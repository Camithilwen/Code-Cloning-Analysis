#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findNum(vector<pair<int, long long> > comm, int num) {
    for(int i=0; i<comm.size(); i++)  {
      if(comm[i].first == num) {
	return i;
      }
    }
    return comm.size();
  }

int main() {
  int n;
  cin>>n;
  while(n != 0) {
    int m = n;
    vector<pair<int, long long> > comm;
    while(m--) {
      int num;
      long long price, unit;
      cin>>num>>price>>unit;
      int dataNum = findNum(comm, num);
      if(dataNum == comm.size()) {
        comm.push_back(make_pair(num, price*unit));
      }
      else {
        comm[dataNum].second += price*unit;
      }
    }

    bool flag = true;
    for(int i=0; i<comm.size(); i++) {
      if(comm[i].second >= 1000000) {
        cout<<comm[i].first<<endl;
        flag = false;
      }
    }
    if(flag == true) {
      cout<<"NA"<<endl;
    }
    cin>>n;
  }
}