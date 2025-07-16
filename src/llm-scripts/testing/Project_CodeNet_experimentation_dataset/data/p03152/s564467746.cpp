#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int main(){
  long long int r=0,c=0;
  long long int n,m; cin >> n >> m;
  vector<int> row(n), col(m); 
  for(int i=0;i<n;i++) cin >> row[i];
  for(int i=0;i<m;i++) cin >> col[i];
  sort(row.begin(), row.end(), greater<int>());
  sort(col.begin(), col.end(), greater<int>());
  long long int ans = 1;
  int rp=0,cp=0;
  for(int i=0;i<n*m;i++){
    int num = n*m-i;
  	if(rp<n && row[rp]==num && cp<m && col[cp]==num){
    	ans = ans; r++;c++;rp++;cp++;
    }else if(rp<n && row[rp]==num){
    	ans = (c * ans)%MOD; rp++; r++;
    }else if(cp<m && col[cp]==num){
    	ans = (r * ans)%MOD; cp++; c++;
    }else{
      	ans = ((r*c - i)*ans)% MOD; 
    }
  }
  cout << ans << endl;
  return 0;
}