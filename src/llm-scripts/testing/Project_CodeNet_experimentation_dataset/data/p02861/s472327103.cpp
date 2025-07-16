#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
struct Data{

  long double x;
  long double y;
};
int main(){

  int N;
  cin>>N;
  vector<Data>data(N);
  double countmax=1;
  for(double i=0;i<=N-1;i++){
  
    cin>>data[i].x>>data[i].y;
    countmax*=i+1;
  }
  double x;
  double x2;
  double y;
  double y2;
  vector<double>P(N);
  for(int i=0;i<=N-1;i++)P[i]=i+1;
  double ave=0;
  do{
    for(int i=0;i<=N-2;i++){
    
      x=data[P[i]-1].x;
      x2=data[P[i+1]-1].x;
      y=data[P[i]-1].y;
      y2=data[P[i+1]-1].y;
      ave+=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
    }
  }while(next_permutation(P.begin(),P.end()));
  ave/=countmax;
  cout<< fixed << setprecision(15)<<ave;
  return 0;
}