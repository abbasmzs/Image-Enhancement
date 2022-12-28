#include <opencv2/opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

void imageSmooothing(const cv::Mat& image) {
    cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Output image", cv::WINDOW_AUTOSIZE);

    //cv::resize(image, image, cv::Size(), 0.3, 0.3);
    cv::imshow("Input image", image);

    cv::Mat out;

    cv::blur(image, out, cv::Size(5, 5));
    cv::blur(out, out, cv::Size(5, 5));

    cv::resize(out, out, cv::Size(), 0.3, 0.3);
    cv::imshow("Output image", out);
    
    cv::waitKey(0);
}

int main(int args, char** argv) {

    cv::Mat img = cv::imread("E:/WORK/Radiology/Data/Abdomen/1111118092_6.tiff", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        printf("No image found\n");
        return -1;
    }

    imageSmooothing(img);
}