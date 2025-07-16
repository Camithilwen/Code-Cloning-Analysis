#include<iostream>
#include<complex>
#include<math.h>
#include<algorithm>
using namespace std;
int n,i,j;
double x[100],y[100],a[101],Ans[100];
complex<double>z[100];
int main()
{
  cin >> n;
  for(i=0;i<n;i++){
    cin >> x[i] >> y[i];
    z[i]=complex<double>(x[i],y[i]);
  }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        a[j]=fmod(arg(z[j]-z[i])+2*M_PI,2*M_PI);
      }
      sort(a,a+n);
      a[n]=a[1]+2*M_PI;
      for(j=1;j<n;j++){
        if(a[j+1]-a[j]>=M_PI){Ans[i]=(a[j+1]-a[j]-M_PI)/2/M_PI;
                             }
      }
      cout << Ans[i] << endl;
    }
}