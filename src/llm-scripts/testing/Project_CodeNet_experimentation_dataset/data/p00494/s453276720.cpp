#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<vector>

#include<queue>

#include<string>


using namespace std;


string str;


int main(void){
	cin >> str;
	int jc=0,oc=0,ic=0,res=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='J'){
			if(oc>0 || ic>0)jc=0;
			oc=0,ic=0;
			jc++;
		}
		if(str[i]=='O'){
			oc++;
			if(ic>0)jc=0;
			ic=0;
		}
		if(str[i]=='I'){
			ic++;
			if(min(jc,ic)>=oc)res=max(res,min(jc,min(oc,ic)));
		}
	}
	printf("%d\n",res);

	return 0;

}