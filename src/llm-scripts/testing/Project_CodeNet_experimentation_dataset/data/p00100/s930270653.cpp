#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;

int n,N;
ll s[4000][2],a,b;
string d;

int main(){
    while(cin>>N){
	if(N==0)return 0;
	for(int i=0;i<4000;i++){
	    for(int j=0;j<2;j++){
		s[i][j]=0;
	    }
	}
	int m=0;
	for(int i=0;i<N;i++){
	    cin>>n>>a>>b;
	    int flag=0;
	    for(int j=0;j<m;j++)if(s[j][0]==n){s[j][1]+=a*b;flag=1;}
	    if(flag==0){s[m][0]=n;s[m][1]=a*b;m++;}
	}
	int flag2=0;
	for(int i=0;i<m;i++)if(s[i][1]>999999){cout<<s[i][0]<<endl;flag2=1;}
	if(flag2==0)cout<<"NA"<<endl;
    }
}