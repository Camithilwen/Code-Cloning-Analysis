#include<bits/stdc++.h>
using namespace std;

int a, b, c, n;
int parts[310];
int result[1010][4];
int main()
{
  while(cin >> a >> b >> c && (a || b || c)){
    cin >> n;
    for(int i = 1; i <= a + b + c; i++)
      parts[i] = 2;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < 4; j++)
	cin >> result[i][j];

    for(int i = 0; i < n; i++)
      if(result[i][3])
	parts[result[i][0]] = parts[result[i][1]] = parts[result[i][2]] = 1;

    for(int i = 0; i < n; i++)
      if(!result[i][3]){
	if(parts[result[i][0]] == 1 && parts[result[i][1]] == 1)
	  parts[result[i][2]] = 0;
	if(parts[result[i][1]] == 1 && parts[result[i][2]] == 1)
	  parts[result[i][0]] = 0;
	if(parts[result[i][2]] == 1 && parts[result[i][0]] == 1)
	  parts[result[i][1]] = 0;
      }

    for(int i = 1; i <= a + b + c; i++)
      cout << parts[i] << endl;

  }
  return 0;
}