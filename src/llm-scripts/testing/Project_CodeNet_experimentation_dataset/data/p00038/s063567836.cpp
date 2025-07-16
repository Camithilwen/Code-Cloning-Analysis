#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;


int main(void){

int cd[5]={0},cnt=0;

char k;
	while(!cin.eof()){
		cin >> cd[0] >> k >>cd[1] >>k >>cd[2] >>k >>cd[3] >>k >>cd[4];
		if(cin.eof()) break;
		
		sort(cd,cd+5);
		int mxp=0,cn1,cn2=0;
		rep(i,5){
			cn1=0;
			rep2(j,i+1,5) if(cd[i]==cd[j]) cn1++;
			cn2 += cn1; 
			mxp = max(mxp,cn1);
		}
//		printf("%d,%d\n",mxp,cn2);
		string yak = "straight";
		rep(i,4) if(cd[i] +1 != cd[i+1]) yak="null";
		if(cd[0]==1 && cd[1]==10 && cd[2]==11 && cd[3]==12 && cd[4]==13)
					yak = "straight";
		if(mxp==1 && cn2==1) yak ="one pair";
		if(mxp==1 && cn2==2) yak ="two pair";
		if(mxp==2 && cn2==3) yak ="three card";
		if(mxp==2 && cn2==4) yak ="full house";
		if(mxp==3) yak ="four card";
		cout << yak << endl;
		cnt++; if(cnt>50) break;
	}	
	
	return 0;
	
	
}