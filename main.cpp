#include "opencv2/opencv.hpp"
#include <iostream>
#include "point.hpp"
void on_mouse(int event, int x, int y, int flags, void* param);
click c;

int main()
{
	cv::Mat img = cv::imread("tory.jpg", cv::IMREAD_COLOR);
	cv::Mat apple = cv::imread("apple.jpg", cv::IMREAD_COLOR);
	cv::resize(apple, apple, cv::Size(img.cols, img.rows));
	c.apple_clone = apple.clone();
	//cv::Mat out = img.clone();
	if (img.empty())
	{
		std::cout << "Image load failed";
		return -1;	
	}
	
	cv::namedWindow("apple");
	

	c.count = 0;
	cv::setMouseCallback("apple", on_mouse, &apple);
	
	cv::imshow("apple", apple);
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