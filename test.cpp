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
	
	/*����SVM��Ҫ������ͼƬ�ߴ�*/
	int width = 600;
	int height = 600;

	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\test_data";
	vector<string> files;
	getFiles(filePath, files);
	int number = files.size();
	cout << "���в���ͼƬ" << number << "��\n" << endl;
	Ptr<ml::SVM>svm = ml::SVM::load("svm_test.xml");

	for (int i = 0; i < number; i++)
	{
		Mat inMat = ChangeImageSize(files[i].c_str(), width, height);
		Mat p = inMat.reshape(1, 1);
		p.convertTo(p, CV_32FC1);
		int response = (int)svm->predict(p);
		cout << "ʶ�������Ϊ��" << response << endl;
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
	cout << "ʶ��40���ٱ�־�ĸ���Ϊ��" << result1 << endl;
	cout << "ʶ���·ʩ����־�ĸ���Ϊ��" << result2 << endl;
	cout << "ʶ�������ʾ��־�ĸ���Ϊ��" << result3 << endl;
	cout << "ʶ���Ƶĸ���Ϊ��" << result4 << endl;
	cout << "ʶ���̵Ƶĸ���Ϊ��" << result5 << endl;
	cout << "ʶ��ƵƵĸ���Ϊ��" << result6 << endl;
	getchar();
	return 0;
}
void getFiles(string path, vector<string>& files)  //���������ļ����������ļ�
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