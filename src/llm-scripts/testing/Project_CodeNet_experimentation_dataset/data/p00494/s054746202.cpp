#include <iostream>
using namespace std;
int main(void){
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='J'){
			int JOI[3]={1,0,0};
			while(s[i]=='J'){++JOI[0];++i;}
			while(s[i]=='O'){++JOI[1];++i;}
			while(s[i]=='I'){++JOI[2];++i;}
			if(JOI[0]>=JOI[1] && JOI[2]>=JOI[1]){
				if(k<JOI[1]) k=JOI[1];
			}
		}
	}
	cout<<k<<endl;
	return 0;
}