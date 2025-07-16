#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string S;
int X[1000005][3];
int z=0;
int y=0;
int main()
{
	cin >> S;
	if(S[0]=='J'){
		X[z][0]++;
		y=0;
	}
	if(S[0]=='O'){
		X[z][1]++;
		y=1;
	}
	if(S[0]=='I'){
		X[z][2]++;
		y=2;
	}
	for(int i=1;i<S.length();i++){
		if(S[i-1]==S[i])X[z][y]++;
		else{
			z++;
			if(S[i]=='J')y=0;
			if(S[i]=='O')y=1;
			if(S[i]=='I')y=2;
			X[z][y]++;
		}
	}
	int ans=0;
	for(int i=0;i<=z;i++){
		if(X[i][0]<X[i+1][1])continue;
		if(X[i+1][1]>X[i+2][2])continue;
		ans=max(ans,X[i+1][1]);
	}
	printf("%d\n",ans);
	return 0;
}