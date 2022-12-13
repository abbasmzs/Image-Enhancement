#include "image_enhancement.h"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void HistoConst(const cv::Mat& img, cv::Mat& out)
{

	//cvtColor(img, img, CV_BGR2GRAY);
	// Establish the number of bins
	int histSize = 256;

	// Set the range
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat hist;

	// Compute the histogram
	calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

	// Draw the histogram
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	// Normalize the result to [ 0, histImage.rows ]
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}


	// Perform Global Histogram Equalization 

	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
	clahe->setClipLimit(2.0);
	clahe->apply(img, out);
	//equalizeHist(img, out);

	// Compute the histogram
	calcHist(&out, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

	Mat outHistImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	// Normalize the result to [ 0, histImage.rows ]
	normalize(hist, hist, 0, outHistImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++)
	{
		line(outHistImage, Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	return;
}