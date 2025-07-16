#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	
	double x,y,x2,y2;
	//cout<<sizeof(double);
	scanf("%lf%lf%lf%lf", &x,&y,&x2,&y2);
	printf("%f\n",hypot(x-x2,y-y2));
	//insert code above
	return 0;
}
//aoj1_10_a.cc