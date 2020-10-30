#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
VideoCapture cam(0);

int main(int argc, char **argv)
{
    // ios_base::sync_with_stdio(true);
    // Mat img = imread("test.jpg");//worked!
    // https://thefreecoder.wordpress.com/2012/09/11/opencv-c-video-capture/
    Mat pic;
    Mat gray;
    cam.read(pic);
    Size s = pic.size();
    int rows = s.height;
    int cols = s.width;
    while (1)
    {
        cam.read(pic);
        cvtColor(pic, gray, cv::COLOR_RGB2GRAY);
        for(int x=0;x<rows;x++)
        {
            for(int y=0;y<cols;y++)
            {
                // Vec &color = gray.at<Vec>(x, y);
                // color[0]+=100;
                // gray.at<Vec3b>(x, y)=color;
                int value = gray.at<uchar>(x,y);
            }
        }
        imshow("Image", gray);
        // cout << color << endl;
        // printf("1");
        if (waitKey(30) == 'q')
            break;
        // https://thefreecoder.wordpress.com/2012/09/11/opencv-c-video-capture/
    }
}