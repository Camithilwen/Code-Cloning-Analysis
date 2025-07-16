#include<iostream>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

map< int, set<int> > Init(int);
set<int> FindFriends(map< int, set<int> >);

int main(){
  int i, n, m, a, b;
  set<int> friends;
  map< int, set<int> > data;

  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    data = Init(n);

    for(i=0; i<m; ++i){
      cin >> a >> b;
      data[a].insert(b);
      data[b].insert(a);
    }
    friends = FindFriends(data);
    cout << friends.size() << endl;
  }
  return 0;
}

map< int, set<int> > Init(int n){
  int i;
  set<int> _data;
  map< int, set<int> > data;
  for(i=1; i<=n; ++i) data.insert(make_pair(i, _data));
  return data;
}

set<int> FindFriends(map< int, set<int> > data){
  set<int> _data, friends;
  set<int>::iterator i, j;
  map< int, set<int> >::iterator k;
  _data = data[1];
  for(i=_data.begin(); i!=_data.end(); ++i){
    if(friends.find(*i) == friends.end())
      friends.insert(*i);
    k = data.find(*i);
    for(j=k->second.begin(); j!=k->second.end(); ++j){
      if(*j != 1 && friends.find(*j) == friends.end())
	friends.insert(*j);
    }
  }
  return friends;
}