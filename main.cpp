#include "opencv2/opencv.hpp"
#include <iostream>
#include "point.hpp"
void on_mouse(int event, int x, int y, int flags, void* param);
int click::count = 0;

int main()
{
	cv::Mat img = cv::imread("tory.jpg", cv::IMREAD_COLOR);

	if (img.empty())
	{
		std::cout << "Image load failed";
		return -1;	
	}
	cv::namedWindow("img");
	cv::setMouseCallback("img", on_mouse, &img);
	cv::imshow("img", img);
	cv::waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*param)
{
	cv::Mat img;
	img = *(cv::Mat*)param;
	click c;
	
	cv::Point point;
	point = cv::Point(x, y);
	if (event == cv::EVENT_LBUTTONDOWN)
		std::cout << "LBUTTUON DOWN : " << point.x << " " << point.y << std::endl;
	if (event == cv::EVENT_LBUTTONUP)
	{
		std::cout << "LBUTTON UP : " << point.x << " " << point.y << std::endl;
		c.count++;
		std::cout << c.count << std::endl;
		//c.line(&img, point);
	}
	//if (c.count % 4 == 1)
	//{
	//	c.p1.x = point.x;
	//	c.p1.y = point.y;
	//	std::cout << c.p1.x << " p1 " << c.p1.y << std::endl;
	//}
	//if (c.count % 4 == 2)
	//{
	//	c.p2.x = point.x;
	//	c.p2.y = point.y;
	//	std::cout << c.p1.x << " p1 " << c.p1.y << std::endl;
	//	std::cout << c.p2.x << " p2 " << c.p2.y << std::endl;
	//	cv::line(img, c.p1, c.p2, cv::Scalar(0, 255, 0), 3);
	//	//cv::imshow("img", img);
	//}
	//if (c.count % 4 == 3)
	//{
	//	c.p3.x = point.x;
	//	c.p3.y = point.y;
	//	std::cout << c.p3.x << " p3 " << c.p3.y << std::endl;
	//}
	//
	//if (c.count % 4 == 0)
	//{
	//	c.p4.x = point.x;
	//	c.p4.y = point.y;
	//	std::cout << c.p4.x << " p4 " << c.p4.y << std::endl;
	//}
	//cv::imshow("img", img);
}