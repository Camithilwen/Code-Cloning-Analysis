#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	int p;
	string S;
	int i,k;
	int AC=0;
	int WA=0;

	cin >> N >> M;
	int wrong[N+5]={0};

	for(i=0;i<M;i++){
		cin >> p >> S;
		if(S=="AC" && wrong[p]>=0){
			AC++;
			WA+=wrong[p];
			wrong[p]=-1000000;
		}else{
			wrong[p]++;
		}
	}

	cout << AC << " " << WA << endl;

	return 0;
}

