#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in();
	string S=in<string>();
	string WS[8];
	REP(i,8) WS[i].resize(N,'_');
	REP(i,4) WS[i][0]='S';
	if(S[0]=='o'){
		WS[0][1]='S';
		WS[0][N-1]='S';
		WS[1][1]='W';
		WS[1][N-1]='W';
		REP(i,2) WS[i+2].clear();
	}
	else{
		WS[2][1]='S';
		WS[2][N-1]='W';
		WS[3][1]='W';
		WS[3][N-1]='S';
		REP(i,2) WS[i].clear();
	}
	REP(i,4) WS[i+4][0]='W';
	if(S[0]=='x'){
		WS[4][1]='S';
		WS[4][N-1]='S';
		WS[5][1]='W';
		WS[5][N-1]='W';
		REP(i,2) WS[i+6].clear();
	}
	else{
		WS[6][1]='S';
		WS[6][N-1]='W';
		WS[7][1]='W';
		WS[7][N-1]='S';
		REP(i,2) WS[i+4].clear();
	}
	
	for(int i=1;i<N-2;i++){
		REP(j,8){
			if(WS[j].empty()) continue;
			if(S[i]=='o'){
				if(WS[j][i]=='S') WS[j][i+1]=WS[j][i-1];
				else if(WS[j][i]=='W') WS[j][i+1]=WS[j][i-1]=='W'?'S':'W';
			}
			else{
				if(WS[j][i]=='W') WS[j][i+1]=WS[j][i-1];
				else if(WS[j][i]=='S') WS[j][i+1]=WS[j][i-1]=='W'?'S':'W';
			}
		}
	}

	for(int i=N-2;i<N;i++){
		REP(j,8){
			if(WS[j].empty()) continue;
			if(S[i]=='o'){
				if(WS[j][i]=='S'){
					if((WS[j][i-1]=='S' && WS[j][(i+1)%N]=='W') || (WS[j][i-1]=='W' && WS[j][(i+1)%N]=='S')){
						WS[j].clear();
					}
				}
				else if(WS[j][i]=='W'){
					if((WS[j][i-1]=='S' && WS[j][(i+1)%N]=='S') || (WS[j][i-1]=='W' && WS[j][(i+1)%N]=='W')){
						WS[j].clear();
					}
				}
			}
			else{
				if(WS[j][i]=='S'){
					if((WS[j][i-1]=='S' && WS[j][(i+1)%N]=='S') || (WS[j][i-1]=='W' && WS[j][(i+1)%N]=='W')){
						WS[j].clear();
					}
				}
				else if(WS[j][i]=='W'){
					if((WS[j][i-1]=='S' && WS[j][(i+1)%N]=='W') || (WS[j][i-1]=='W' && WS[j][(i+1)%N]=='S')){
						WS[j].clear();
					}
				}
			}
		}
	}

	for(auto& x:WS){
		if(!x.empty()){
			out(x);
			return 0;
		}
	}

	out(-1);
	return 0;
}
