#include "opencv2/opencv.hpp"
#include <iostream>
#include "point.hpp"
void on_mouse(int event, int x, int y, int flags, void* param);
click c;

int main()
{
	cv::Mat img = cv::imread("tory.jpg", cv::IMREAD_COLOR);
	//cv::Mat out = img.clone();
	if (img.empty())
	{
		std::cout << "Image load failed";
		return -1;	
	}
	cv::namedWindow("img");
	//cv::namedWindow("out");

	c.count = 0;
	cv::setMouseCallback("img", on_mouse, &img);
	cv::imshow("img", img);
	//cv::imshow("out", out);
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