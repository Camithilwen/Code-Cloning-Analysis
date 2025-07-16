#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

  int n;
  while(cin>>n){
    if( n == 0 ) break;

    int score[n];
    for(int i = 0; i < n; ++i){
      score[i] = 0;
    }
    for(int i = 0; i < n*(n-1)/2; ++i){
      int a,b,c,d;
      cin >> a >> b >> c >> d;
      --a;
      --b;
      
      score[a] += c>d?3:c==d?1:0;
      score[b] += d>c?3:c==d?1:0;
    }

    vector<pair<int,int> > v;
    for(int i = 0; i < n; ++i){
      v.push_back( make_pair(score[i], i) );
    }
    sort(v.begin(), v.end());

    int rank[n];

    /*
    for(int i = 0; i < n; ++i){
      cout << score[i] << endl;
    }
    */
    
    for(int i = n-1; i >= 0; --i){
      rank[ v[i].second ] = n-1-i+1;
      if( i<n-1 && v[i].first == v[i+1].first){
        rank[ v[i].second ] = rank[ v[i+1].second ];
      }
    }
    
    for(int i = 0; i < n; ++i){
      cout << rank[i] << endl;
    }
    
  }
  return 0;
}