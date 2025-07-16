#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n, k;
	while(cin >> n >> k && (n || k)){
		int card[10] = {0};
		map<string, int> m;
		for(int i = 0; i < n; ++i)
			cin >> card[i];
			
		int ans = 0;
		if(k == 2){
			for(int i = 0; i < n; ++i){
				for(int j  = 0; j < n; ++j){
					if(i == j)
						continue;
					string str = to_string(card[i]) + to_string(card[j]);
					if(m[str] == 0){
						ans++;
						m[str] = 1;
					}
				}
			}
		}
		else if(k == 3){
			for(int i = 0; i < n; ++i){
				for(int j  = 0; j < n; ++j){
					if(i == j)
						continue;
					for(int k = 0; k < n; ++k){
						if(i == k || j == k)
							continue;
						string str = to_string(card[i]) + to_string(card[j]) + to_string(card[k]);
						if(m[str] == 0){
							ans++;
							m[str] = 1;
						}
					}
				}
			}
		}
		else if(k == 4){
			for(int i = 0; i < n; ++i){
				for(int j  = 0; j < n; ++j){
					if(i == j)
						continue;
					for(int k = 0; k < n; ++k){
						if(i == k || j == k)
							continue;
						for(int l = 0; l < n; ++l){
							if(i == l || j ==l ||  k == l)
								continue;
							string str = to_string(card[i]) + to_string(card[j]) + to_string(card[k]) + to_string(card[l]);
				 			if(m[str] == 0){
								ans++;
								m[str] = 1;
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}