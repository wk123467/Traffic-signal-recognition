//#include <stdio.h>  
//#include <time.h>  
//#include <opencv2/opencv.hpp>  
//#include <opencv2/imgproc.hpp>  
//#include <iostream> 
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>  
//#include <opencv2/ml/ml.hpp>  
//#include <io.h> //�����ļ���غ���
//
//
//
//
//using namespace std;
//using namespace cv;
//using namespace cv::ml;
//
//void getFiles(string path, vector<string>& files); //��ȡͼƬ������·��
///**
//��ȡ�������ѵ��ͼƬ�����Ӧ��ǩ
//1.40���ٱ�־��
//2.��·ʩ����־��
//3.�����ʾ��
//4.���
//5.�̵�
//6.�Ƶ�
//*/
//void getMark1(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height);
//void getMark2(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height);
//void getMark3(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height);
//void getMark4(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height);
//void getMark5(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height);
//void getMark6(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height);
//
//Mat ChangeImageSize(const std::string &srcPath, const int width, const int height);
//
//
//
//int main()
//{
//	//����SVM����ͼƬ�ߴ�
//	const int width = 600;
//	const int height = 600;
//
//	//��ȡѵ������
//	Mat classes;
//	Mat trainingData;
//	Mat trainingImages;
//	vector<int> trainingLabels;
//	//getBubble()��getNoBubble()����ȡһ��ͼƬ��ὫͼƬ��������д��
//	//  �������У������ŻὫ��ǩд����һ�������У������ͱ�֤������
//	//  �ͱ�ǩ��һһ��Ӧ�Ĺ�ϵpush_back(0)����push_back(1)��ʵ����
//	//  ��������ǩ�Ĺ��̡�
//	getMark1(trainingImages, trainingLabels, width, height);
//	getMark2(trainingImages, trainingLabels, width, height);
//	getMark3(trainingImages, trainingLabels, width, height);
//	getMark4(trainingImages, trainingLabels, width, height);
//	getMark5(trainingImages, trainingLabels, width, height);
//	getMark6(trainingImages, trainingLabels, width, height);
//	//���������У���getBubble()��getNoBubble()д�õİ��������ľ��󿽱���trainingData����������ǩ��vector����������
//	//��ת���󿽱���trainingLabels����ˣ�����׼��������ɣ�trainingData��trainingLabels��������Ҫѵ�������ݡ�
//	Mat(trainingImages).copyTo(trainingData);
//	trainingData.convertTo(trainingData, CV_32FC1);
//	Mat(trainingLabels).copyTo(classes);
//	// ���������������ò���
//	Ptr<SVM> SVM_params = SVM::create();
//	SVM_params->setType(SVM::C_SVC);
//	SVM_params->setKernel(SVM::LINEAR);  //�˺���
//	SVM_params->setDegree(0);
//	SVM_params->setGamma(0.01);
//	SVM_params->setCoef0(0);
//	SVM_params->setC(100);
//	SVM_params->setNu(0);
//	SVM_params->setP(0.005);
//	SVM_params->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 1000, 0.01));
//	Ptr<TrainData> tData = TrainData::create(trainingData, ROW_SAMPLE, classes);
//	// ѵ��������
//	SVM_params->train(tData);
//	//����ģ��
//	SVM_params->save("svm_test.xml");//��ѵ���õ�ģ�ͱ����ڴ��ļ��С�
//	cout << "ѵ����ɣ�����" << endl;
//	getchar();
//	return 0;
//}
//Mat ChangeImageSize(const string &srcPath, const int width, const int height)
//{
//	Mat img = cv::imread(srcPath);
//	if (img.rows == height && img.cols == width)
//		return img;
//
//	Size dsize = Size(width, height);
//	Mat img2 = Mat(dsize, CV_32S);
//	resize(img, img2, dsize);
//	return img2;
//}
//void getFiles(string path, vector<string>& files)//���������ļ����µ������ļ���
//{
//	intptr_t   hFile = 0;
//	struct _finddata_t fileinfo;
//	string p;
//	int i = 30;
//	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
//	{
//		do
//		{
//			if ((fileinfo.attrib &  _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
//					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
//			}
//			else
//			{
//				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
//			}
//
//		} while (_findnext(hFile, &fileinfo) == 0);
//
//		_findclose(hFile);
//	}
//}
//
//void getMark1(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height)
//{
//	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\40";
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = ChangeImageSize(files[i].c_str(), width, height);
//
//		SrcImage = SrcImage.reshape(1, 1);
//
//
//
//		trainingImages.push_back(SrcImage);
//		trainingLabels.push_back(1);
//	}
//
//}
//
//
//void getMark2(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height)
//{
//	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\work";
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = ChangeImageSize(files[i].c_str(), width, height);
//
//
//		SrcImage = SrcImage.reshape(1, 1);
//
//
//		trainingImages.push_back(SrcImage);
//		trainingLabels.push_back(2);
//	}
//}
//void getMark3(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height)
//{
//	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\pass";
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = ChangeImageSize(files[i].c_str(), width, height);
//		SrcImage = SrcImage.reshape(1, 1);
//		trainingImages.push_back(SrcImage);
//		trainingLabels.push_back(3);
//	}
//}
//void getMark4(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height)
//{
//	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\red";
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = ChangeImageSize(files[i].c_str(), width, height);
//		SrcImage = SrcImage.reshape(1, 1);
//		trainingImages.push_back(SrcImage);
//		trainingLabels.push_back(4);
//	}
//}
//void getMark5(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height)
//{
//	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\green";
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = ChangeImageSize(files[i].c_str(), width, height);
//		SrcImage = SrcImage.reshape(1, 1);
//		trainingImages.push_back(SrcImage);
//		trainingLabels.push_back(5);
//	}
//}
//void getMark6(Mat& trainingImages, vector<int>& trainingLabels, const int width, const int height)
//{
//	const char * filePath = "C:\\Users\\22923\\Desktop\\mark\\images\\yellow";
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = ChangeImageSize(files[i].c_str(), width, height);
//		SrcImage = SrcImage.reshape(1, 1);
//		trainingImages.push_back(SrcImage);
//		trainingLabels.push_back(6);
//	}
//}
