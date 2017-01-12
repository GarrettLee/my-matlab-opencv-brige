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
	mwSize dims[3] = { 1, 1, 3};

	//多态,不知道为什么，当这里使用多态性来赋值的话会出现array->dims这一项无法初始化！！
	realDoubleArray  array = realDoubleArray(3, dims,  mxDOUBLE_CLASS, mxREAL);
	cv::Mat out = array.tocv(CV_64FC3);
	double a = out.at<Vec<double,3>>(0, 0)[1];
	double b = out.at<Vec<double, 3>>(0, 0)[0];
	realDoubleArray array2 = realDoubleArray(out);

	cv::FileStorage fs("afaf.xml", cv::FileStorage::WRITE);
	
	fs << "data" << 100;
	fs.release();

	int tesst = out.col(2).row(5).data[0];

    return 3;
}

