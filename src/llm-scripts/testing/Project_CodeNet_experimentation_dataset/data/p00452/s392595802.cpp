#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> twoThrow;
	int n;
	int m;
	int point[1000];
	int ans;
	
	while (1){
		twoThrow.clear();
		
		scanf("%d%d", &n, &m);
		
		if (n == 0){
			break;
		}
		
		for (int i = 0; i < n; i++){
			scanf("%d", &point[i]);
		}
		
		
		twoThrow.push_back(0);
		for (int i = 0; i < n; i++){
			twoThrow.push_back(point[i]);
			for (int j = i; j < n; j++){
				twoThrow.push_back(point[i] + point[j]);
			}
		}
		sort(twoThrow.begin(), twoThrow.end());
		
		int t;
		ans = 0;
		for (int i = 0; i < twoThrow.size(); i++){
			vector<int>::iterator it = upper_bound(twoThrow.begin(), twoThrow.end(), m - twoThrow[i]);
			if (it == twoThrow.begin()){
				continue;
			}
			it--;
			t = *it;
			if (ans < t + twoThrow[i]){
				ans = t + twoThrow[i];
			}
		}
		
		printf("%d\n", ans);
	}
	
	return (0);
}