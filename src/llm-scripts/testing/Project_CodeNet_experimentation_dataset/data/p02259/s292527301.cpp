#include <iostream>

using namespace std;

int bubblesort(int A[], int N) {
  int count = 0;
  int flag = 1;

  while (flag) {
    flag = 0;
    for (int i = N-1; i > 0; i--) {
      if (A[i] < A[i-1]) {
	swap(A[i], A[i-1]);
	flag = 1;
	count++;
      }
    }
  }
  
  for (int j = 0; j < N; j++) {
    if (j != N -1) cout << A[j] << " ";
    else cout <<A[j] << "\n";
 
  }

  cout << count << "\n";
}

int main() {
  
  int A[100];
  int N;

  cin >> N;

  for (int i=0; i < N; i++) {
    cin >> A[i];
  }

  bubblesort(A, N);
  return 0;
}