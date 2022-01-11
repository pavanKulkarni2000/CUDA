#include<opencv2/opencv.hpp>
#include<stdio.h>

int main(){
    cv::Mat image = cv::imread("samples/1a.jpg",cv::IMREAD_GRAYSCALE);
    // Error Handling
    if (image.empty()) {
      fprintf(stdout, "Image not found!\n");
      return 1;
    } 
    cv::Mat resized_down;
    cv::resize(image, resized_down, cv::Size(200, 200), cv::INTER_LINEAR);
    cv::imshow("Image to classify", resized_down);
    cv::waitKey(0);
    printf("Hello");
}