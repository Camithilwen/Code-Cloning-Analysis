#include <bits/stdc++.h>
using namespace std;

class Fruit {
  public:
    string name;
    double efficiency;
    Fruit(string _name, double _efficiency):
      name(_name),
      efficiency(_efficiency) {
    }
};

int main() {
  int N;
  while(cin >> N, N) {
    vector<Fruit> fruits;
    for(int n = 0; n < N; ++n) {
      string name;
      cin >> name;
      int seedCost;
      cin >> seedCost;
      int aTime = 0;
      int aFromLeafTime = 0;
      for(int i = 0; i < 5; ++i) {
        int t;
        cin >> t;
        aTime += t;
        if(i > 2) aFromLeafTime += t;
      }
      int nfruit;
      cin >> nfruit;
      int aFruitPrice;
      cin >> aFruitPrice;
      int ngrow;
      cin >> ngrow;
      int tTime;
      tTime = aTime + aFromLeafTime * (ngrow - 1);
      int price;
      price = aFruitPrice * nfruit * ngrow;
      int income;
      income = price - seedCost;
      double efficiency;
      efficiency = (double)income / (double)tTime;
      Fruit fruit(name, efficiency);
      fruits.push_back(fruit);
    }
    sort(fruits.begin(), fruits.end(), [](Fruit left, Fruit right) {
      if(left.efficiency == right.efficiency) return left.name < right.name;
      return left.efficiency > right.efficiency;
    });
    for(int i = 0; i < N; ++i) cout << fruits[i].name << endl; //cout << fruits[i].name << " " << fruits[i].efficiency << endl;
    cout << '#' << endl;
  }
  return 0;
}