#include <cmath>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void insertion_sort(vector<int> &list, int interval, int &count) {
  for (int i = interval; i < list.size(); ++i) {
    int key = list[i];
    int j = i - interval;
    while (j >= 0 && list[j] > key) {
      list[j+interval] = list[j];
      j = j - interval;
      count++;
    }
    list[j+interval] = key;
  }
}

void shell_sort(vector<int> &list, int &count) {
  int index = max(0, (int)(log10(list.size())/log10(2)) - 1);
  vector<int> intervals;
  while (index >= 0) {
    intervals.push_back(pow(2, index));
    index--;
  }
  cout << intervals.size() << endl;
  for (auto iter = intervals.begin(); iter != intervals.end() - 1; ++iter) {
    cout << *iter << " ";
  }
  cout << intervals.back() << endl;
  for (int interval : intervals) {
    insertion_sort(list, interval, count);
  }
}

int main() {
  int N;
  cin >> N;
  string str;
  vector<int> list;
  for (int i = 0; i < N; ++i) {
    cin >> str;
    list.push_back(stoi(str));
  }

  int count = 0;
  shell_sort(list, count);
  cout << count << endl;
  for (auto iter = list.begin(); iter != list.end(); ++iter) {
    cout << *iter << endl;
  }
}