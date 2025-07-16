#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int main() {

  while(1) {
  
    int n;
    cin >> n;
    int m;
    cin >> m;

    if(n==0 && m ==0) break;
  
    vector <int> re[502];

    queue <int > Q;
    int a, b;
    for(int i=0;i<m;i++) {
      cin >> a >> b;
      re[a].push_back(b);
      re[b].push_back(a);
    }

    int t;
    int count = -1;
    Q.push(1);

    int dis[502];
    for(int i=0;i<=n;i++) dis[i] = -1;
  
    
  
    while(Q.empty() != 1){
    
      t = Q.front();
      Q.pop();
    
      for(int i=0;i<re[t].size();i++) {
	if(dis[re[t][i]] == -1 && dis[t]+1 < 2) {
	  dis[re[t][i]] = dis[t] + 1;
	  count++;
	  //  printf("dis[i%d](%d) | dis[t%d](%d) | re[%d][%d](%d)\n",i,dis[re[t][i]],t,dis[t],t,i,re[t][i]);
	  Q.push(re[t][i]);
	  //cout << "Q.front == " << Q.front() << endl;
	}
      }
    }
  
    cout << count << endl;
  
  }

  return 0;
}