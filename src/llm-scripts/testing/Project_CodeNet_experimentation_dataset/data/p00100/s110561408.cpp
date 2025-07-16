
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<complex>
using namespace std ;
typedef vector<int> vi ;
typedef vector<vi> vvi ;
typedef vector<string> vs ;
typedef pair<int, int> pii; 
typedef long long ll ;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()


int main(void){
  int n;
  while(cin>>n,n){
    vector<pair<int , long long > > sales;
    while(n--){
      int id,code,num;
      cin>>id>>code>>num;
      int i = 0 ;
      for(; i < sales.size();i++){
	if(sales.at(i).first==id){
	  sales.at(i).second += (long long) code * num;
	  break;
	}
      }
      if(i == sales.size()){
	pair<int , long long> worker;
	worker.first = id;
	worker.second = (long long)code * num;
	sales.push_back(worker);
      }
      
    }
    bool found = false;
    rep(i,sales.size()){
      if(sales.at(i).second >= 1000000){
	found = true;
	cout << sales.at(i).first << endl;
      }
    }
    if(!found)
      cout << "NA" << endl;
    
  }
}