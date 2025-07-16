#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,p,a,b,c,d,e,f,m,s;
	char l[32];
	pair<double,string>A[50];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;++i)
		{
			scanf("%s%d%d%d%d%d%d%d%d%d",l,&p,&a,&b,&c,&d,&e,&f,&s,&m);
			A[i].second=l;
			A[i].first=-(f*s*m-p)/double(a+b+c+m*(d+e));
		}
		sort(A,A+n);
		for(i=0;i<n;++i)puts(A[i].second.c_str());
		puts("#");
	}
	return 0;
}