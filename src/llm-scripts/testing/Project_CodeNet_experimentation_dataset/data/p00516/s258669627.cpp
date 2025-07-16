#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n, m, t, i, j;
	scanf("%d %d", &n, &m);

	vector<int> sports;
	vector<int> votes(m, 0);

	for(i = 0;i < n;++i){
		scanf("%d", &t);
		sports.push_back(t);
	}

	for(i = 0;i < m;++i){
		scanf("%d", &t);
		for(j = 0;j < n;++j){
			if(sports[j] <= t){
				votes[j]++;
				break;
			}
		}
	}

	vector<int>::iterator itr = max_element(votes.begin(), votes.end());
	size_t d = distance(votes.begin(), itr);
	printf("%zu\n", d+1);

	return 0;
}
