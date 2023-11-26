#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Eigen>
using namespace std;
using namespace Eigen;

int main(int argc,char **argv)
{
	cout.precision(3);
	Vector3d v(1,0,0);//定义三维空间向量
	//定义旋转矩阵,Identify将其初始化为单位阵
	Matrix3d rotationMatrix=Eigen::Matrix3d::Identity();
	cout<<"旋转矩阵初始化后=\n"<<rotationMatrix<<endl;
	//定义旋转向量,M_PI/4表示180度/4=45度,沿着z轴旋转45度


	AngleAxisd rotationVector(M_PI/4,Vector3d(0,0,1));

	  //旋转向量对应的旋转矩阵
  rotationMatrix = rotationVector.matrix();
  //或者rotationMatrix = rotationVector.toRotationMatrix()
  cout << "由旋转向量映射的旋转矩阵 = \n" << rotationMatrix << endl;


  //利用旋转矩阵和旋转向量对v进行旋转
  Vector3d vRotated = rotationMatrix * v;	//利用向量
  cout << "v经过旋转矩阵作用后 = \n" << vRotated.transpose() << endl;
  vRotated = rotationVector * v;	//利用矩阵
  cout << "v经过旋转向量作用后 = \n" << vRotated.transpose() << endl;


  //定义欧拉角，2 1 0表示按ZYX顺序分析；roll pitch yaw
  Vector3d eulerAngles = rotationMatrix.eulerAngles(2,1,0);
  cout << "roll pitch yaw = " << eulerAngles.transpose() << endl;


  //定义变换阵，变换阵使用的是齐次坐标，主要元素是旋转阵和平移向量
  //可以使用()对变换阵元素赋值，也可以直接改变变换阵赋的旋转阵平移向量，但不能使用<<对变换阵元素赋值
  Isometry3d T = Isometry3d::Identity();	//初始化为单位阵
  T.rotate(rotationVector);	//设置旋转阵，也可以利用旋转向量进行设置
  T.pretranslate(Vector3d(1,3,4));	//设置平移向量
  //T(0, 0) = 0, T(0, 1) = 1;    //可以这样改变T阵元素，但不能使用T <<1,2,3……;
  cout << "变换矩阵 = \n" << T.matrix() << endl;


  //定义四元数
  Quaterniond q = Quaterniond(rotationVector);	//也可以用旋转矩阵进行初始化
  cout << "四元数（虚部（3个），实部） = " << q.coeffs().transpose() << endl;    //coeffs的作用是按(x,y,z,w)顺序返回四元数各个系数并存放在一个四维向量中，其中（w是实部）


  //利用四元数进行旋转
  //v是一个三维空间中的向量，*运算利用了重载，数学上的表达是qvq^(-1)，运算结果是三维空间向量
  vRotated = q*v;
  cout << "v经过四元数作用后 = " << vRotated.transpose() << endl;
  //利用数学定义计算，将向量写成四元数进行运算，运算结果是四元数
  cout << "v经过四元数作用后 = " << (q*Quaterniond(0,1,0,0)*q.inverse()).coeffs().transpose() << endl;


  return 0;
}

