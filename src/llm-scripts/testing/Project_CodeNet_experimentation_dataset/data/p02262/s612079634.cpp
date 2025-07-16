#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long cnt;

void print(vector<int> &data){
	for (int i = 0; i < data.size(); ++i){
		cout << data[i] << endl;
	}
}

void insertSort(vector<int> &data, int d){
	int n = data.size();
	for (int i = d; i < n; ++i) {
		int v = data[i];
		int j = i - d;
		while (j >= 0 && data[j] > v) {
			data[j + d] = data[j];
			j -= d;
			cnt++;
		}
		data[j + d] = v;
	}
}

void insertSort2(vector<int> &data, int d){
	int n = data.size();
	for (int i = d; i < 2 * d; ++i) {
		int v = data[i];
		int j = i - d;
		while (data[j] > v) {
			data[j + d] = data[j];
			j -= d;
			cnt++;
		}
		data[j + d] = v;
	}
}

void shellSort(vector<int> &data){
	vector<int> dist;
	for (int i = 1; i <= data.size(); i = 3 * i + 1)
		dist.push_back(i);

	int n = dist.size();
	cout << n << endl;

	for (int i = n - 1; i >= 0; --i)
	{
		insertSort(data, dist[i]);
		cout << dist[i];
		if (i != 0) cout << " ";
		else cout << endl;
	}
	cout << cnt << endl;
	print(data);
}


int main(){
	int n; cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) cin >> data[i];

	shellSort(data);

	return 0;
}