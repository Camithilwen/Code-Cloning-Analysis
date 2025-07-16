#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef  long long ll;
ll gcd(ll f , ll s){if(s==0)return f;else return gcd(s,f%s);}
int const N = 1000006;
ll const M = 998244353;
long double const ep = .000000000000000001;
int p[N];
queue<int>q;
ll Farray[1032][1032] , Sarray[1032][1023] , arr[1002][1003];
int main() {
	
	int n;cin >> n;
	if(n==2){
		cout << 4 << " " << 7 << endl << 23 << " " << 10 ;
		return 0;
	}
	for(int i = 2 ; i <= 1000 ; i++){
		if(!p[i]){
			for(int x = i + i; x <= 100000 ; x+=i)p[x] = 1;
		}
	}	
	for(int i = 2 ; i <= 100000 ; i++)if(!p[i])q.push(i);
	pair<int,int>start = mp(0,0);
	for(pair<int,int> i = start ; i.first < n ; i.first += 2){
		int currP = q.front();
		q.pop();
		for(pair<int,int> x = i ; x.first < n && x.second < n ; x.first++ , x.second++){
			Farray[x.first][x.second] = currP;
		}
	}
	for(pair<int,int> i = mp(0,2) ; i.second < n ; i.second += 2){
		int currP = q.front();
		q.pop();
		for(pair<int,int> x = i ; x.first < n && x.second < n ; x.first++ , x.second++){
			Farray[x.first][x.second] = currP;
		}
	}
	
	for(pair<int,int> i = start ; i.second < n ; i.second += 2){
		int currP = q.front();
		q.pop();
		for(pair<int,int> x = i ; x.first < n && x.second >= 0 ; x.first++ , x.second--){
			Sarray[x.first][x.second] = currP;
		}
	}

	for(pair<int,int> i = mp(1+(n%2),n-1) ; i.first < n ; i.first += 2){
		int currP = q.front();
		q.pop();
		for(pair<int,int> x = i ; x.first < n && x.second >= 0 ; x.first++ , x.second--){
			Sarray[x.first][x.second] = currP;
		}
	}


	for(int i = 0 ; i < n ; i++)
		for(int x = 0 ; x < n ; x++)
			arr[i][x] = Farray[i][x] * Sarray[i][x];
	for(int i=0 ; i< n ; i++){
		for(int j=0 ; j< n ; j++){
			if((i + j)%2== 1){
				set<ll>s;
				if(i != 0){
					s.insert(Farray[i-1][j]);
					s.insert(Sarray[i-1][j]);
				}
				if(i != n-1){
					s.insert(Farray[i+1][j]);
					s.insert(Sarray[i+1][j]);
				}
				if(j != 0){
					s.insert(Farray[i][j-1]);
					s.insert(Sarray[i][j-1]);
				}
				if(j != n-1){
					s.insert(Farray[i][j+1]);
					s.insert(Sarray[i][j+1]);
				}
				arr[i][j] = 1;
				set<ll>::iterator it = s.begin();
				for(;it!=s.end() ; it++)arr[i][j]*= *(it);
				arr[i][j]++;
			}
		}
	}
	for(int i=0 ; i< n ; i++){
		for(int j=0 ; j< n ; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;	
}