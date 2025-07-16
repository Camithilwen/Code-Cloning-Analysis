#include<iostream>
#include<vector>
using namespace std;

int m;
int g[1000000];
int cnt=0;
std::vector<int> G;
void insertionSort(int array[], int n, int g){
	int tmp,j;
	for(int i=g;i<n;i++){
		tmp = array[i];
		j= i-g;
		while(j>=0 && array[j]>tmp){
			array[j+g] = array[j];
			j=j-g;
			cnt++;
		}
		array[j+g]=tmp;
	}
}

void shellSort(int array[],int n){
	cnt = 0;

	for(int h=1; ;){
		if(h>n) break;
		G.push_back(h);
		h = 3 * h + 1;
	}

	for(int i=G.size()-1;i>=0;i--){
		insertionSort(array,n,G[i]);
	}
}

int main(){
	int n;
	int array[1000001];
	cin >> n;

	for(int i=0;i<n;i++){
		cin >>array[i];
	}

	shellSort(array,n);

	cout << G.size() << endl;
	for(int i=G.size()-1;i>=0;i--){
		cout<<G[i];
		if(i) cout<<" ";
	}
	cout << endl;

	cout << cnt << endl;

	for(int i=0;i<n;i++){
		cout << array[i]<<endl;
	}

	return 0;
}