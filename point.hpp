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

		void line(void*param, cv::Point p)
		{

			cv::Mat src_img = cv::imread("tory.jpg", cv::IMREAD_COLOR);
			cv::Mat src_img_result(src_img.size(), CV_8UC3);
			
			cv::Mat destination;
			destination = *(cv::Mat*)param;
			cv::Mat destination_result(src_img.size(), CV_8UC3);
			
			cv::Mat mask_orig(src_img.size(), CV_8UC1, cv::Scalar(255, 255, 255));
			cv::Mat mask_result(src_img.size(), CV_8UC1);
			

			cv::Point2f src[4], dst[4];

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

				src[0] = cv::Point2f(p1.x, p1.y);
				src[1] = cv::Point2f(p2.x, p2.y);
				src[2] = cv::Point2f(p3.x, p3.y);
				src[3] = cv::Point2f(p4.x, p4.y);
				
				cv::Point2f temp_src[4], temp_dst[4];

				temp_src[0] = cv::Point2f(0, 0);
				temp_src[1] = cv::Point2f(0, src_img.rows);
				temp_src[2] = cv::Point2f(src_img.cols, src_img.rows);
				temp_src[3] = cv::Point2f(src_img.cols, 0);

				
				cv::Mat result = cv::getPerspectiveTransform(temp_src, src);
				cv::warpPerspective(mask_orig, mask_result, result, cv::Size(src_img.cols, src_img.rows));
				cv::warpPerspective(src_img, src_img_result, result, cv::Size(src_img.cols, src_img.rows));

				for(int i=0; i< src_img.cols; i++)
					for (int j = 0; j < src_img.rows; j++)
					{
						if (mask_result.at<unsigned char>(j, i) == 255)
						{
							destination_result.at<cv::Vec3b>(j, i)[0] = src_img_result.at<cv::Vec3b>(j, i)[0];
							destination_result.at<cv::Vec3b>(j, i)[1] = src_img_result.at<cv::Vec3b>(j, i)[1];
							destination_result.at<cv::Vec3b>(j, i)[2] = src_img_result.at<cv::Vec3b>(j, i)[2];
						}
						else
						{
							destination_result.at<cv::Vec3b>(j, i)[0] = destination.at<cv::Vec3b>(j, i)[0];
							destination_result.at<cv::Vec3b>(j, i)[1] = destination.at<cv::Vec3b>(j, i)[1];
							destination_result.at<cv::Vec3b>(j, i)[2] = destination.at<cv::Vec3b>(j, i)[2];
						}
					}
				
				//cv::imshow("mask_result", mask_result);
				//cv::imshow("src_img_result", src_img_result);
				cv::imshow("destination_result", destination_result);
			}

		}

};