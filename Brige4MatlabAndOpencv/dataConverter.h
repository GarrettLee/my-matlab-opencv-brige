#pragma once

#ifdef BRIGE4MATLABANDOPENCV_EXPORTS
#define BRIGE4MATLABANDOPENCV_API __declspec(dllexport)
#else
#define BRIGE4MATLABANDOPENCV_API __declspec(dllimport)
#endif


#include "opencv2/opencv.hpp"
#include "mex.h"
#define GET_CV_CHANNELS(type) CV_MAT_CN_MASK & type


namespace garrettWorkspace {
	class  dataConverter {
	public:
		dataConverter();

	private:
	};

	class BRIGE4MATLABANDOPENCV_API numericConverter :dataConverter {
	public:
		cv::Mat mx2cv(const mxArray * prhs, int cvType);

	private:
	};
}