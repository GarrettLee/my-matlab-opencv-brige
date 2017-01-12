// saveAsCv.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "saveAsCv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "mex.h"
#include "Brige4MatlabAndOpencv.h"
#include "opencv2/opencv.hpp"
#include <io.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs,  mxArray *prhs[]) {
	if (nrhs != 2) {
		mexPrintf("Only one aurgment requred.\n");
		return;
	}
	if (!mxIsDouble(prhs[0])) {
		mexPrintf("The first aurgment must be double.\n");
		return;
	}
	if (mxIsComplex(prhs[0])) {
		mexPrintf("The first aurgment must be real.\n");
		return;
	}
	char dir[5000];
	mxGetString(prhs[1], dir, 5000);

	mexFunctionCollector::realDoubleArray array(prhs[0]);
	cv::Mat mat = array.tocv(CV_32FC3);
	cv::FileStorage fs(dir, cv::FileStorage::WRITE);
	fs << "data" << mat;
	fs.release();
	mexPrintf("Saved.\n");
}