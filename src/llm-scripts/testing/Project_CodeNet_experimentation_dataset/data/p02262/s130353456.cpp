/**************
*	Shell Sort
*************/

#include <iostream>
#include <vector>	//??£?¨?
#include <algorithm>
using namespace std;
typedef vector<int> TList;

void insertionSort(TList* A, int g, int* cnt  ){

	for(unsigned int i=g ; i<(A->size()); i++){
		int v = (*A)[i];
		int j = i-g;
		while(j>=0 && (*A)[j]>v){
			(*A)[j+g] = (*A)[j];
			j = j-g;
			(*cnt)++;
		}
		(*A)[j+g] =v;
	}
	return ;
}
//---------------------------------------------------------
void shellSort(TList* A, TList* G, int* cnt){

	for(unsigned int i=0; i<(G->size()); i++){
		insertionSort(A, (*G)[i], cnt);
	}

	return;
}
//--<<???????????¢??°>>-------------------------------------------------------
int main(){

	//??????????¨????
	cin.tie(0);
	ios::sync_with_stdio(false);
	//??\???
	int n;
	cin >> n;
	vector<int> A;
	A.resize(n);
	for(unsigned int i=0; i< A.size(); i++){
		cin >> A[i];
	}
	
	//??????
	TList G;
//	G.reserve(100);//????????????????´???°???????????£??????????????¨????????????
	int sum = 1;
	while(sum <= n){
	    G.push_back(sum);
		sum = sum * 3 + 1;
	}
	reverse(G.begin(), G.end());

	int cnt = 0;
	shellSort(&A, &G, &cnt);

	//??????
	cout << G.size() << endl;
	for(unsigned int i=0; i<(G.size()); i++){
		cout << G[i];
		if(i!=(G.size()-1)){
			 cout <<" " ;
		}
	}
	cout << endl;
	cout << cnt << endl;
	for(int i=0; i< n; i++){
		cout << A[i]<< endl;
	}

	return 0;
}
//-----------------------------------------------