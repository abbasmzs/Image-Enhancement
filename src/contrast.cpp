#include "contrast.h"

/// Vector contains:
///1) img_higher_contrast  
///2) img_lower_contrast   
///3) img_higher_brightness
///3) img_lower_brightness 


std::vector<cv::Mat> contrast::ImageResult(Mat img)
{
    {

        std::vector<cv::Mat> result;

        Mat img_higher_contrast;
        img.convertTo(img_higher_contrast, -1, 2, 0); //increase the contrast (double)

        Mat img_lower_contrast;
        img.convertTo(img_lower_contrast, -1, 0.5, 0); //decrease the contrast (halve)

        Mat img_higher_brightness;
        img.convertTo(img_higher_brightness, -1, 1, 20); //increase the brightness by 20 for each pixel 

        Mat img_lower_brightness;
        img.convertTo(img_lower_brightness, -1, 1, -15); //decrease the brightness by 20 for each pixel


        result.push_back(img_higher_contrast   );
        result.push_back(img_lower_contrast    );
        result.push_back(img_higher_brightness  );
        result.push_back(img_lower_brightness  );

        return result;
    }
}


