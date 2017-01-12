#include "stdafx.h"

#include "mexFunctionCollector.h"
mexFunctionCollector::numericArray::numericArray()
{
}

mexFunctionCollector::numericArray::numericArray(size_t ndim, const size_t * idims, mxClassID classid, mxComplexity flag)
{
	this->array = createNumericArray( ndim, idims,  classid,  flag);
	this->dims = this->calDims();
	
}

cv::vector<int> mexFunctionCollector::numericArray::getDims()
{
	return this->dims;
}

mexFunctionCollector::realDoubleArray::realDoubleArray(size_t ndim, const size_t * dims, mxClassID classid, mxComplexity flag) : doubleArray( ndim,   dims,  classid,  flag)
{

}

mexFunctionCollector::realDoubleArray::realDoubleArray(cv::Mat mat)
{
	this->array = cv2mx(mat);
	this->dims = this->calDims();
}

cv::Mat mexFunctionCollector::realDoubleArray::tocv(int cvType)
{
	return this->mx2cv(this->array, cvType, this->dims);
}

cv::Mat mexFunctionCollector::realDoubleArray::mx2cv(const mxArray * prhs, int cvType, cv::vector<int> dims)
{
	int dimnums = dims.size();
	assert(dimnums <= 3);
	
	const int channels = dims[2];
	int depth = CV_MAT_DEPTH(cvType);	//深度，也就是类型
	int cn = CV_MAT_CN(cvType);	//通道数
	assert(cn == channels);
	double *samples;
	samples = mxGetPr(prhs);
	int width = dims[1];
	int height = dims[0];
	cv::Mat out = cv::Mat(height, width, cvType);
	
	switch (depth) {
		//CV_8U
	case 0:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
		//CV_8S
	case 1:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
		//CV_16U
	case 2:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
		//CV_16S
	case 3:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
		//CV_32S
	case 4:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
		//CV_32F
	case 5:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
		//CV_64F
	case 6:
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++) {
				for (int c = 0; c < channels; c++) {
					out.row(i).col(k).data[c] = samples[k * height + i];
				}
			}
		}
		break;
	default:
		break;
	}

	return out;
}

mxArray * mexFunctionCollector::realDoubleArray::cv2mx(cv::Mat mat)
{
	int h = mat.rows;
	int w = mat.cols;
	int c = mat.channels();
	mwSize dims[3] = { h, w, c };
	mxArray * pMat = mxCreateNumericArray(3, dims, mxDOUBLE_CLASS, mxREAL);
	double *input = (double *)mxGetData(pMat);
	for (int i = 0; i < h; i++)			//i为行
	{
		for (int j = 0; j < w; j++)		//j为列
		{
			for (int ch = 0; ch < c; ch++)	//ch为第三维，也就是说mxArray顺序为先执行行，然后再执行列，最后执行第三维，如果还有第四维，这时候再到第四维
			{
				input[j*h + i + ch*h*w] = mat.row(i).col(j).data[c - 1 - ch];
			}
		}
	}

	return pMat;
}

cv::vector<int> mexFunctionCollector::numericArray::calDims()
{
	cv::vector<int> dims;
	const size_t * dim = mxGetDimensions(array);
	const size_t num = mxGetNumberOfDimensions(array);
	for (int i = 0; i < num; i++){
		dims.push_back(dim[i]);
	}
	return dims;
}

mxArray * mexFunctionCollector::numericArray::createNumericArray(size_t ndim, const size_t * dims, mxClassID classid, mxComplexity flag)
{
	return mxCreateNumericArray( ndim,   dims,  classid,  flag);
}

const size_t * mexFunctionCollector::numericArray::getDims(const mxArray * pa)
{
	return mxGetDimensions(pa);
}

const size_t mexFunctionCollector::numericArray::getDimNums(const mxArray * pa)
{
	return mxGetNumberOfDimensions(pa);
}

mexFunctionCollector::doubleArray::doubleArray()
{
}

mexFunctionCollector::doubleArray::doubleArray(size_t ndim, const size_t * dims, mxClassID classid, mxComplexity flag):numericArray( ndim,  dims,  classid,  flag)
{
}
