#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
using namespace std;

int main(){
	int N;cin >> N;

	int ans=0;
	for(int i=3;i<N;i++){
		ans=max(ans, N/i);
	}
	cout << ans << endl;
}
