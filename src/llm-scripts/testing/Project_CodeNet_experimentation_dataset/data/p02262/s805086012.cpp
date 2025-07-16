#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int cnt = 0;
int a[1000500];

void insertsort(int a[], int n, int g){
	for (int i = g; i < n; i++){
		int v = a[i];
		int j = i - g;
		while (j >= 0 && a[j] > v){
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}

int main(void)
{
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	// 3g + 1
	vector <int> kotori;
	for (int g = 1; g <= n; g = 3 * g + 1){
		kotori.push_back(g);
	}

	for (int i = kotori.size() - 1; i >= 0; i--){
		insertsort(a, n, kotori[i]);
	}
	
	reverse(kotori.begin(), kotori.end());
	cout << kotori.size() << endl;
	for (int i = 0; i < kotori.size(); i++){
		cout << kotori[i] << (i + 1 == kotori.size() ? '\n' : ' ');
	}
	cout << cnt << endl;

	for (int i = 0; i < n; i++){
		cout << a[i] << endl;
	}

	return 0;
}