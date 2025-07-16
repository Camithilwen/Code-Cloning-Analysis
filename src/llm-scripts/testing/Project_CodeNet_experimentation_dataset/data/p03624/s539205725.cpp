#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.

char _find(string &str){
    bool pres[26]={0};
    for(char ch:str){
        pres[ch-'a']=1;
    }
    for(int i=0;i<26;i++){
        if(pres[i]==0){
            return (char)(i+'a');
        }
    }
    return '%';
}

void solve(){
    string str;
    cin>>str;
    char ch=_find(str);
    str="";
    str.push_back(ch);
    cout<<( str=="%" ? "None" : str)<<endl;
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}