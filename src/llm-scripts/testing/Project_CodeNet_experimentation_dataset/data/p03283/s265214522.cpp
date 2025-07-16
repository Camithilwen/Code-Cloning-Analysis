#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l[200000+5],r[200000+5],n,m,q,ret[200000+5],sz,p,num1[200000+5],num[200000];
int l1[200000+5],r1[200000+5],vec[600000+5],c[600000+5];
void Add( int x)  //树状数组加入
{
    for(;x<=sz;x+=(x&-x))
        c[x]++;  //因为这里只需要1，所以我就写出c[x]++了
}
int Sum( int x)  //树状数组求和，同上面的sum(x)
{
     int s=0;  //计数的变量
    for(;x>0;x-=(x&-x))  //累计
        s+=c[x];
    return s;  //返回结果
}
bool cmp1(int a,int b){
	return r1[a]<r1[b];
}
bool cmp(int a,int b){
	return r[a]<r[b];
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
    	cin>>l[i]>>r[i];
    	vec[p++]=l[i];
    	vec[p++]=r[i];
    	num[i]=i;
	}
	for(int i=1;i<=q;i++){
		cin>>l1[i]>>r1[i];
		vec[p++]=l1[i];
		vec[p++]=r1[i];
		num1[i]=i;
	}
	sort(vec,vec+p);
	sz=unique(vec,vec+p)-vec;
	for(int i=1;i<=m;i++){
		l[i]=lower_bound(vec,vec+sz,l[i])-vec+1;
		r[i]=lower_bound(vec,vec+sz,r[i])-vec+1;
	}
	for(int i=1;i<=q;i++){
		l1[i]=lower_bound(vec,vec+sz,l1[i])-vec+1;
		r1[i]=lower_bound(vec,vec+sz,r1[i])-vec+1;
	}
	sort(num1+1,num1+q+1,cmp1);
	sort(num+1,num+m+1,cmp);
	
	int j=1;
	for(int k=1;k<=q;k++){
		int i=num1[k];
		while(j<=m&&r[num[j]]<=r1[i]){
		Add(l[num[j++]]);	
		} 
		ret[i]=j-Sum(l1[i]-1)-1;
	
	}
	for(int i=1;i<=q;i++){
		cout<<ret[i]<<endl;
	}
}