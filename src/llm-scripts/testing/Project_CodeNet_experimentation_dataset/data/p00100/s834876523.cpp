#include <iostream>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;
int main (int argc, char const* argv[]) {
  int N, id, price, num;
  const ll LIMIT = 1000000LL;
  while (true) {
    cin >> N;
    if (N == 0) break;
    map<int,pair<bool,ll> > dict;
    vector<int> id_list;
    for (int i = 0; i < N; i += 1) {
      cin >> id >> price >> num;
      ll tmp = (ll)price * (ll)num;
      // New
      if (dict.count(id) == 0) {
        if (LIMIT <= tmp) {
          dict.insert(make_pair(id,make_pair(true,0)));
        } else {
          dict.insert(make_pair(id,make_pair(false,tmp)));
        }
        id_list.push_back(id);
      // Add
      } else {
        if (dict[id].first) continue;
        if (LIMIT <= tmp + dict[id].second) {
          dict[id].first = true;
        } else {
          dict[id].second += tmp;
        }
      }
    }
    // Print
    bool printed = false;
    for (int i = 0; i < id_list.size(); i += 1) {
      if (dict[id_list[i]].first) {
        cout << id_list[i] << endl;
        printed = true;
      }
    }
    if (!printed) cout << "NA" << endl;
  }
  return 0;
}