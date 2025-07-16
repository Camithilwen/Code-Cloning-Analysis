#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <map> 
using namespace std;
 
const int MAX= 10000100;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
#define ll long long int
#define gcd(a,b) __gcd(a,b)

int GCD(int a, int b) {if(!b) return a; return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}

int main(void){
  string str;
  while(cin>>str){
    vector<int> card;
    vector<int> cnt(13,0);
    for(int i = 0 ; i < str.size() ; i ++){
      if('1' <= str[i] && str[1] <= '9'){
	if('0' <= str[i + 1] && str[i + 1] <= '9'){
	  int num = 10 + str[i + 1] - '0';
	  card.push_back(num);
	  cnt[--num] ++;
	  i ++;
	}else{
	  int num = str[i] - '0';
	  card.push_back(num);
	  cnt[--num] ++;
	}
      } 
    }
    sort(card.begin(),card.end());
    int ans[2][2] = {0,0,0,0};
    int c1,c2;
    c1 = c2 = 0;
    bool straight = false;
    rep(i,cnt.size()){
      if(cnt[i] == 1 && 
	 cnt[i + 1] == 1 && 
	 cnt[i + 2] == 1 && 
	 cnt[i + 3] == 1 && 
	 cnt[i + 4] == 1){
	straight = true;
	break;
      }
      if(cnt[i] > 1 && c1 == 0)
	c1 = cnt[i];
      else if(cnt[i] > 1)
	c2 = cnt[i];
    }
    if(straight)
      cout<<"straight";
    else if(c1 == 5)
      cout<<"five card";
    else if(c1 == 4 || c2 == 4)
      cout<<"four card";
    else if((c1 == 3 && c2 == 2) || 
	    (c1 == 2 && c2 == 3)) 
      cout<<"full house";
    else if(c1 == 3)
      cout<<"three card";
    else if(c1 == 2 && c2 == 2)
      cout<<"two pair";
    else if(c1 == 2)
      cout<<"one pair";
    else if(cnt[ 9] == 1 && 
	    cnt[10] == 1 && 
	    cnt[11] == 1 && 
	    cnt[12] == 1 && 
	    cnt[ 0] == 1)
      cout<<"straight";
    else 
      cout<<"null";
    cout<<endl;
    
    }
}