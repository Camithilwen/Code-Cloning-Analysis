#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int n,rank[100];
  pair<int,int> point[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    point[i].first = 0;
    point[i].second = i;
  }
  for(int i=0;i<n*(n-1)/2;i++){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(c<d){
      point[b-1].first += 3;
    }else if(c>d){
      point[a-1].first += 3;
    }else{
      point[a-1].first += 1;
      point[b-1].first += 1;
    }
  }
  sort(point,point+n);
  reverse(point,point+n);
  int r;
  for(int i=0;i<n;i++){
    int team = point[i].second;
    if(i>0&&point[i].first==point[i-1].first){
      rank[team] = r;
    }else{
      r = i+1;
      rank[team] = r;
    }
  }
  for(int i=0;i<n;i++) printf("%d\n",rank[i]);
  return 0;
}