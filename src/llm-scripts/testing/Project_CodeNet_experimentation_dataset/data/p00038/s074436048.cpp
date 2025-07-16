#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int> > que;
	string ss;
	int c[5];
	while(scanf("%d,%d,%d,%d,%d",&c[0],&c[1],&c[2],&c[3],&c[4])!=EOF){
		int dt[14];
		for(int i=0;i<14;i++){
			dt[i]=0;
		}
		for(int i=0;i<5;i++){
			que.push(c[i]);
		}
		while(!que.empty()){
			for(int i=1;i<=13;i++){
				if(que.top()==i)dt[i]++;
			}
			que.pop();
		}
		int onepair=0,threecard=0,straight=0,fourcard=0;
		for(int i=1;i<14;i++){
			if(dt[i]==2)onepair++;
			if(dt[i]==3)threecard++;
			if(dt[i]==4)fourcard++;
		}
		for(int i=5;i<14;i++){
			if(dt[i-4]==1 && dt[i-3]==1 && dt[i-2]==1 && dt[i-1]==1 &&dt[i]==1)straight++;
			if(i==13){
				if(dt[10]==1 && dt[11]==1 && dt[12]==1 && dt[13]==1 &&dt[1]==1)straight++;
			}
		}
		if(onepair==1){
			if(threecard==1)cout<<"full house"<<endl;
			else cout<<"one pair"<<endl;
		}
		else if(onepair==2)cout<<"two pair"<<endl;
		else if(threecard==1){
			if(onepair==1)cout<<"full house"<<endl;
			else cout<<"three card"<<endl;
		}
		else if(fourcard==1)cout<<"four card"<<endl;
		else if(straight==1)cout<<"straight"<<endl;
		else cout<<"null"<<endl;
	}
	return 0;
}