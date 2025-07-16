#include<iostream>
using namespace std;

const int INF = 2000000;

struct LineTable{
  int cost;
  int times;
  LineTable(){
    cost = INF;
    times = INF;
  }
};

int main(){

    int n,m;
    while(1){
      cin >> n >> m;
      if(n==0&&m==0){
        break;
      }
      LineTable table[m][m];

      for(int i=0;i<m;i++){
        table[i][i].cost = 0;
        table[i][i].times = 0;
      }

      for(int i=0;i<n;i++){
        int a,b,cost,times;
        cin >> a >> b >> cost >> times;
        table[a-1][b-1].cost = cost;
        table[a-1][b-1].times = times;
        table[b-1][a-1].cost = cost;
        table[b-1][a-1].times = times;
      }

      for(int k=0;k<m;k++){
        for(int i=0;i<m;i++){
          for(int j=0;j<m;j++){
            if(table[i][j].cost > table[i][k].cost + table[k][j].cost){
              table[i][j].cost = table[i][k].cost + table[k][j].cost;
            }
          }
        }
      }

      for(int k=0;k<m;k++){
        for(int i=0;i<m;i++){
          for(int j=0;j<m;j++){
            if(table[i][j].times > table[i][k].times + table[k][j].times){
              table[i][j].times = table[i][k].times + table[k][j].times;
            }
          }
        }
      }

/*      for(int k=m-1;k>=0;k--){
        for(int i=m-1;i>=0;i--){
          for(int j=m-1;j>=0;j--){
            if(table[i][j].cost > table[i][k].cost + table[k][j].cost){
              table[i][j].cost = table[i][k].cost + table[k][j].cost;
            }
          }
        }
      }

      for(int k=m-1;k>=0;k--){
        for(int i=m-1;i>=0;i--){
          for(int j=m-1;j>=0;j--){
            if(table[i][j].times > table[i][k].times + table[k][j].times){
              table[i][j].times = table[i][k].times + table[k][j].times;
            }
          }
        }
      }*/

      int k,p,q,r;
      cin >> k;
      /*cin >> p >> q >> r;
      if(r==0){
        cout << table[p-1][q-1].cost;
      }
      else{
        cout << table[p-1][q-1].times;
      }
      for(int i=1;i<k;i++){
        cin >> p >> q >> r;
        if(r==0){
          cout << ' ' <<table[p-1][q-1].cost;
        }
        else{
          cout << ' ' <<table[p-1][q-1].times;
        }
      }
      cout << endl;*/

      for(int i=0;i<k;i++){
        cin >> p >> q >> r;
        if(r==0){
          cout << table[p-1][q-1].cost << endl;;
        }
        else{
          cout << table[p-1][q-1].times << endl;
        }
      }
    }
    return 0;
}