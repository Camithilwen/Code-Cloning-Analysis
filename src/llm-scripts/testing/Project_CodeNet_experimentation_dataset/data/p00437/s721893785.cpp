#include <iostream>
using namespace std;
int main()
{
	int a,b,c; int CASE[1000][3];
	while(1)
	{
		cin >> a >> b >> c ; int total=a+b+c;
		if(a==0 && b==0 && c==0) break;
		int N,i,j,k,r; int pnt=0;
		cin >> N ; 
		int* test=new int[total]; for(int n=0;n<total;n++) test[n]=2;
		for(int n=0;n<N;n++)
		{
			cin >> i >> j >> k >> r ;
			if(r==1) test[i-1]=test[j-1]=test[k-1]=1;
			else CASE[pnt][0]=i-1,CASE[pnt][1]=j-1,CASE[pnt++][2]=k-1;
		}
		for(int n=0;n<pnt;n++)
		{
			if(test[CASE[n][0]]==1 && test[CASE[n][1]]==1 && test[CASE[n][2]]==2) test[CASE[n][2]]=0;
			if(test[CASE[n][0]]==1 && test[CASE[n][2]]==1 && test[CASE[n][1]]==2) test[CASE[n][1]]=0;
			if(test[CASE[n][1]]==1 && test[CASE[n][2]]==1 && test[CASE[n][0]]==2) test[CASE[n][0]]=0;
		}
		for(int n=0;n<total;n++)
		cout << test[n] << '\n' ;
	}
}