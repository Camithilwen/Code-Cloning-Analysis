#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#define maxn 1e9
#define pi acos(-1)
#define LL long long
using namespace std;
double aabs(double x)
{
	if(x<0)return -x;
	return x;
}
int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}
struct card{char suit,value;};
void bubble(struct card A[],int N)///冒泡排序；
{
	for(int i=0;i<N;i++)
		for(int j=N-1;j>=i+1;j--)
			if(A[j].value<A[j-1].value)
			{
				card t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			}
}
void selection(struct card A[],int N)///选择排序；
{
	for(int i=0;i<N;i++)
	{
		int minj=i;
		for(int j=i;j<N;j++)
		{
			if(A[j].value<A[minj].value)minj=j;
		}
		card t=A[i];
		A[i]=A[minj];
		A[minj]=t;
	}
}
LL cnt;
int l;
int a[1000000];
int n;
vector<int>G;
void insertionSort(int A[],int n,int g)///指定了间隔g的插入排序
{
	for(int i=g;i<n;i++)
	{
		int v=A[i];
		int j=i-g;
		while (j>=0&&A[j]>v) {
			A[j+g]=A[j];
			j-=g;
			cnt++;
		}
		A[j+g]=v;
	}
}
void shellSort(int A[],int n)///希尔排序；
{
	for(int h=1;;)//生成数列G={1,4,13,40,121,364,1093,.....}
	{
		if(h>n)break;
		G.push_back(h);
		h=3*h+1;
	}
	for(int i=G.size()-1;i>=0;i--)///按逆序指定G[i]=g;
	{
		insertionSort(A, n, G[i]);
	}
}
bool isStable(struct card c1[],struct card c2[],int N)///判断稳定；
{
	for(int i=0;i<N;i++)
	{
		if(c1[i].suit!=c2[i].suit)return false;
	}
	return true;
}
int main()
{
	card c1[107],c2[107];
	int n;
	char ch;
	cin>>n;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	cnt=0;
	shellSort(a, n);
	cout<<G.size()<<endl;
	for(int i=G.size()-1;i>=0;i--)
	{
		printf("%d",G[i]);
		if(i)printf(" ");
	}
	printf("\n");
	printf("%lld\n",cnt);
	for(int i=0;i<n;i++)printf("%d\n",a[i]);
	return 0;
}

