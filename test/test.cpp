// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Brige4MatlabAndOpencv.h"
#include "mex.h"
#include "opencv2\opencv.hpp"
using namespace cv;
using namespace mexFunctionCollector;
int main()
{
	mwSize dims[3] = { 10, 10, 3};

	//��̬,��֪��Ϊʲô��������ʹ�ö�̬������ֵ�Ļ������array->dims��һ���޷���ʼ������
	realDoubleArray  array = realDoubleArray(3, dims,  mxDOUBLE_CLASS, mxREAL);
	cv::Mat out = array.tocv(CV_64FC3);
	realDoubleArray array2 = realDoubleArray(out);

	int tesst = out.col(2).row(5).data[0];

    return 3;
}

