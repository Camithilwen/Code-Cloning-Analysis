
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{

  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  int dx=abs(sx-tx);
  int dy=abs(sy-ty);
  cout<<string(dx,'R')<<string(dy,'U');
  cout<<string(dx,'L')<<string(dy,'D');
  cout<<'L'<<string(dy+1,'U')<<string(dx+1,'R')<<'D';
  cout<<'R'<<string(dy+1,'D')<<string(dx+1,'L')<<'U';
  cout<<endl;
  return 0;

}
