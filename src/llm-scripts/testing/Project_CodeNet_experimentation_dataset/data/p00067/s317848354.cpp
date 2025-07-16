#include <bits/stdc++.h>
using namespace std;

string field[12];

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void sol(int x, int y);

int main()
{
  while (cin >> field[0]){
    long ct = 0;
    for (int i = 1; i < 12; i++){
      cin >> field[i];
    }
    for (int i = 0; i < 12; i++){
      for (int j = 0; j < 12; j++){
        if (field[i][j] == '1'){
          field[i][j] = '0';
          sol(i, j);
          ct++;
        }
      }
    }
    cout << ct << endl;
  }
}

void sol(int x, int y)
{
  for (int i = 0; i < 4; i++){
    if (!(0 <= x + dx[i] && 0 <= y + dy[i] && x + dx[i] < 12 && y + dy[i] < 12)) continue;
    if (field[x + dx[i]][y + dy[i]] == '1'){
      field[x + dx[i]][y + dy[i]] = '0';
      sol(x + dx[i], y + dy[i]);
    }
  }
}