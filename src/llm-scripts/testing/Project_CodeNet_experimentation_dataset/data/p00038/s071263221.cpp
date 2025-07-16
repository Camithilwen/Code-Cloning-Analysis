#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
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

vector<string> split_naive(const string &s, char delim) {
	vector<string> elems;
	string item;
	for(char ch:s){
		if(ch==delim){
			if(!item.empty()) elems.push_back(item);
			item.clear();
		}
		else{
			item += ch;
		}
	}
	if(!item.empty()) elems.push_back(item);
	return elems;
}

int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	
	string S;
	while(cin>>S){
		auto SS=split_naive(S,',');
		vector<int> C(5);
		map<int,int> M;
		REP(i,5){
			sscanf(SS[i].c_str(),"%d",&C[i]);
			M[C[i]]++;
		}
		sort(ALL(C));
		
		int two=0,three=0,four=0;
		for(auto& x:M){
			if(x.second==2) two++;
			else if(x.second==3) three++;
			else if(x.second==4) four++;
		}
		if(four){
			out("four card");
		}
		else if(three){
			if(two){
				out("full house");
			}
			else{
				out("three card");
			}
		}
		else if(two){
			if(two==2){
				out("two pair");
			}
			else{
				out("one pair");
			}
		}
		else{
			bool straight = true;
			if(C[0]==1){
				if(C[1]==2 || C[1]==10){
					for(int i=1;i<4;i++){
						if(C[i+1]!=C[i]+1){
							straight = false;
							break;
						}
					}
				}
				else{
					straight = false;
				}
			}
			else{
				REP(i,4){
					if(C[i+1]!=C[i]+1){
						straight = false;
						break;
					}
				}
			}
			if(straight){
				out("straight");
			}
			else{
				out("null");
			}
		}
	}
	return 0;
}
