#pragma once
#include "opencv2/opencv.hpp"
class click {
	
		
	public:

		int count;
		
		cv::Point p1;
		cv::Point p2;
		cv::Point p3;
		cv::Point p4;
		//void line();

		void line(void*param, cv::Point p)
		{
			cv::Mat img;
			img = *(cv::Mat*)param;
			std::vector<cv::Point> trans;
			cv::Point2f src[4], dst[4];
			cv::Mat apple = cv::imread("apple.jpg", cv::IMREAD_COLOR);
			cv::resize(apple, apple, cv::Size(img.cols, img.rows));
			cv::Mat destination(1000, 1000, CV_8UC3);

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
				
				//cv::imshow("img", img);
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
				cv::line(img, p1, p2, cv::Scalar(0, 255, 0), 3);
				cv::line(img, p2, p3, cv::Scalar(0, 255, 0), 3);
				cv::line(img, p3, p4, cv::Scalar(0, 255, 0), 3);
				cv::line(img, p4, p1, cv::Scalar(0, 255, 0), 3);
				/*trans.push_back(p1);
				trans.push_back(p2);
				trans.push_back(p3);
				trans.push_back(p4);*/

				src[0] = cv::Point2i(p1.x, p1.y);
				src[1] = cv::Point2i(p2.x, p2.y);
				src[2] = cv::Point2i(p3.x, p3.y);
				src[3] = cv::Point2i(p4.x, p4.y);
				
				int max_w = (p4.x - p1.x > p3.x - p2.x) ? p4.x - p1.x : p3.x - p2.x;
				int max_h = (p2.y - p1.y > p3.y - p4.y) ? p2.y - p1.y : p3.y - p4.y;

				dst[0] = cv::Point2i(0, 0);
				dst[1] = cv::Point2i(0, max_h-1);
				dst[2] = cv::Point2i(max_w-1, max_h-1);
				dst[3] = cv::Point2i(max_w-1, 0);

				cv::Point2f temp_src[4], temp_dst[4];
				temp_src[0] = cv::Point2f(0, 0);
				temp_src[1] = cv::Point2f(0, img.rows);
				temp_src[2] = cv::Point2f(img.cols, img.rows);
				temp_src[3] = cv::Point2f(img.cols, 0);

				cv::Mat result = cv::getPerspectiveTransform(temp_src, src);
				cv::warpPerspective(img, destination, result, cv::Size(img.cols, img.rows));

			}
			
			cv::imshow("img", img);
			cv::imshow("apple", apple);
			cv::imshow("out", destination);
		}

		//void transform();
};