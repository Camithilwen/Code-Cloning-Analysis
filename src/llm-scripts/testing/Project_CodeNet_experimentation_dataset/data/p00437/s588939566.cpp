#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int a,b,c,N;
	while(cin >> a >> b >> c && a){
		cin >> N;
		vector< vector<int> > v(N,vector<int>(4));
		vector<int> chk(a+b+c,2);
		
		rep(i,N){
			rep(j,4){
				cin >> v[i][j];
				if(j!=3)v[i][j]--;
			}
		}
		rep(i,N){
			if(v[i][3] == 1){
				rep(j,3) chk[v[i][j]] = 1;
			}
		}
		rep(i,N){
			if(v[i][3] == 0){
				rep(j,3){
					if(chk[v[i][j]] == 2){
						int c = 0;
						rep(k,3)c += chk[v[i][k]] == 1;
						if(c==2)chk[v[i][j]] = 0;
					}
				}
			}
		}
		rep(i,a+b+c) cout << chk[i] << endl;
		
	}
}