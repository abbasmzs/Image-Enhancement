//////// Abbas-Mazrouei-Sebdani [abbas.mzs]
#include <iostream>
#include <opencv2/opencv.hpp>

#include "image_enhancement.h"

void AGCWD(const cv::Mat & src, cv::Mat & dst, double alpha)
{
	int rows = src.rows;
	int cols = src.cols;
	int channels = src.channels();
	int total_pixels = rows * cols;

	cv::Mat L;
	cv::Mat HSV;
	std::vector<cv::Mat> HSV_channels;
	if (channels == 1) {
		L = src.clone();
	}
	else {
		cv::cvtColor(src, HSV, CV_BGR2HSV_FULL);
		cv::split(HSV, HSV_channels);
		L = HSV_channels[2];
	}

	int histsize = 256;
	float range[] = { 0,256 };
	const float* histRanges = { range };
	int bins = 256;
	cv::Mat hist;
	calcHist(&L, 1, 0, cv::Mat(), hist, 1, &histsize, &histRanges, true, false);

	double total_pixels_inv = 1.0 / total_pixels;
	cv::Mat PDF = cv::Mat::zeros(256, 1, CV_64F);
	for (int i = 0; i < 256; i++) {
		PDF.at<double>(i) = hist.at<float>(i) * total_pixels_inv;
	}

	double pdf_min, pdf_max;
	cv::minMaxLoc(PDF, &pdf_min, &pdf_max);
	cv::Mat PDF_w = PDF.clone();
	for (int i = 0; i < 256; i++) {
		PDF_w.at<double>(i) = pdf_max * std::pow((PDF_w.at<double>(i) - pdf_min) / (pdf_max - pdf_min), alpha);
	}

	cv::Mat CDF_w = PDF_w.clone();
	double culsum = 0;
	for (int i = 0; i < 256; i++) {
		culsum += PDF_w.at<double>(i);
		CDF_w.at<double>(i) = culsum;
	}
	CDF_w /= culsum;

	std::vector<uchar> table(256, 0);
	for (int i = 1; i < 256; i++) {
		table[i] = cv::saturate_cast<uchar>(255.0 * std::pow(i / 255.0, 1 - CDF_w.at<double>(i)));
	}

	cv::LUT(L, table, L);

	if (channels == 1) {
		dst = L.clone();
	}
	else {
		cv::merge(HSV_channels, dst);
		cv::cvtColor(dst, dst, CV_HSV2BGR_FULL);
	}

	return;
}