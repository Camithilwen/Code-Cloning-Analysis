        #include<bits/stdc++.h>
        #define int long long
        using namespace std;
        typedef pair<int,int> P;
         
        signed main(){
          vector<int> v;
          int t=3;
          while(v.size()<1000){
            bool f=1;
            for(int i=2;i*i<=t;i++)if(t%i==0)f=0;
            if(f)v.push_back(t);
            t++;
          }
          int d1[500][500],d2[500][500],c=0;
          for(int i=-498;i<500;i+=2){
            for(int j=-i;j+i<500;j++){
              if(0<=j&&j<500&&0<=j+i&&j+i<500)d1[j][j+i]=v[c];
            }
            c++;
          }
         
          for(int i=0;i<1000;i+=2){
            for(int j=1000;i-j<500;j--){
              if(0<=j&&j<500&&0<=i-j&&i-j<500)d2[j][i-j]=v[c];
            }
            c++;
          }
         
          int n;
          cin>>n;
          
          int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              if(j)cout<<" ";
              if((i+j)%2){
        	int res=1;
        	set<int> s;
        	for(int k=0;k<4;k++){
        	  int nx=j+dx[k],ny=i+dy[k];
        	  if(nx<0||ny<0||nx>=500||ny>=500)continue;
        	  s.insert(d1[ny][nx]);
        	  s.insert(d2[ny][nx]);
        	}
        	for(auto z:s){res*=z;}
        	cout<<res+1;
              }
              else cout<<d1[i][j]*d2[i][j];
            }
            cout<<endl;
          }
          return 0;
        }