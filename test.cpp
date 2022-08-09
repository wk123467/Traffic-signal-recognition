#include <stdio.h>  
#include <time.h>  
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc.hpp>  
#include <iostream> 
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>  
#include <io.h>

using namespace std;
using namespace cv;
//using namespace ml;

void getFiles(string path, vector<string>& files);
Mat ChangeImageSize(const string &srcPath, const int width, const int height);


int main()
{
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	int result4 = 0;
	int result5 = 0;
	int result6 = 0;
	
	/*设置SVM需要的输入图片尺寸*/
	int width = 600;
	int height = 600;

	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\test_data";
	vector<string> files;
	getFiles(filePath, files);
	int number = files.size();
	cout << "共有测试图片" << number << "张\n" << endl;
	Ptr<ml::SVM>svm = ml::SVM::load("svm_test.xml");

	for (int i = 0; i < number; i++)
	{
		Mat inMat = ChangeImageSize(files[i].c_str(), width, height);
		Mat p = inMat.reshape(1, 1);
		p.convertTo(p, CV_32FC1);
		int response = (int)svm->predict(p);
		cout << "识别的数字为：" << response << endl;
		if (response == 1)
		{
			result1++;
		}
		else if(response == 2)
		{
			result2++;
		}
		else if (response == 3)
		{
			result3++;
		}
		else if (response == 4)
		{
			result4++;
		}
		else if (response == 5)
		{
			result5++;
		}
		else if (response == 6)
		{
			result6++;
		}
	}
	cout << "识别40限速标志的个数为：" << result1 << endl;
	cout << "识别道路施工标志的个数为：" << result2 << endl;
	cout << "识别隧道警示标志的个数为：" << result3 << endl;
	cout << "识别红灯的个数为：" << result4 << endl;
	cout << "识别绿灯的个数为：" << result5 << endl;
	cout << "识别黄灯的个数为：" << result6 << endl;
	getchar();
	return 0;
}
void getFiles(string path, vector<string>& files)  //用来遍历文件夹下所有文件
{
	intptr_t   hFile = 0;
	/*long   hFile = 0;*/
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
Mat ChangeImageSize(const string &srcPath, const int width, const int height)
{
	Mat img = cv::imread(srcPath);
	if (img.rows == height && img.cols == width)
		return img;

	Size dsize = Size(width, height);
	Mat img2 = Mat(dsize, CV_32S);
	resize(img, img2, dsize);
	return img2;
}