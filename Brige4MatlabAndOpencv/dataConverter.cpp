#include "stdafx.h"
#include "dataConverter.h"
using namespace garrettWorkspace;
using namespace cv;
garrettWorkspace::dataConverter::dataConverter()
{
}
cv::Mat numericConverter::mx2cv(const mxArray * prhs, int cvType)
{

	int depth = CV_MAT_DEPTH(cvType);	//��ȣ�Ҳ��������
	int channel = CV_MAT_CN(cvType);	//ͨ����
	assert(channel == 1);
	double *samples;
	samples = mxGetPr(prhs);
	int width = (int)mxGetN(prhs);
	int height = (int)mxGetM(prhs);
	Mat out = Mat(height, width, cvType);
	switch (depth) {
	//CV_8U
	case 0:									
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<Vec<unsigned char, 1>>(i, k) =  samples[k * height + i] ;
			}
		}
		break;
	//CV_8S
	case 1:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<char>(i, k) = samples[k * height + i];
			}
		}
		break;
	//CV_16U
	case 2:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<unsigned short int>(i, k) = samples[k * height + i];
			}
		}
		break;
	//CV_16S
	case 3:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<short int>(i, k) = samples[k * height + i];
			}
		}
		break;
	//CV_32S
	case 4:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<int>(i, k) = samples[k * height + i];
			}
		}
		break;
	//CV_32F
	case 5:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<float>(i, k) = samples[k * height + i];
			}
		}
		break;
	//CV_64F
	case 6:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				out.at<double>(i, k) = samples[k * height + i];
			}
		}
		break;
	default:
		break;
	}

	
	return out;
}

mxArray * cv2mx(Mat imgSrc) {

	int h = imgSrc.rows;
	int w = imgSrc.cols;
	int c = imgSrc.channels();
	mxArray *pMat = NULL;
	double *input = NULL;
	if (c == 1) // gray image
	{
		mwSize dims[2] = { h, w };
		pMat = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
		input = (double *)mxGetData(pMat);
		MatIterator_<float> it = imgSrc.begin<float>();
		int inn = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				input[j*h + i] = (double)*it++;

			}
		}


	}
	else if (c == 3) // 3-channel image
	{
		mwSize dims[3] = { h, w, c };
		pMat = mxCreateNumericArray(c, dims, mxDOUBLE_CLASS, mxREAL);
		
		input = (double *)mxGetData(pMat);
		for (int i = 0; i < h; i++)			//iΪ��
		{
			for (int j = 0; j < w; j++)		//jΪ��
			{
				for (int ch = 0; ch < c; ch++)	//chΪ����ά��Ҳ����˵mxArray˳��Ϊ��ִ���У�Ȼ����ִ���У����ִ�е���ά��������е���ά����ʱ���ٵ�����ά
				{
					input[j*h + i + ch*h*w] = imgSrc.row(i).col(j).data[c - 1 - ch];
				}
			}
		}
	}
	return pMat;


}
