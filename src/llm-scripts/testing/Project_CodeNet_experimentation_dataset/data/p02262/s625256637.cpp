#include <bits/stdc++.h>
using namespace std;

int insertionSort(vector<int> &A, int N, int g, int &cnt){
  for(int i = g; i < N; i++){
    int v = A.at(i);
    int j = i - g;
    while(j >= 0 && A.at(j) > v){
      A.at(j+g) = A.at(j);
      j = j - g;
      cnt++;
    }
    A.at(j+g) = v;
  }
}

void shellSort(vector<int> &A, int N){

  int cnt = 0;
  int m;
  vector<int> G(100);

  for(int i = 0; i < 100; i++){
    if(i == 0){
      G.at(i) = N / 2 + 1;
    }
    else{
      G.at(i) = G.at(i-1) / 2 - 1;
    }
    if(G.at(i) < 0){
      G.at(i-1) = 1;
      G.at(i) = 0;
      m = i;
      break;
    }
  }
  for(int i = 0; i < m; i++){
    insertionSort(A, N, G.at(i), cnt);
  }

  cout << m << endl;
  for(int i = 0; i < m; i++){
    if(i) cout << " ";
    cout << G.at(i);
  }
  cout << endl << cnt << endl;
  for(int i = 0; i < N; i++){
    cout << A.at(i) << endl;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> R(n);

  for(int i = 0; i < n; i++){
    cin >> R.at(i);
  }

  shellSort(R, n);

  return 0;
}

