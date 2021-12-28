#ifndef IMAGE_READ
#define IMAGE_READ

#include <opencv2/opencv.hpp> 
void image_matrix(char *image_file,double data[][28][28]){
  cv::Mat image = cv::imread(image_file,cv::IMREAD_GRAYSCALE);

  cv::Mat newImg;
  resize(image, newImg, cv::Size(28, 28), cv::INTER_LINEAR);
  image.release();

  newImg.forEach<uchar>([&data](uchar &c, const int * position) -> void {
    (*data)[position[0]][position[1]]=(double)c/255.0;
  });
  newImg.release();

}

#endif