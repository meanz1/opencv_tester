#include "opencv2/opencv.hpp"
#include <iostream>
#include "text_construct1.hpp"

void on_mouse(int event, int x, int y, int flags, void* param);
click n;

int main()
{	
	// src_img is background of text
	cv::Mat src_img(1000, 1000, CV_8UC3, cv::Scalar(0, 0, 0));

	// destination is original laptop image
	cv::Mat destination = cv::imread("apple.jpg", cv::IMREAD_COLOR);

	// resize a laptop image
	cv::resize(destination, destination, cv::Size(src_img.cols, src_img.rows));

	// src_img_result is transformation of src_img
	cv::Mat src_img_result(src_img.size(), CV_8UC3);

	//destination_result is original laptop image + src_img_result
	cv::Mat destination_result(src_img.size(), CV_8UC3);

	cv::Point2f src[4], dst[4];
	n.flow = cv::Point(0, 550);
	cv::namedWindow("destination");
	n.count = 0;
	cv::imshow("destination", destination);
	cv::waitKey();
	cv::setMouseCallback("destination", on_mouse, &destination);
	//while(1)
	//{
		if (n.count == 0)
		{
			std::string des = "minji";

			while (n.flow.x < 500) {
				std::cout << n.flow.x << "  " << std::endl;
				origin_mat m;
				m.ori();
				cv::putText(m.origin, des, n.flow, 0, 9, cv::Scalar(255, 0, 0), 15);

				src[0] = cv::Point2f(n.p1.x, n.p1.y);
				src[1] = cv::Point2f(n.p2.x, n.p2.y);
				src[2] = cv::Point2f(n.p3.x, n.p3.y);
				src[3] = cv::Point2f(n.p4.x, n.p4.y);

				cv::Point2f temp_src[4], temp_dst[4];

				temp_src[0] = cv::Point2f(0, 0);
				temp_src[1] = cv::Point2f(0, src_img.rows);
				temp_src[2] = cv::Point2f(src_img.cols, src_img.rows);
				temp_src[3] = cv::Point2f(src_img.cols, 0);


				cv::Mat result = cv::getPerspectiveTransform(temp_src, src);
				cv::warpPerspective(m.origin, src_img_result, result, cv::Size(src_img.cols, src_img.rows));

				for (int i = 0; i < src_img.cols; i++)
					for (int j = 0; j < src_img.rows; j++)
					{
						if (src_img_result.at<cv::Vec3b>(j, i)[0] == 0 && src_img_result.at<cv::Vec3b>(j, i)[1] == 0 && src_img_result.at<cv::Vec3b>(j, i)[2] == 0)
						{
							destination_result.at<cv::Vec3b>(j, i)[0] = destination.at<cv::Vec3b>(j, i)[0];
							destination_result.at<cv::Vec3b>(j, i)[1] = destination.at<cv::Vec3b>(j, i)[1];
							destination_result.at<cv::Vec3b>(j, i)[2] = destination.at<cv::Vec3b>(j, i)[2];
						}
						else
						{
							destination_result.at<cv::Vec3b>(j, i)[0] = src_img_result.at<cv::Vec3b>(j, i)[0];
							destination_result.at<cv::Vec3b>(j, i)[1] = src_img_result.at<cv::Vec3b>(j, i)[1];
							destination_result.at<cv::Vec3b>(j, i)[2] = src_img_result.at<cv::Vec3b>(j, i)[2];
						}
					}

				cv::imshow("src_img", m.origin);
				cv::imshow("src_img_result", src_img_result);
				cv::imshow("destination_result", destination_result);
				n.flow.x++;
				cv::waitKey(1);
			}
			
		}
		//Sleep(10);
	//}
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void* param)
{
	cv::Mat img;
	img = *(cv::Mat*)param;

	cv::Point point;
	point = cv::Point(x, y);

	if(event == cv::EVENT_LBUTTONDOWN)
		std::cout << "LBUTTUON DOWN : " << point.x << " " << point.y << std::endl;
	if (event == cv::EVENT_LBUTTONUP)
	{
		std::cout << "LBUTTON UP : " << point.x << " " << point.y << std::endl;
		n.count++;
		std::cout << n.count << std::endl;
		n.pointing(&img, point);
	}

}