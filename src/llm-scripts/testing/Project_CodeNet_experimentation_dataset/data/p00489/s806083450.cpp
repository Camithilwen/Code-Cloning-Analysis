#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;
	int table[101][101] = {0};
	for(int i=0 ; i < n*(n-1)/2 ; i++ ){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		int s1, s2;
		if( c > d ){ 
			s1 = 3;
			s2 = 0;
		}else if( c == d ){
			s1 = s2 = 1;
		}else{
			s1 = 0;
			s2 = 3;
		}
		table[a][b] = s1;
		table[b][a] = s2;
	}
	vector<P> v;
	int score[101] = {0};
	for(int i=0 ; i < n ; i++ ){
		for(int j=0 ; j < n ; j++ ){
			if( i == j ) continue;
			score[i] += table[i][j];
		}
		v.push_back( P(-score[i],i) );
	}
	sort( v.begin() , v.end() );
	int rank[101] = {0};
	rank[ v[0].second ] = 1;
	for(int i=1 ; i < v.size() ; i++ ){
		rank[ v[i].second ] = ( v[i].first == v[i-1].first )? rank[ v[i-1].second ] : i+1;
	}
	for(int i=0 ; i < n ; i++ ){
		cout << rank[i] << endl;
	}
}