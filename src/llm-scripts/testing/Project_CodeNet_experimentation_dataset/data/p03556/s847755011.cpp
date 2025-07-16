// B - Around Square
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	int64_t ans = 0;
	for(int i=1; i*i<=N; ++i) ans = i*i;
	cout<<ans<<endl;
}
