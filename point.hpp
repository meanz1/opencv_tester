#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/core.hpp"
class click {
	
		
	public:

		int count;
		
		cv::Point p1;
		cv::Point p2;
		cv::Point p3;
		cv::Point p4;
		//void line();
		cv::Mat apple_clone;

		void line(void*param, cv::Point p)
		{
			//cv::Mat img;
			//img = *(cv::Mat*)param;
			cv::Mat img = cv::imread("tory.jpg", cv::IMREAD_COLOR);
			std::vector<cv::Point> trans;
			cv::Point2f src[4], dst[4];
			
			
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
				/*cv::line(img, p1, p2, cv::Scalar(0, 255, 0), 3);
				cv::line(img, p2, p3, cv::Scalar(0, 255, 0), 3);
				cv::line(img, p3, p4, cv::Scalar(0, 255, 0), 3);
				cv::line(img, p4, p1, cv::Scalar(0, 255, 0), 3);*/
				/*trans.push_back(p1);
				trans.push_back(p2);
				trans.push_back(p3);
				trans.push_back(p4);*/

				src[0] = cv::Point2f(p1.x, p1.y);
				src[1] = cv::Point2f(p2.x, p2.y);
				src[2] = cv::Point2f(p3.x, p3.y);
				src[3] = cv::Point2f(p4.x, p4.y);
				
				/*int max_w = (p4.x - p1.x > p3.x - p2.x) ? p4.x - p1.x : p3.x - p2.x;
				int max_h = (p2.y - p1.y > p3.y - p4.y) ? p2.y - p1.y : p3.y - p4.y;

				dst[0] = cv::Point2i(0, 0);
				dst[1] = cv::Point2i(0, max_h-1);
				dst[2] = cv::Point2i(max_w-1, max_h-1);
				dst[3] = cv::Point2i(max_w-1, 0);*/

				cv::Point2f temp_src[4], temp_dst[4];
				cv::Point2f poly[1][4];

				poly[0][0] = src[0];
				poly[0][1] = src[1];
				poly[0][2] = src[2];
				poly[0][3] = src[3];

				temp_src[0] = cv::Point2f(0, 0);
				temp_src[1] = cv::Point2f(0, img.rows);
				temp_src[2] = cv::Point2f(img.cols, img.rows);
				temp_src[3] = cv::Point2f(img.cols, 0);

				cv::Mat mask_orig(img.size(), CV_8UC1, cv::Scalar(0, 0, 255));
				cv::Mat mask_result(img.size(), CV_8UC1);

				cv::Mat result = cv::getPerspectiveTransform(temp_src, src);
				cv::warpPerspective(img, destination, result, cv::Size(img.cols, img.rows));
				/*cv::warpPerspective(mask_orig, mask_result, result, cv::Size(img.cols, img.rows));


				for(int i=0; i< destination.cols; i++)
					for (int j = 0; j < destination.rows; j++)
					{
						if (destination.at<cv::Vec3b>(j, i)[0] == 0);
					}*/
				const cv::Point2f* ppt[1] = { poly[0] };
				int npt[] = { 4 };
				cv::Mat a;
				a = destination.clone();
				
				cv::fillPoly(destination, poly[], cv::Scalar(255, 255, 0));
				cv::imshow("out", destination);

			}
			
			//cv::imshow("img", img);
			
			//cv::imshow("out", destination);
		}

		//void transform();
};