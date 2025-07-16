#include<iostream>
#include<vector>
using namespace std;

struct Answer
{
	int m;
	vector<int> G;
	int cnt;
};

void insertionSort(vector<int> &A, int &g, int &cnt)
{
	for(int i = g; i < A.size(); i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
}

vector<int> FindShellSortNumber(int n)
{
	int g = 1;
	vector<int> G;
	while(g <= n){
		G.push_back(g);
		g = 3 * g + 1;
	}
	int size = G.size();
	for(int i = 1; i <= size / 2; i++){
		swap(G[i-1], G[size-i]);
	}
	return G;
}

Answer shellSort(vector<int> &A)
{
	Answer Result;
	Result.cnt = 0;
	Result.G   = FindShellSortNumber(A.size());
	Result.m   = Result.G.size();
	for(int i = 0; i < Result.m; i++){
		insertionSort(A, Result.G[i], Result.cnt);
	}
	return Result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> A;
	A.resize(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	Answer Result = shellSort(A);
	cout << Result.m << endl;
	for(int i = 0; i < Result.G.size() - 1; i++){
		cout << Result.G[i] << ' ';
	}
	cout << Result.G[Result.G.size() - 1] << endl;
	cout << Result.cnt << endl;
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << endl;
	}
	return 0;
}