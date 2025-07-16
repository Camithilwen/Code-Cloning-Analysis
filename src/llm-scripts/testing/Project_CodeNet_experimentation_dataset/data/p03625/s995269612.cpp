#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

long long N;
map<long long, long long> mp;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N ;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		if(mp.count(a)==0){
			mp[a] = 1;
		}
		else{
			mp[a]++;
		}
	}
	vector<pair<long long, long long>> v;

	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		long long k = itr->first;
		long long u = itr->second;
		v.push_back(make_pair(k, u));
	}

	sort(v.begin(), v.end());
	int found = 0;
	long long ans = 0;
	for(int i=v.size()-1; i>=0; i--){
		if(v[i].second < 2) continue;
		if(v[i].second >=4){
			if(found == 2){
				ans = ans*(v[i].first);
			}
			else{
				ans = (v[i].first)*(v[i].first);
			}
			found = 4;
			break;
		}
		if(v[i].second == 2 || v[i].second == 3){
			found += 2;
			if(found == 4){
				ans = ans * v[i].first;
				break;
			}
			else{
				ans = v[i].first;
			}
		}
		
	}
	if(found < 4) ans = 0;
	printf("%lld\n", ans);
	return 0;
}