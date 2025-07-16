#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


int main(int argc, char *argv[]) {

	int A,B; cin >> A >> B;
	int skt = 1;
	int ans = 0;
	while(B > skt) {
		skt--;
		skt += A;	
		ans++;
	}
	cout << ans << endl;
	

	return 0;
}
