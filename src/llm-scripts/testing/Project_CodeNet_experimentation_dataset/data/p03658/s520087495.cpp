#include <bits/stdc++.h>

using namespace std;

int main(){

  int N, K ;
  cin >> N >> K;

  int array[N];
  for(int i = 0;i < N ; i++){
    cin >> array[i];
  }

  for(int i = 0;i < N ; i++){
    int max = i;
    for(int j = i+1;j < N;j++){
      if(array[max] < array[j]){
	max = j;

      }

    }
          swap(array[i],array[max]);
  }
  /*for (int i = 0; i < N ;i++){
    cout <<array[i];
    } */
  
  int sum = 0;
  for(int i = 0;i < K;i++){

    sum += array[i];
  }
  
  cout << sum << endl;
    
  return 0;
}
