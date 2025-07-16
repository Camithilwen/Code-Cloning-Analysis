#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<cmath>
#include<ctime>
#include<complex>

using namespace std;

#define REP(i,s,e) for(int i=int(s);i<=int(e);i++)
#define rep(i,n) for(int i=0;i<int(n);i++)

int f(int n){
	if(n==0) return 1;
	else return 10*f(n-1);
}

int main(){

	int n,k;
	while(1){

		cin >> n >> k;
		if(n==0 && k==0) break;

		vector<int>card(n);
		rep(i,n) cin >> card[i];

		if(k==2){
			vector<int>u;
			rep(i,n){
				rep(j,n){
				  if(i!=j){
					  vector<int>v;
					  if(card[i]/10!=0) v.push_back(card[i]/10);
					                    v.push_back(card[i]%10);
					  if(card[j]/10!=0) v.push_back(card[j]/10);
										v.push_back(card[j]%10);

					  int s=v.size(); int p=0;
					  rep(i,s) p+=v[i]*f(s-1-i);
					  u.push_back(p);
					  v.clear();
				   }
				}
			}

			sort(u.begin(),u.end());
			vector<int>::iterator it=unique(u.begin(),u.end());
			u.erase(it,u.end());

			cout << u.size() << endl;

			u.clear();
		}

		if(k==3){
			vector<int>u;
			rep(i,n){
				rep(j,n){
					rep(k,n){
				  if(i!=j && i!=k && j!=k){
					  vector<int>v;
					  if(card[i]/10!=0) v.push_back(card[i]/10);
					                    v.push_back(card[i]%10);
					  if(card[j]/10!=0) v.push_back(card[j]/10);
										v.push_back(card[j]%10);
					  if(card[k]/10!=0) v.push_back(card[k]/10);
										v.push_back(card[k]%10);

					  int s=v.size(); int p=0;
					  rep(i,s) p+=v[i]*f(s-1-i);
					  u.push_back(p);
					  v.clear();
				   }
				}
			}
		}
			sort(u.begin(),u.end());
			vector<int>::iterator it=unique(u.begin(),u.end());
			u.erase(it,u.end());

			cout << u.size() << endl;

			u.clear();
		}

		if(k==4){
			vector<int>u;
			rep(i,n){
				rep(j,n){
					rep(k,n){
						rep(l,n){
				  if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
					  vector<int>v;
					  if(card[i]/10!=0) v.push_back(card[i]/10);
					                    v.push_back(card[i]%10);
					  if(card[j]/10!=0) v.push_back(card[j]/10);
										v.push_back(card[j]%10);
					  if(card[k]/10!=0) v.push_back(card[k]/10);
										v.push_back(card[k]%10);
					  if(card[l]/10!=0) v.push_back(card[l]/10);
										v.push_back(card[l]%10);

					  int s=v.size(); int p=0;
					  rep(i,s) p+=v[i]*f(s-1-i);
					  u.push_back(p);
					  v.clear();
				   }
				}
			}
		}
	}
			sort(u.begin(),u.end());
			vector<int>::iterator it=unique(u.begin(),u.end());
			u.erase(it,u.end());

			cout << u.size() << endl;

			u.clear();
		}

	}

	return 0;
}