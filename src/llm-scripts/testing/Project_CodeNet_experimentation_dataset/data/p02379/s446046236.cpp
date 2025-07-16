//using class
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

class Point{
  public: //以下、外部からaccess可能
  double x,y; //member
  
  Point(double xx,double yy){ //コンストラクタ
    x = xx;
    y = yy;
  }
};

double getDistance(Point p1, Point p2){
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main(){
  Point p1(0,0), p2(0,0); //変数宣言
  //コンストラクタによって座標指定して初期化
  
  cin >> p1.x >> p1.y >> p2.x >> p2.y; //public access可
  
  printf ("%lf", getDistance(p1, p2) );
  
  return 0;
}
