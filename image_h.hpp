#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <Windows.h>

class origin_mat {
public:
	cv::Mat origin;

	void ori() {
		origin = cv::Mat(1000, 1000, CV_8UC3, cv::Scalar(0, 0, 0));
	}
};

class click {
public:
	int count;
	cv::Point p1;
	cv::Point p2;
	cv::Point p3;
	cv::Point p4;
	cv::Point flow;

	void pointing(void* param, cv::Point p)
	{
		if (count % 4 == 1)
		{
			p1.x = p.x;
			p1.y = p.y;
			std::cout << p1.x << " p1 " << p1.y << std::endl;

		}
		if (count % 4 == 2)
		{
			p2.x = p.x;
			p2.y = p.y;
			std::cout << p1.x << " p1 " << p1.y << std::endl;
			std::cout << p2.x << " p2 " << p2.y << std::endl;

		}
		if (count % 4 == 3)
		{
			p3.x = p.x;
			p3.y = p.y;
			std::cout << p3.x << " p3 " << p3.y << std::endl;
		}

		if (count % 4 == 0)
		{
			p4.x = p.x;
			p4.y = p.y;
			std::cout << p4.x << " p4 " << p4.y << std::endl;
		}
	}


};