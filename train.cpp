//#include <stdio.h>  
//#include <time.h>  
//#include <opencv2/opencv.hpp>  
//#include <opencv2/imgproc.hpp>  
//#include <iostream> 
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>  
//#include <opencv2/ml/ml.hpp>  
//#include <io.h> //查找文件相关函数
//
//
//
//
//using namespace std;
//using namespace cv;
//using namespace cv::ml;
//
//void getFiles(string path, vector<string>& files); //获取图片的所有路径
///**
//获取三种类的训练图片及其对应标签
//1.40限速标志牌
//2.道路施工标志牌
//3.隧道警示牌
//4.红灯
//5.绿灯
//6.黄灯
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
//	//设置SVM输入图片尺寸
//	const int width = 600;
//	const int height = 600;
//
//	//获取训练数据
//	Mat classes;
//	Mat trainingData;
//	Mat trainingImages;
//	vector<int> trainingLabels;
//	//getBubble()与getNoBubble()将获取一张图片后会将图片（特征）写入
//	//  到容器中，紧接着会将标签写入另一个容器中，这样就保证了特征
//	//  和标签是一一对应的关系push_back(0)或者push_back(1)其实就是
//	//  我们贴标签的过程。
//	getMark1(trainingImages, trainingLabels, width, height);
//	getMark2(trainingImages, trainingLabels, width, height);
//	getMark3(trainingImages, trainingLabels, width, height);
//	getMark4(trainingImages, trainingLabels, width, height);
//	getMark5(trainingImages, trainingLabels, width, height);
//	getMark6(trainingImages, trainingLabels, width, height);
//	//在主函数中，将getBubble()与getNoBubble()写好的包含特征的矩阵拷贝给trainingData，将包含标签的vector容器进行类
//	//型转换后拷贝到trainingLabels里，至此，数据准备工作完成，trainingData与trainingLabels就是我们要训练的数据。
//	Mat(trainingImages).copyTo(trainingData);
//	trainingData.convertTo(trainingData, CV_32FC1);
//	Mat(trainingLabels).copyTo(classes);
//	// 创建分类器并设置参数
//	Ptr<SVM> SVM_params = SVM::create();
//	SVM_params->setType(SVM::C_SVC);
//	SVM_params->setKernel(SVM::LINEAR);  //核函数
//	SVM_params->setDegree(0);
//	SVM_params->setGamma(0.01);
//	SVM_params->setCoef0(0);
//	SVM_params->setC(100);
//	SVM_params->setNu(0);
//	SVM_params->setP(0.005);
//	SVM_params->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 1000, 0.01));
//	Ptr<TrainData> tData = TrainData::create(trainingData, ROW_SAMPLE, classes);
//	// 训练分类器
//	SVM_params->train(tData);
//	//保存模型
//	SVM_params->save("svm_test.xml");//将训练好的模型保存在此文件中。
//	cout << "训练完成！！！" << endl;
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
//void getFiles(string path, vector<string>& files)//用来遍历文件夹下的所有文件。
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
