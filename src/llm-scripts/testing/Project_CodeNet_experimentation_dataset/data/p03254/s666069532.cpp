#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}

int gcd(int a,int b){
   if(a%b==0) return b;
   return gcd(b,a%b);
}
int digit(int num){
   int cnt=0;
   while(num!=0){
      cnt+=num%10;
      num=num/10;
   }
   return cnt;
}
int main(void){
   int N;
   cin>>N;
   long long x;
   cin>>x;
   vector<long long> a(N);
   vector<long long> result(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   sort(a.begin(),a.end());
   for(int i=0;i<N;i++){
      result[i]=min(x,a[i]);
      x-=result[i];
   }
   result[N-1]+=x;
   int ans=0;
   for(int i=0;i<N;i++){
      if(result[i]==a[i]) ans++;
   }
   cout<<ans<<endl;
   return 0;
}
