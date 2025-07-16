#include <algorithm>
#include <iostream>
using namespace std;
static const int MAX = 200000;

static const int sentinel = 1000000000;
long int ninvention = 0;

int merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = sentinel;
  R[n2] = sentinel;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      ninvention += max(0, n1 - i);
      A[k] = R[j];
      j++;
    }
  }
}

int mergeSort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int data[MAX];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }
  mergeSort(data, 0, n);

  cout << ninvention << endl;
}