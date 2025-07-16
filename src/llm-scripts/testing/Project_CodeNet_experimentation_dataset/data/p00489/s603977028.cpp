#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int teamn = 0;
  cin >> teamn;
  vector<int> point(teamn,0);
  vector<int> run(teamn,0);
  vector<int> plist;
  vector<int> rank(teamn,1);
  int fteam1,fteam2;
  int point1,point2;
  for(int n = 0;n<(teamn*(teamn-1))/2;n++){
    cin >> fteam1 >> fteam2;
    cin >> point1 >> point2;
    fteam1 -= 1;
    fteam2 -= 1;
    if(point1 > point2){
      point[fteam1] += 3;
    }else
    if(point1 == point2){
      point[fteam1] += 1;
      point[fteam2] += 1;
    }else
    if(point1 < point2){
      point[fteam2] += 3;
    }
  }
  for(int g = 0;g<point.size();g++){
    run[g] = point[g];
  }
  sort(run.begin(),run.end(),greater<int>());
  //for(int n = 0;n<run.size();n++){
  //  if(run[n] != run[n+1]){
  //    plist.push_back(run[n]);
  //  }
  //}
  for(int n = 0;n<run.size();n++){
    for(int g = 0;g<point.size();g++){
      if(n == 0 && run[n] == point[g]){
        rank[g] = n;
      }
      if(run[n] == point[g] && n != 0){
        if(run[n] != run[n-1]){
          rank[g] = n;
        }
      }
    }
  }
  for(int n = 0;n<rank.size();n++){
    cout << rank[n]+1 << endl;
  }
  return 0;
}