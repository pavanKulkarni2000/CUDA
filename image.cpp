#include <opencv2/opencv.hpp> 
#include<iostream>
#include<stdio.h>

int main(int argc, char** argv) 
{ 
  // Read the image file 
  cv::Mat image = cv::imread("samples/7a.png",cv::IMREAD_GRAYSCALE);

  cv::Mat newImg;
  resize(image, newImg, cv::Size(28, 28), cv::INTER_LINEAR);

  // for(int i=0;i<newImg.rows;i++){
  //   for(int j=0;j<newImg.cols;j++){
  //     printf("%3d ",newImg.at<uchar>(i,j));
  //   }
  //   std::cout<<"\n";
  // }

  double m[28][28];
  newImg.forEach<uchar>([&m](uchar &c, const int * position) -> void {
    m[position[0]][position[1]]=(float)c/255.0;
  });

  for(int i=0;i<28;i++){
    for(int j=0;j<28;j++){
      printf("%1.0f ",m[i][j]);
    }
    std::cout<<"\n";
  }
  return 0; 
}