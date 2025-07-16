#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n, m;
  while(1){
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0)return 0;
    int res = 0, tmp;
    vector<int> points, points2;
    for(int i = 0;i < n;i++){
      scanf("%d", &tmp);
      points.push_back(tmp);
    }
    vector<int>::iterator it1,it2;
    for(it1 = points.begin();it1 != points.end();it1++){
      points2.push_back(*it1);
      for(it2 = points.begin();it2 != points.end();it2++){
	if(*it1 + *it2 <= m)points2.push_back(*it1 + *it2);
      }
    }
    sort(points2.begin(),points2.end());
    for(it1 = points2.begin();it1 != points2.end();it1++){
      it2 = upper_bound(points2.begin(), points2.end(), m - *it1);
      if(it2 == points2.begin())continue;
      it2--;
      res = max(res, *it1 + *it2);
    }
    printf("%d\n",res);
  }
}