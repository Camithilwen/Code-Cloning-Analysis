#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1010;

int h, w, a, b, mat[N][N];
ii arr[N];

bool can(int c1, int c2){
	for(int i=0 ; i<c2 ; i++)
		arr[i] = ii(b, i);
	for(int i=c2 ; i<w ; i++)
		arr[i] = ii(h-b, i);
	sort(arr, arr+w);
	memset(mat, 0, sizeof mat);
	for(int i=h-1 ; i>=0 ; i--){
		int cur = (i >= c1 ? w-a : a);
		for(int j=w-1 ; cur>0 && j>=0 ; j --, cur --){
			arr[j].first --;
			if(arr[j].first<0)
				return false;
			mat[i][ arr[j].second ] = 1;
		}
		sort(arr, arr+w);
	}
	for(int i=0 ; i<h ; i++){
		for(int j=0 ; j<w ; j++)
			cout << mat[i][j];
		cout << "\n";
	}
	return true;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w >> a >> b;
	for(int i=0 ; i<=h ; i++)
		for(int j=0 ; j<=w ; j++){
			int f1 = i*a + (h-i)*(w-a);
			int f2 = j*b + (w-j)*(h-b);
			if(f1 == f2 && can(i, j))
				return 0;
		}
	cout << "-1\n";
}














