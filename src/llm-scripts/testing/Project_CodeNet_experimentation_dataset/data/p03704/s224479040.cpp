#include<bits/stdc++.h>
#include<vector>
#define LL long long
#define PI pair<LL,LL>
using namespace std;
LL D,St1[25],St2[25],P[25],Last[25],Ans;
vector<LL>V;
void DFS(LL L,LL R,LL Val,LL Cnt){
	if(L==R){
		Ans+=(Val==D)*Cnt;
		return; 
	}
	if(abs(Val-D)>Last[L]*10) return;
	for(LL I=-9;I<=9;I++){
		LL Ways=((L==0)?St2[I+10]:St1[I+10]);
		if(V[L]==0) Ways=(I<=0);
		if(Ways==0) continue;
		DFS(L+1,R,Val+I*V[L],Cnt*Ways);
	} 
}
void Solve(LL Len){
	V.clear();
	for(LL I=0;Len-I-1>=I;++I) V.push_back(P[Len-I-1]-P[I]);
	vector<PI>An1,An2;
	for(LL I=V.size()-1;I>-1;--I) Last[I]=Last[I+1]+V[I]; 
	DFS(0,V.size(),0,1);
}
int main(){
    scanf("%lld",&D);
    P[0]=1;
    for(LL I=1;I<=18;I++) P[I]=P[I-1]*10;
    for(LL I=0;I<=9;I++)
    	for(LL J=0;J<=9;J++){
    		St1[I-J+10]++;
			if(I&&J) St2[I-J+10]++;	
		}
	for(LL I=1;I<=18;I++) Solve(I);
	printf("%lld",Ans);
	return 0;
}
