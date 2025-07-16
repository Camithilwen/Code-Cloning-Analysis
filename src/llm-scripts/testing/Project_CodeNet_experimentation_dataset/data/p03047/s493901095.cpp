#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define co(a) cout<<a<<endl
#define sz size()
#define bgn begin()
#define en end()
#define pb(a) push_back(a)
#define pop pop_back
#define V vector
#define P pair
#define V2(a,b,c) V<V<int>> a(b,V<int>(c))
#define V2a(a,b,c,d) V<V<int>> a(b,V<int>(c,d))
#define incin(a) int a; cin>>a
#define yuko(a) setprecision(a)
//#define min min<int>
//#define max max<int>
template<class T>
 void cou(vector<vector<T>> a){
  int b=a.size();
  int c=a[0].size();
  fo(i,b){
    fo(j,c){
      cout<<a[i][j];
      if(j==c-1)
        cout<<endl;
      else
        cout<<' ';
    }
  }
}
/*template<>
 void cou(vector<vector<char>> a){
  int b=a.size();
  int c=a[0].size();
  fo(i,b){
    fo(j,c){
      cout<<a[i][j];
      if(j==c-1)
        cout<<endl;
      else
        cout<<' ';
    }
  }
}*/
 int wari(int a,int b) {
   if(a%b==0)
     return a/b;
   else
     return a/b+1;
 }
 int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
 }
 int souwa(int a){
  return a*(a+1)/2;
 }
 int lcm(int a,int b){
  int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return d*e/f;
    }
  int gcm(int a,int b){
      int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return f;
  }
 bool prime(int a){
   if(a<2)
     return false;
   else if(a==2)
     return true;
   else if(a%2==0)
     return false;
   double b=sqrt(a);
    for(int i=3;i<=b;i+=2){
      if(a%i==0){
        return false;
      }
    }
   return true;
 }
struct Union{
  vector<int> par;
  Union(int n){
	par= vector<int>(n, -1);
  }
  int find(int x){
    if(par[x]<0)
      return x;
    else
      return par[x]=find(par[x]);
  }
  bool same(int a,int b){
    return find(a)==find(b);
  }
  int Size(int a){
    return -par[find(a)];
  }
  void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
      return;
    if(Size(b)>Size(a))
      swap<int>(a,b);
    par[a]+=par[b];
    par[b]=a;
  }
};
int ketas(int a){
  string b=to_string(a);
  int c=0;
  fo(i,keta(a)){
    c+=b[i]-'0';
  }
  return c;
}
/*struct aa{
	vector<int> gt;
  aa(int n){
	gt= vector<int>(n, 1);
  }
	void c(V<int> d,int b){
	if(d[b]==0){
		gt[d[b]-1]++;
		gt[gt.sz-1]++;
	}
	else{
		gt[d[b]-1]++;
		c(d,d[d[b]]-1);
	}
}
void cok(int a){
	cout<<gt[a-1]<<endl;
	fo(i,a-1)
	cout<<gt[i]<<endl;
}
};
*/
signed main(){
	int a,b;
	cin>>a>>b;
	cout<<a+1-b<<endl;
}