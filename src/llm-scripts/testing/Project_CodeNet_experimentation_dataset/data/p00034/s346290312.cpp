#include<cstdio>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
	int l[10],v[2];
	while(~scanf("%d",l)){
		for(int i=1;i<10;i++)	scanf(",%d",l+i);
		scanf(",%d,%d",v,v+1);
		int len=accumulate(l,l+10,0);
		vector<int> rail(len);
		for(int i=0,cnt=0;i<10;i++){
			for(int j=0;j<l[i];j++,cnt++){
				rail[cnt]=i+1;
			}
		}
		double x=1.0*v[0]/(v[0]+v[1])*len;
		if(-1e-9<(x-(int)x) && (x-(int)x)<1e-9)	x-=0.1;
		printf("%d\n",rail[(int)x]);
	}
	return 0;
}