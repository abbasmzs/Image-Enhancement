#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>
#include "contrast.h"
#include "image_enhancement.h"

using std::chrono::high_resolution_clock;

void MyTimeOutput(const std::string& str, const high_resolution_clock::time_point& start_time, const high_resolution_clock::time_point& end_time)
{
    std::cout << str << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0 << "ms" << std::endl;
    return;
}

int main(int argc, char** argv)
{
    cv::Mat src = cv::imread("E:/proje/contrast/contrast/Data/Hand/1111119239_2.tiff", IMREAD_GRAYSCALE);

    if (src.empty()) {
        std::cout << "Can't read image file." << std::endl;
        return -1;
    }

    high_resolution_clock::time_point start_time, end_time;


    imwrite("src.tiff", src);
    
    ///basic contrast function
    contrast instContrast;
    std::vector<cv::Mat> imgResult = instContrast.ImageResult(src);
    cv::Mat high_contrast_src_convert = imgResult[0];
    imwrite("high_contrast_src_convert.tiff", high_contrast_src_convert);
    cv::Mat low_contrast_src_convert = imgResult[1];
    imwrite("low_contrast_src_convert.tiff", low_contrast_src_convert);
    cv::Mat high_brightness_src_convert = imgResult[2];
    imwrite("high_brightness_src_convert.tiff", high_brightness_src_convert);
    cv::Mat low_brightness_src_convert = imgResult[3];
    imwrite("low_brightness_src_convert.tiff", low_brightness_src_convert);

    start_time = high_resolution_clock::now();
    cv::Mat src_auto_histo;
    HistoConst(src, src_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("src_auto_histo: ", start_time, end_time);
    imwrite("src_auto_histo.tiff", src_auto_histo);



    ///LDR
    start_time = high_resolution_clock::now();
    cv::Mat LDR_dst;
    LDR(src, LDR_dst);
    //cv::resize(LDR_dst, LDR_dst, cv::Size(), 0.3, 0.3);
    imgResult = instContrast.ImageResult(LDR_dst);
    cv::Mat high_cont_LDR_convert = imgResult[0];
    imwrite("high_cont_LDR_convert.tiff", high_cont_LDR_convert);
    cv::Mat low_cont_LDR_convert = imgResult[1];
    imwrite("low_cont_LDR_convert.tiff", low_cont_LDR_convert);
    cv::Mat high_bright_LDR_convert = imgResult[2];
    imwrite("high_bright_LDR_convert.tiff", high_bright_LDR_convert);
    cv::Mat low_bright_LDR_convert = imgResult[3];
    imwrite("low_bright_LDR_convert.tiff", low_bright_LDR_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("LDR: ", start_time, end_time);
    imwrite("LDR_dst.tiff", LDR_dst);

    start_time = high_resolution_clock::now();
    cv::Mat LDR_auto_histo;
    HistoConst(LDR_dst, LDR_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("LDR_auto_Histo: ", start_time, end_time);
    imwrite("LDR_auto_Histo.tiff", LDR_auto_histo);



    ///WTHE
    start_time = high_resolution_clock::now();
    cv::Mat WTHE_dst;
    WTHE(src, WTHE_dst);
    //cv::resize(WTHE_dst, WTHE_dst, cv::Size(), 0.3, 0.3);
    imgResult = instContrast.ImageResult(WTHE_dst);
    cv::Mat high_cont_WTHE_convert = imgResult[0];
    imwrite("high_cont_WTHE_convert.tiff", high_cont_WTHE_convert);
    cv::Mat low_cont_WTHE_convert = imgResult[1];
    imwrite("low_cont_WTHE_convert.tiff", low_cont_WTHE_convert);
    cv::Mat high_bright_WTHE_convert = imgResult[2];
    imwrite("high_bright_WTHE_convert.tiff", high_bright_WTHE_convert);
    cv::Mat low_bright_WTHE_convert = imgResult[3];
    imwrite("low_bright_WTHE_convert.tiff", low_bright_WTHE_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("WTHE: ", start_time, end_time);
    imwrite("WTHE_dst.tiff", WTHE_dst);

    start_time = high_resolution_clock::now();
    cv::Mat WTHE_auto_histo;
    HistoConst(WTHE_dst, WTHE_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("WTHE_auto_histo: ", start_time, end_time);
    imwrite("WTHE_auto_histo.tiff", WTHE_auto_histo);



    ///JHE
    start_time = high_resolution_clock::now();
    cv::Mat JHE_dst;
    JHE(src, JHE_dst);
    //cv::resize(WTHE_dst, WTHE_dst, cv::Size(), 0.3, 0.3);
    imgResult = instContrast.ImageResult(JHE_dst);
    cv::Mat high_cont_JHE_convert = imgResult[0];
    imwrite("high_cont_JHE_convert.tiff", high_cont_JHE_convert);
    cv::Mat low_cont_JHE_convert = imgResult[1];
    imwrite("low_cont_JHE_convert.tiff", low_cont_JHE_convert);
    cv::Mat high_bright_JHE_convert = imgResult[2];
    imwrite("high_bright_JHE_convert.tiff", high_bright_JHE_convert);
    cv::Mat low_bright_JHE_convert = imgResult[3];
    imwrite("low_bright_JHE_convert.tiff", low_bright_JHE_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("JHE2: ", start_time, end_time);
    imwrite("JHE_dst.tiff", JHE_dst);

    start_time = high_resolution_clock::now();
    cv::Mat JHE_auto_histo;
    HistoConst(JHE_dst, JHE_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("JHE_auto_histo: ", start_time, end_time);
    imwrite("JHE_auto_histo.tiff", JHE_auto_histo);



    ///SEF
    start_time = high_resolution_clock::now();
    cv::Mat SEF_dst;
    SEF(src, SEF_dst);
    imgResult = instContrast.ImageResult(SEF_dst);
    cv::Mat high_cont_SEF_convert = imgResult[0];
    imwrite("high_cont_SEF_convert.tiff", high_cont_SEF_convert);
    cv::Mat low_cont_SEF_convert = imgResult[1];
    imwrite("low_cont_SEF_convert.tiff", low_cont_SEF_convert);
    cv::Mat high_bright_SEF_convert = imgResult[2];
    imwrite("high_bright_SEF_convert.tiff", high_bright_SEF_convert);
    cv::Mat low_bright_SEF_convert = imgResult[3];
    imwrite("low_bright_SEF_convert.tiff", low_bright_SEF_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("SEF: ", start_time, end_time);
    imwrite("JHE_dst.tiff", SEF_dst);

    start_time = high_resolution_clock::now();
    cv::Mat SEF_auto_histo;
    HistoConst(SEF_dst, SEF_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("SEF_auto_histo: ", start_time, end_time);
    imwrite("SEF_auto_histo.tiff", SEF_auto_histo);



    ///IAGCWD2
    start_time = high_resolution_clock::now();
    cv::Mat IAGCWD2_dst;
    IAGCWD2(src, IAGCWD2_dst);
    imgResult = instContrast.ImageResult(IAGCWD2_dst);
    cv::Mat high_cont_IAGCWD2_convert = imgResult[0];
    imwrite("high_cont_IAGCWD2_convert.tiff", high_cont_IAGCWD2_convert);
    cv::Mat low_cont_IAGCWD2_convert = imgResult[1];
    imwrite("low_cont_IAGCWD2_convert.tiff", low_cont_IAGCWD2_convert);
    cv::Mat high_bright_IAGCWD2_convert = imgResult[2];
    imwrite("high_bright_IAGCWD2_convert.tiff", high_bright_IAGCWD2_convert);
    cv::Mat low_bright_IAGCWD2_convert = imgResult[3];
    imwrite("low_bright_IAGCWD2_convert.tiff", low_bright_IAGCWD2_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("IAGCWD2: ", start_time, end_time);
    imwrite("IAGCWD2_dst.tiff", IAGCWD2_dst);

    start_time = high_resolution_clock::now();
    cv::Mat IAGCWD2_auto_histo;
    HistoConst(IAGCWD2_dst, IAGCWD2_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("IAGCWD2_auto_histo: ", start_time, end_time);
    imwrite("IAGCWD2_auto_histo.tiff", IAGCWD2_auto_histo);



    ///AGCIE
    start_time = high_resolution_clock::now();
    cv::Mat AGCIE_dst;
    AGCIE(src, AGCIE_dst);
    imgResult = instContrast.ImageResult(AGCIE_dst);
    cv::Mat high_cont_AGCIE_convert = imgResult[0];
    imwrite("high_cont_AGCIE_convert.tiff", high_cont_AGCIE_convert);
    cv::Mat low_cont_AGCIE_convert = imgResult[1];
    imwrite("low_cont_AGCIE_convert.tiff", low_cont_AGCIE_convert);
    cv::Mat high_bright_AGCIE_convert = imgResult[2];
    imwrite("high_bright_AGCIE_convert.tiff", high_bright_AGCIE_convert);
    cv::Mat low_bright_AGCIE_convert = imgResult[3];
    imwrite("low_bright_AGCIE_convert.tiff", low_bright_AGCIE_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AGCIE: ", start_time, end_time);
    imwrite("AGCIE_dst.tiff", AGCIE_dst);

    start_time = high_resolution_clock::now();
    cv::Mat AGCIE_auto_histo;
    HistoConst(AGCIE_dst, AGCIE_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AGCIE_auto_histo: ", start_time, end_time);
    imwrite("AGCIE_auto_histo.tiff", AGCIE_auto_histo);



    ///AGCWD
    start_time = high_resolution_clock::now();
    cv::Mat AGCWD_dst;
    AGCWD(src, AGCWD_dst);
    imgResult = instContrast.ImageResult(AGCWD_dst);
    cv::Mat high_cont_AGCWD_convert = imgResult[0];
    imwrite("high_cont_AGCWD_convert.tiff", high_cont_AGCWD_convert);
    cv::Mat low_cont_AGCWD_convert = imgResult[1];
    imwrite("low_cont_AGCWD_convert.tiff", low_cont_AGCWD_convert);
    cv::Mat high_bright_AGCWD_convert = imgResult[2];
    imwrite("high_bright_AGCWD_convert.tiff", high_bright_AGCWD_convert);
    cv::Mat low_bright_AGCWD_convert = imgResult[3];
    imwrite("low_bright_AGCWD_convert.tiff", low_bright_AGCWD_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AGCWD: ", start_time, end_time);
    imwrite("AGCWD_dst.tiff", AGCWD_dst);

    start_time = high_resolution_clock::now();
    cv::Mat AGCWD_auto_histo;
    HistoConst(AGCWD_dst, AGCWD_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AGCWD_auto_histo: ", start_time, end_time);
    imwrite("AGCWD_auto_histo.tiff", AGCWD_auto_histo);




    ///GCEHistMod
    start_time = high_resolution_clock::now();
    cv::Mat GCEHistMod_dst;
    GCEHistMod(src, GCEHistMod_dst);
    imgResult = instContrast.ImageResult(GCEHistMod_dst);
    cv::Mat high_cont_GCEHistMod_convert = imgResult[0];
    imwrite("high_cont_GCEHistMod_convert.tiff", high_cont_GCEHistMod_convert);
    cv::Mat low_cont_GCEHistMod_convert = imgResult[1];
    imwrite("low_cont_GCEHistMod_convert.tiff", low_cont_GCEHistMod_convert);
    cv::Mat high_bright_GCEHistMod_convert = imgResult[2];
    imwrite("high_bright_GCEHistMod_convert.tiff", high_bright_GCEHistMod_convert);
    cv::Mat low_bright_GCEHistMod_convert = imgResult[3];
    imwrite("low_bright_GCEHistMod_convert.tiff", low_bright_GCEHistMod_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("GCEHistMod: ", start_time, end_time);
    imwrite("GCEHistMod_dst.tiff", GCEHistMod_dst);

    start_time = high_resolution_clock::now();
    cv::Mat GCEHistMod_auto_histo;
    HistoConst(GCEHistMod_dst, GCEHistMod_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("GCEHistMod_auto_histo: ", start_time, end_time);
    imwrite("GCEHistMod_auto_histo.tiff", GCEHistMod_auto_histo);




    ///adaptiveImageEnhancement
    //start_time = high_resolution_clock::now();
    //cv::Mat adaptiveImageEnhancement_dst;
    //adaptiveImageEnhancement(src, adaptiveImageEnhancement_dst);
    //contrast instContrast;
    //imgResult = instContrast.ImageResult(adaptiveImageEnhancement_dst);
    //cv::Mat high_cont_adaptiveImageEnhancement_convert = imgResult[0];
    //imwrite("high_cont_adaptiveImageEnhancement_convert.tiff", high_cont_adaptiveImageEnhancement_convert);
    //cv::Mat low_cont_adaptiveImageEnhancement_convert = imgResult[1];
    //imwrite("low_cont_adaptiveImageEnhancement_convert.tiff", low_cont_adaptiveImageEnhancement_convert);
    //cv::Mat high_bright_adaptiveImageEnhancement_convert = imgResult[2];
    //imwrite("high_bright_adaptiveImageEnhancement_convert.tiff", high_bright_adaptiveImageEnhancement_convert);
    //cv::Mat low_bright_adaptiveImageEnhancement_convert = imgResult[3];
    //imwrite("low_bright_adaptiveImageEnhancement_convert.tiff", low_bright_adaptiveImageEnhancement_convert);
    //end_time = high_resolution_clock::now();
    //MyTimeOutput("adaptiveImageEnhancement: ", start_time, end_time);
    //imwrite("adaptiveImageEnhancement_dst.tiff", adaptiveImageEnhancement_dst);

    //start_time = high_resolution_clock::now();
    //cv::Mat adaptiveImageEnhancement_auto_histo;
    //HistoConst(adaptiveImageEnhancement_dst, adaptiveImageEnhancement_auto_histo);
    //end_time = high_resolution_clock::now();
    //MyTimeOutput("adaptiveImageEnhancement_auto_histo: ", start_time, end_time);
    //imwrite("adaptiveImageEnhancement_auto_histo.tiff", adaptiveImageEnhancement_auto_histo);
    


    ////////new reading
    //src = cv::imread("E:/proje/contrast/contrast/Data/Foot/1111119244_3.tiff", 1);
    cvtColor(src, src, CV_GRAY2BGR);



    ///AINDANE
    start_time = high_resolution_clock::now();
    cv::Mat AINDANE_dst;
    AINDANE(src, AINDANE_dst);
    imgResult = instContrast.ImageResult(AINDANE_dst);
    cv::Mat high_cont_AINDANE_convert = imgResult[0];
    imwrite("high_cont_AINDANE_convert.tiff", high_cont_AINDANE_convert);
    cv::Mat low_cont_AINDANE_convert = imgResult[1];
    imwrite("low_cont_AINDANE_convert.tiff", low_cont_AINDANE_convert);
    cv::Mat high_bright_AINDANE_convert = imgResult[2];
    imwrite("high_bright_AINDANE_convert.tiff", high_bright_AINDANE_convert);
    cv::Mat low_bright_AINDANE_convert = imgResult[3];
    imwrite("low_bright_AINDANE_convert.tiff", low_bright_AINDANE_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AINDANE: ", start_time, end_time);
    imwrite("AINDANE_dst.tiff", AINDANE_dst);

    //start_time = high_resolution_clock::now();
    //cv::Mat AINDANE_auto_histo;
    //HistoConst(AINDANE_dst, AINDANE_auto_histo);
    //end_time = high_resolution_clock::now();
    //MyTimeOutput("AINDANE_auto_histo: ", start_time, end_time);
    //imwrite("AINDANE_auto_histo.tiff", AINDANE_auto_histo);




    ///CEusingLuminanceAdaptation
    start_time = high_resolution_clock::now();
    cv::Mat CEusingLuminanceAdaptation_dst;
    CEusingLuminanceAdaptation(src, CEusingLuminanceAdaptation_dst);
    imgResult = instContrast.ImageResult(CEusingLuminanceAdaptation_dst);
    cv::Mat high_cont_CEusingLuminanceAdaptation_convert = imgResult[0];
    imwrite("high_cont_CEusingLuminanceAdaptation_convert.tiff", high_cont_CEusingLuminanceAdaptation_convert);
    cv::Mat low_cont_CEusingLuminanceAdaptation_convert = imgResult[1];
    imwrite("low_cont_CEusingLuminanceAdaptation_convert.tiff", low_cont_CEusingLuminanceAdaptation_convert);
    cv::Mat high_bright_CEusingLuminanceAdaptation_convert = imgResult[2];
    imwrite("high_bright_CEusingLuminanceAdaptation_convert.tiff", high_bright_CEusingLuminanceAdaptation_convert);
    cv::Mat low_bright_CEusingLuminanceAdaptation_convert = imgResult[3];
    imwrite("low_bright_CEusingLuminanceAdaptation_convert.tiff", low_bright_CEusingLuminanceAdaptation_convert);
    end_time = high_resolution_clock::now();
    MyTimeOutput("CEusingLuminanceAdaptation: ", start_time, end_time);
    imwrite("CEusingLuminanceAdaptation_dst.tiff", CEusingLuminanceAdaptation_dst);

    //start_time = high_resolution_clock::now();
    //cv::Mat CEusingLuminanceAdaptation_auto_histo;
    //HistoConst(CEusingLuminanceAdaptation_dst, CEusingLuminanceAdaptation_auto_histo);
    //end_time = high_resolution_clock::now();
    //MyTimeOutput("CEusingLuminanceAdaptation_auto_histo: ", start_time, end_time);
    //imwrite("CEusingLuminanceAdaptation_auto_histo.tiff", CEusingLuminanceAdaptation_auto_histo);




    //////converting 1 to gray scale for two algorithms
    cv::cvtColor(AINDANE_dst, AINDANE_dst, CV_BGR2GRAY);
    cv::cvtColor(CEusingLuminanceAdaptation_dst, CEusingLuminanceAdaptation_dst, CV_BGR2GRAY);


    start_time = high_resolution_clock::now();
    cv::Mat AINDANE_auto_histo;
    HistoConst(AINDANE_dst, AINDANE_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AINDANE_auto_histo: ", start_time, end_time);
    imwrite("AINDANE_auto_histo.tiff", AINDANE_auto_histo);


    start_time = high_resolution_clock::now();
    cv::Mat CEusingLuminanceAdaptation_auto_histo;
    HistoConst(CEusingLuminanceAdaptation_dst, CEusingLuminanceAdaptation_auto_histo);
    end_time = high_resolution_clock::now();
    MyTimeOutput("CEusingLuminanceAdaptation_auto_histo: ", start_time, end_time);
    imwrite("CEusingLuminanceAdaptation_auto_histo.tiff", CEusingLuminanceAdaptation_auto_histo);




    ///contrast and brightness
    //Mat img_higher_contrast1;
    //LDR_dst.convertTo(img_higher_contrast1, -1, 2, 0); //increase the contrast (double)
    //Mat img_higher_contrast3;
    //LDR_dst.convertTo(img_higher_contrast3, -1, 2, 2); //increase the contrast (double)
    //Mat img_lower_brightness1;
    //img_higher_contrast1.convertTo(img_lower_brightness1, -1, 1, -20); //decrease the brightness by 20 for each pixel
    //Mat img_lower_brightness2;
    //img_higher_contrast3.convertTo(img_lower_brightness2, -1, 1, -20); //decrease the brightness by 20 for each pixel



    cv::waitKey();
    return 0;
}