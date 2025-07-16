#include<cstdio>
#include<vector>
using namespace std;

int insSort(vector<int> &arr, int g) {
	int	v, cnt;

	cnt = 0;
	for(int i=g; i<arr.size(); ++i) {
		int j;
		v = arr[i];
		for(j=i-g; j>=0 && arr[j]>v; j-=g) {
			arr[j+g] = arr[j];
			++cnt;
		}
		arr[j+g] = v;
	}
	return cnt;
}

int main() {
	int	n, tmp, m, cnt;
	vector<int>	arr, G;

	scanf("%d", &n);
	arr.reserve(n);

	for(int i=0; i<n; ++i) {
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	tmp = 4;
	G.push_back(1);
	for(m=1; tmp<n; ++m) {
		G.push_back(tmp);
		tmp = 3 * tmp + 1;
	}

	cnt = 0;
	for(auto it=G.rbegin(); it!=G.rend(); ++it) {
		cnt += insSort(arr, *it);
	}

	printf("%d\n", m);
	for(auto it=G.rbegin(); it!=--(G.rend()); ++it) {
		printf("%d ", *it);
	}
	printf("%d\n", G[0]);
	printf("%d\n", cnt);
	for(auto it=arr.begin(); it!=arr.end(); ++it) {
		printf("%d\n", *it);
	}
}