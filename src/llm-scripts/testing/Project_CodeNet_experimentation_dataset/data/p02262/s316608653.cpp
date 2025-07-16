#include <iostream>
#include <cmath>
using namespace std;

int insertionSort(int a[], int n, int g){
	int cnt = 0;
	for(int i=g;i<n;++i){
		int v = a[i];
		int j = i - g;
		while(j>=0 && a[j]>v){
			a[j+g] = a[j];
			j = j - g;
			++cnt;
		}
		a[j+g] = v;
	}
	return cnt;
}

int* interleavedlist(int n, int *m){
	int i = 1, j = 0;
	*m = log10(2*n+1) / log10(3);
	int *g = new int[*m];
	while(i<=n){
		g[j] = i;
		++j;
		i = 3 * i + 1;
	}
	return g;
}

void shellSort(int a[], int n){
	int cnt = 0;
	int m;
	int *g = interleavedlist(n,&m);
	
	cout<<m<<endl;
	for(int i=m-1;i>=0;--i)cout<<g[i]<<(i?" ":"");
	cout<<endl;
	
	for(int i=m-1;i>=0;--i){
		cnt += insertionSort(a,n,g[i]);
	}
	cout<<cnt<<endl;
}

int main() {
	int n, *data;
	
	cin>>n;
	data = new int[n];
	for(int i=0;i<n;++i){
		cin>>data[i];
	}
	
	shellSort(data,n);
	
	for(int i=0;i<n;++i){
		cout<<data[i]<<endl;
	}
	return 0;
}