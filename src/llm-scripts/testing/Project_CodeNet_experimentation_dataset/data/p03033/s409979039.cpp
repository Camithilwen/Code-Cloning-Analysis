#include <cstdio>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<tuple<int, int, int>> event;
	for(int i = 0; i < N; i++) {
		int s, t, x;
		scanf("%d %d %d", &s, &t, &x);
		event.push_back(make_tuple(s-x, 1, x));
		event.push_back(make_tuple(t-x, -1, x));
	}
	
	vector<int> D(Q);
	for(int i = 0; i < Q; i++) scanf("%d", &D[i]);
	
	sort(event.begin(), event.end());
	multiset<int> st;
	int k = 0;  //何番目のイベントまで処理したか
	for(int i = 0; i < Q; i++) {
		while(k < event.size() && get<0>(event[k]) <= D[i]) {
			if(get<1>(event[k]) == 1) {
				st.insert(get<2>(event[k]));
			} else {
				auto it = st.find(get<2>(event[k]));
				if(it != st.end()) st.erase(it); //1つだけ削除
			}
			k++;
		}
		
		if(st.empty()) printf("-1\n");
		else printf("%d\n", *st.begin());
	}
	
	return 0;
}