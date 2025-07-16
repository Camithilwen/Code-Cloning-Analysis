#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n,k,a[10],power[6];
vector<string>vec;
int main(){
	while(true){
		cin>>n>>k;vec.clear();power[0]=1;for(int i=1;i<5;i++)power[i]=power[i-1]*n;
		if(n==0 && k==0)break;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<power[k];i++){
			int bit[4];for(int j=0;j<k;j++)bit[j]=(i/power[j])%n;
			bool OK=true;
			if(k==2 && (bit[0]==bit[1]))OK=false;
			if(k==3 && (bit[0]==bit[1] || bit[0]==bit[2] || bit[1]==bit[2]))OK=false;
			if(k==4 && (bit[0]==bit[1] || bit[0]==bit[2] || bit[1]==bit[2]))OK=false;
			if(k==4 && (bit[0]==bit[3] || bit[1]==bit[3] || bit[2]==bit[3]))OK=false;
			if(OK==true){
				string S="";
				for(int j=0;j<k;j++)S+=to_string(a[bit[j]]);
				vec.push_back(S);
			}
		}
		sort(vec.begin(),vec.end());int cnt=1;
		for(int i=1;i<vec.size();i++){
			if(vec[i-1]!=vec[i])cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}