#include "opencv2/opencv.hpp"
#include <iostream>
#include "point_text.hpp"

void on_mouse_q(int event, int x, int y, int flags, void* param);
click a;

int main()
{
	cv::Mat src_img(1000, 1000, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::Mat destination = cv::imread("apple.jpg", cv::IMREAD_COLOR);
	cv::resize(destination, destination, cv::Size(src_img.cols, src_img.rows));

	cv::namedWindow("destination");

	a.count = 0;
	cv::setMouseCallback("destination", on_mouse_q, &destination);

	cv::imshow("destination", destination);
	cv::waitKey();

	return 0;
}

void on_mouse_q(int event, int x, int y, int flags, void* param)
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
		a.count++;
		std::cout << a.count << std::endl;
		a.line(&img, point);
	}

}