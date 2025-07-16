#include<bits/stdc++.h>
using namespace std;
int main()
{
      int n,t=0;
      cin>>n;
      int arr[2*n];
      priority_queue<int,vector<int>,greater<int>> q;
      for(int i=0;i<2*n;i++)
      {
            int k;
            cin>>k;
            q.push(k);
      }
      for(int i=0;i<n;i++)
      {
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            t=t+min(x,y);
      }
      cout<<t;
}
