// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Brige4MatlabAndOpencv.h"
#include "mex.h"
#include "opencv2\opencv.hpp"
using namespace cv;
using namespace mexFunctionCollector;
int main()
{
	mwSize dims[4] = { 10, 10, 3, 13 };

	//多态
	numericArray * array =& realDoubleArray(4, dims,  mxDOUBLE_CLASS, mxREAL);
	array->tocv(CV_16S);

	/*
	mxArray *test = mxCreateNumericArray(4, dims, mxDOUBLE_CLASS, mxREAL);
	const size_t * dim = mxGetDimensions(test);
	const size_t num = mxGetNumberOfDimensions(test);
	double *testPtr = mxGetPr(test);
	

	for (int i = 0; i < 1; i++) {
		testPtr[i] = 0;
	}
	garrettWorkspace::dataConverter dc;
	dc.mx2cv(test, 0);
	dc.mx2cv(test, 1);
	dc.mx2cv(test, 2);

	dc.mx2cv(test, 3);
	dc.mx2cv(test, 4);
	dc.mx2cv(test, 5);
	dc.mx2cv(test, 6);*/
    return 1;
}

