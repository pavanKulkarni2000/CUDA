#ifndef IMAGE_READ
#define IMAGE_READ

#include <opencv2/opencv.hpp> 
#include<iostream>
void image_matrix(char *image_file,double data[][28][28]){
  cv::Mat image = cv::imread(image_file,cv::IMREAD_GRAYSCALE);

  cv::Mat newImg;
  resize(image, newImg, cv::Size(28, 28), cv::INTER_LINEAR);
  image.release();

  newImg.forEach<uchar>([&data](uchar &c, const int * position) -> void {
    (*data)[position[0]][position[1]]=(double)(c)/255.0;
  });
  newImg.release();

}

void write_image(char *image_file,double data[28][28]){
  cv::Mat image=cv::Mat(28,28,0);
  image.forEach<uchar>([data](uchar &c, const int * position) -> void {
    c=data[position[0]][position[1]];
  });
  std::cout<<"rows="<<image.rows<<" cols="<<image.cols<<"\n";
    for(int i=0;i<image.rows;i++){
    for(int j=0;j<image.cols;j++){
      printf("%3d ",image.at<uchar>(i,j));
    }
    std::cout<<"\n";
  }

  cv::imwrite(image_file, image);
}

#endif