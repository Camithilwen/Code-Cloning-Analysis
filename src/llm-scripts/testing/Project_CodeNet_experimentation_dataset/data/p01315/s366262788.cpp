#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
  for(;;){
    int n;
    cin >> n;
    if(n==0) break;
    multimap< double,set<string> > list;
    for(int i=0; i<n; i++){
      string name;
      int p,a,b,c,d,e,f,s,m;
      cin >> name >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      int num = f + f * (m-1);
      int time = a + b + c + (d + e) * m;
      double value = (num * s - p) / (double)time;
      multimap< double,set<string> >::iterator it = list.find(value);
      if(it != list.end()){
        (*it).second.insert(name);
      }else{
        set<string> s;
        s.insert(name);
        list.insert(make_pair< double,set<string> >(value,s));
      }
    }
    multimap< double,set<string> >::reverse_iterator rit = list.rbegin();
    while(rit != list.rend()){
      for(set<string>::iterator it = (*rit).second.begin(); it != (*rit).second.end(); it++){
        cout << (*it) << endl;
      }
      rit++;
    }
    cout << "#" << endl;
  }
  return 0;
}