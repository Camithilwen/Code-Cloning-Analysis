#include <bits/stdc++.h>
using namespace std;

int main(){
	int vote[101];
	int N,Q,M;
	int day;
	int tmp;
	int ans;
	int i,j;
	while(1){
		tmp=0;
		ans=0;
		for(i = 0 ; i < 101 ; i++){
			vote[i]=0;
		}
		cin >> N >> Q;
		if(N == 0 && Q == 0){
			break;
		}
		
		tmp=Q-1;
		
		for(i = 0 ; i < N ; i++){
			cin >> M;
			for(j = 0 ; j < M ; j++){
				cin >> day;
				 vote[day]++;
			}
		}
		for(i = 0 ; i < 101 ; i++){
			if(vote[i] > tmp){
				ans = i;
				tmp = vote[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}