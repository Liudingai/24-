#include <iostream>
#include<vector>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char **argv){
     vector<Point3f> objectPoints;
     vector<Point2f> imagePoints;
     objectPoints={
     (0,0,0),
	(0,30,0),
	(30,0,0),
	(30,30,0)
     }
     imagePoints={
     
	 (0,0),
     	(0,20),
	(10,2),
	(8,22)
     }
     Mat cameraMatrix=(Mat_<double>(3,3)<<458.654,0,367.215,0,457.296,248.375,0,0,1);
	Mat distCoeffs=(Mat_<double>(1,5)<<0,0,0,0,0);

	Mat rvec;
	Mat tvec;
	bool success=solvePnP(objectPoints,imagePoints,cameraMatrix,distCoeffs,rvec,tvec);

	if(success){
	 Mat rotationMatrix;
	 Rodrigues(rvec,rotationMatrix);

	 cout<<"Rotation Vector:"<<endl<<rvec<<endl;
	 cout<<"Translation Vector:"<<endl<<tvec<<endl;
	 cout<<"Rotation Matrix"<<endl<<rotationMatrix<<endl;
	
	         float distance = sqrt(tvec.at<double>(0,0) * tvec.at<double>(0,0) + tvec.at<double>(1,0) * tvec.at<double>(1,0) + tvec.at<double>(2,0) * tvec.at<double>(2,0)) / 10;
                 cout << "distance = "<< distance << std::endl;
	}
	return 0;

}
