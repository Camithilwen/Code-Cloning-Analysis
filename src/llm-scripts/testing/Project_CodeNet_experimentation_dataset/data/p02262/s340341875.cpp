
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int swap_count = 0; // number of swaps

void insertion_sort(vector<int> &sort_vec, int n, int interval) {
  for (int i = interval; i < n; ++i) {
    int pivot = sort_vec[i];
    int j = i - interval;
    while (j >= 0 && sort_vec[j] > pivot) { //
      sort_vec[j + interval] = sort_vec[j]; // perform swap
      j = j - interval; // drop by interval
      swap_count++;
    }
    sort_vec[j + interval] = pivot; // put pivot in proper place
  }
}

int main() {
  int n; //number of entries
  cin >> n;

  vector<int> sort_vec;
  //initialize unsorted vector
  for (int i = 0; i < n; ++i) {
    int entry;
    cin >> entry;
    sort_vec.push_back(entry);
  }
  
  vector<int> intervals;
  //initialize array according to formula k_next = 3*k_prev + 1 (Knuth)
  int next = 1;
  while (true) {
    intervals.push_back(next);
    next = next * 3 + 1;
    if (next >= n) break;
  }

  int intervals_size = intervals.size();
  //shell sort
  for (int i = intervals_size - 1; i >= 0; --i) {
    insertion_sort(sort_vec, n, intervals[i]);
  }

  //print results
  cout << intervals_size << endl; // number of intervals
  for (int i = intervals_size - 1; i >= 0; --i) {
    cout << intervals[i];
    if (i <= n - 1) cout << " ";
  }
  cout << endl;
  cout << swap_count << endl; // number of swaps
  for (int i = 0; i < n; ++i) { // sorted vector
    cout << sort_vec[i] << endl;
  }
  
}
    
  
  
  
  
  