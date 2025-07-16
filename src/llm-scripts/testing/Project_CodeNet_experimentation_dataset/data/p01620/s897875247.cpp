#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        vector<int> a;
        for(int i=0,t;i<n;++i){
            cin>>t;
            a.push_back(t);
        }
        string s,ans;
        cin>>s;

        string alpha;
        map<char, int> alphaM;
        int id = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            alpha.push_back(c);
            alphaM[c] = id++;
        }
        for(char c = 'A'; c <= 'Z'; c++) {
            alpha.push_back(c);
            alphaM[c] = id++;
        }


        for(int i=0;i<s.size();++i){
            int x=a[i%a.size()];
            int id2 = alphaM[s[i]];
            ans += alpha[(id2-x+52)%52];
        }
        cout<<ans<<endl;
    }
}