// mynteyed_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

#include <mynteyed/camera.h>
#include <mynteyed/utils.h>

MYNTEYE_USE_NAMESPACE

int main()
{
	Camera cam;
	DeviceInfo dev_info;
	if (!util::select(cam, &dev_info)) {
		return 1;
	}
	util::print_stream_infos(cam, dev_info.index);

	std::cout << "Open device: " << dev_info.index << ", "
		<< dev_info.name << std::endl << std::endl;

	OpenParams params(dev_info.index);
	params.stream_mode = StreamMode::STREAM_2560x720;
	params.ir_intensity = 4;
	params.framerate = 30;

	cam.Open(params);

	std::cout << std::endl;
	if (!cam.IsOpened()) {
		std::cerr << "Error: Open camera failed" << std::endl;
		return 1;
	}
	std::cout << "Open device success" << std::endl << std::endl;

	std::cout << "Press ESC/Q on Windows to terminate" << std::endl;

	cv::namedWindow("left");
	cv::namedWindow("right");
	cv::namedWindow("depth");

	for (;;) {
		auto left_color = cam.GetStreamData(ImageType::IMAGE_LEFT_COLOR);
		if (left_color.img) {
			cv::Mat left = left_color.img->To(ImageFormat::COLOR_BGR)->ToMat();
			cv::imshow("left", left);
		}

		auto right_color = cam.GetStreamData(ImageType::IMAGE_RIGHT_COLOR);
		if (right_color.img) {
			cv::Mat right = right_color.img->To(ImageFormat::COLOR_BGR)->ToMat();
			cv::imshow("right", right);
		}

		auto image_depth = cam.GetStreamData(ImageType::IMAGE_DEPTH);
		if (image_depth.img) {
			cv::Mat depth = image_depth.img->To(ImageFormat::DEPTH_BGR)->ToMat();
			cv::imshow("depth", depth);
		}

		char key = static_cast<char>(cv::waitKey(1));
		if (key == 27 || key == 'q' || key == 'Q') {  // ESC/Q
			break;
		}
	}

	cam.Close();
	cv::destroyAllWindows();
	return 0;
}
