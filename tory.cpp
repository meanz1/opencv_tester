#include "opencv2/opencv.hpp"
#include <iostream>
#include "point_tory.hpp"
void on_mouse(int event, int x, int y, int flags, void* param);
click c;

int main_a()
{
	cv::Mat src_img = cv::imread("tory.jpg", cv::IMREAD_COLOR);
	cv::Mat destination = cv::imread("apple.jpg", cv::IMREAD_COLOR);
	cv::resize(destination, destination, cv::Size(src_img.cols, src_img.rows));
	
	if (src_img.empty())
	{
		std::cout << "Image load failed";
		return -1;	
	}
	
	cv::namedWindow("destination");
	

	c.count = 0;
	cv::setMouseCallback("destination", on_mouse, &destination);
	
	cv::imshow("destination", destination);
	cv::waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*param)
{

	cv::Mat img;
	img = *(cv::Mat*)param;
	
	
	cv::Point point;
	point = cv::Point(x, y);
	if (event == cv::EVENT_LBUTTONDOWN)
		std::cout << "LBUTTUON DOWN : " << point.x << " " << point.y << std::endl;
	if (event == cv::EVENT_LBUTTONUP)
	{
		std::cout << "LBUTTON UP : " << point.x << " " << point.y << std::endl;
		c.count++;
		std::cout << c.count << std::endl;
		c.line(&img, point);
	}
	
}