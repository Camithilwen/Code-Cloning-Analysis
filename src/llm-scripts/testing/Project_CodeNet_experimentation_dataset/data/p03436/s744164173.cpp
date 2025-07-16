#include<bits/stdc++.h>
using namespace std;
int main(){
  long h,w;cin>>h>>w;
  long b=0;
  vector<string>S(h);for(long i=0;i<h;i++){
    cin>>S[i];
    for(char c:S[i])if(c=='#')b++;
  }
  vector<long>D(w*h,-1);D[0]=0;
  queue<long>q;q.push(0);
  while(q.size()){
    long f=q.front();q.pop();
    if(f/w-1>=0&&D[f-w]==-1&&S[f/w-1][f%w]!='#'){
      D[f-w]=D[f]+1;q.push(f-w);
    }
    if(f/w+1<h&&D[f+w]==-1&&S[f/w+1][f%w]!='#'){
      D[f+w]=D[f]+1;q.push(f+w);
    }
    if(f%w-1>=0&&D[f-1]==-1&&S[f/w][f%w-1]!='#'){
      D[f-1]=D[f]+1;q.push(f-1);
    }
    if(f%w+1<w&&D[f+1]==-1&&S[f/w][f%w+1]!='#'){
      D[f+1]=D[f]+1;q.push(f+1);
    }
  }
  cout<<(D[w*h-1]!=-1?(w*h)-D[w*h-1]-b-1:-1)<<endl;
}