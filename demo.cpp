#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
VideoCapture cam(0);

int main(int argc, char **argv)
{
    // Mat img = imread("test.jpg");//worked!
    // https://thefreecoder.wordpress.com/2012/09/11/opencv-c-video-capture/
    Mat pic;
    Mat gray;
    while (1)
    {
        cam.read(pic);
        cvtColor(pic, gray, cv::COLOR_RGB2GRAY);
        imshow("Image", gray);
        if (waitKey(30) >= 0) //wei sm bu yao bu xing zhi you wait key bu xing
            break;

        // https://thefreecoder.wordpress.com/2012/09/11/opencv-c-video-capture/
    }
}