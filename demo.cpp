#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>

bool Cam = true;
bool first = true;
using namespace cv;
using namespace std;
VideoCapture cam(0);
int value;
Mat showing;
int main(int argc, char **argv)
{
    // ios_base::sync_with_stdio(true);
    // Mat img = imread("test.jpg");//worked!
    // https://thefreecoder.wordpress.com/2012/09/11/opencv-c-video-capture/
    Mat pic;
    Mat gray;
    if (Cam)
        cam.read(pic);
    else
    {
        pic = imread("test.jpg");
        resize(pic, pic, cv::Size(), 0.15, 0.15);
        // zhi zuo yi ka shi tai da le? na wei sm ni zhi de fang fa bu ka zhe zhong get fang shi
    }
    Size s = pic.size();
    int rows = s.height;
    int cols = s.width;
    while (1)
    {
        if (Cam)
            cam.read(pic);
        cvtColor(pic, gray, cv::COLOR_RGB2GRAY);
        for (int x = 22; x < rows-11; x++)
        {
            for (int y = 22; y < cols-11; y++)
            {
                // Vec &color = gray.at<Vec>(x, y);
                // color[0]+=100;
                // gray.at<Vec3b>(x, y)=color;
                int main_value = gray.at<uchar>(x, y);
                // value += rand() % 100; //tou guo zhe ge fa xian qu yu bu dui
                for (int subx = -5; subx < 5; subx++)
                {
                    for (int suby = -5; suby < 5; suby++)
                    {
                        value = gray.at<uchar>(x+subx, y+suby);
                        value+=main_value;///(sqrt(pow(subx,2)+pow(suby,2)));
                        gray.at<uchar>(x+subx, y+suby)=value/2;
                    }
                }
                gray.at<uchar>(x, y) = value;
            }
        }
        // resize(gray, showing, cv::Size(), 0.15, 0.15);
        imshow("Image", gray);
        // resizeWindow("Image", 50, cols/10); not working
        // cout << color << endl;
        // printf("1");
        if (waitKey(30) == 'q')
            break;
        // https://thefreecoder.wordpress.com/2012/09/11/opencv-c-video-capture/
        // cout<<gray.get(CV_CAP_PROP_FPS)<<endl;
    }
}