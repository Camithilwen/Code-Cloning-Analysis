#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>v;
  int answer=0;
  for(int i = 0 ; i< 2*n ;i++){
    int k;
    cin>>k;
    v.push_back(k);
  }
  sort(v.begin(),v.end());
  for(int i = 0 ; i < 2*n ; i+=2){
    answer+=min(v.at(i),v.at(i+1));
  }
  cout<<answer<<endl;
return 0;
}
