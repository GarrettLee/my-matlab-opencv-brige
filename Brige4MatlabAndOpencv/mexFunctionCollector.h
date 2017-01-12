#pragma once
#pragma once

#ifdef BRIGE4MATLABANDOPENCV_EXPORTS
#define BRIGE4MATLABANDOPENCV_API __declspec(dllexport)
#else
#define BRIGE4MATLABANDOPENCV_API __declspec(dllimport)
#endif


#include "opencv2/opencv.hpp"
#include "mex.h"

namespace mexFunctionCollector {		
	//����Ϊ����������
	class BRIGE4MATLABANDOPENCV_API numericArray {	
	public:
		numericArray();
		numericArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		cv::vector<int> getDims();
		virtual cv::Mat tocv(int cvType) = 0;
	protected:
		mxArray *  createNumericArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		const size_t * getDims(const mxArray *pa);
		const size_t getDimNums(const mxArray *pa);
		cv::vector<int> calDims();
		cv::vector<int> dims;				//�ṹ��h��w��.....
		mxArray * array;
	};

	//double
	class BRIGE4MATLABANDOPENCV_API doubleArray : public numericArray {
	public:
		doubleArray();
		doubleArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		virtual cv::Mat tocv(int cvType) = 0;			//�� =0 ���Ǵ����࣬�����಻����ʵ���������������
	};

	//ʵdouble
	class BRIGE4MATLABANDOPENCV_API realDoubleArray : public doubleArray {
	public:
		realDoubleArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		realDoubleArray(cv::Mat mat);

		virtual cv::Mat tocv(int cvType);
	private:
		cv::Mat mx2cv(const mxArray * prhs, int cvType, cv::vector<int> dims);
		mxArray * cv2mx(cv::Mat mat);
	};
}