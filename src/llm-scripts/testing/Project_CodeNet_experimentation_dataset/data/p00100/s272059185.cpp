#include <iostream>
#include <vector>
#include <algorithm> 
#include <map> 
using namespace std;




int main(){
	int n;
	cin >> n;

	while(n != 0){
		vector < pair<long long, long long> > v(n);
		int order[n];
		int num = 0;
		for (int i = 0; i < n; ++i){
			long long id, p, q;
			cin >> id >> p >> q;
			v[i] = make_pair(id, p * q);
			order[i] = id;
		}

		sort(v.begin(), v.end());
		int c = 1;

		for (int i = 0; i < n - 1; ++i){
			if(v[i].first != v[i+1].first){
				c++;
			}
		}

		vector < pair<long long, long long> > sum(c);
		int k = 0;
		for (int i = 0; i < c; ++i){
			sum[i] = make_pair(0, 0);
		}

		long long s = 0;
		for (int i = 0; i < n ; ++i){
			s += v[i].second;
			if(i < n - 1){
				if(v[i].first != v[i+1].first){
					sum[k] = make_pair(v[i].first, s);
					s = 0;
					k++;
				}
			}else{
				sum[k] = make_pair(v[i].first, s);
			}
		}

		int ids[c];
		for (int i = 0; i < c; ++i){
			if(sum[i].second >= 1000000){
				ids[num] = sum[i].first;
				num++;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < num; j++){
				if(order[i] == ids[j]){
					cout << order[i] << endl;
					ids[j] = -10000;
				}
			}
		}

		if(num == 0){
			cout << "NA" << endl;
		}

		cin >> n;
	}

	return 0;
}