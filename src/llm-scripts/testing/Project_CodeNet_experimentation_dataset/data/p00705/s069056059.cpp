#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int nMember, nNeedMember;
  while(cin >> nMember >> nNeedMember, nMember | nNeedMember) {
    vector<int> dates(100, 0); //one base
    for(int i = 0; i < nMember; ++i) {
      int ndate;
      cin >> ndate;
      for(int j = 0; j < ndate; ++j) {
        int date;
        cin >> date;
        ++dates[date];
      }
    }
    auto max_itr = max_element(dates.begin(), dates.end());
    cout << ((*max_itr >= nNeedMember) ? distance(dates.begin(), max_itr) : 0) << endl;
  }
  return 0;
}