//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    string s,ans;cin>>s;
    if(s.size()!=26){
        vector<int> vec(26);
        for(char c:s){
            vec[(c-'a')]++;
        }
        for(int i=0;i<26;i++){
            if(vec[i]==0){
                ans=s+(char)('a'+i);
                break;
            }
        }
    }
    else{
        bool answer=false;
        vector<int> vec(26);
        for(int i=25;i>=0;i--){
            int tmp=s[i]-'a';
            vec[tmp]++;
            for(int j=tmp+1;j<26;j++){
                if(vec[j]){
                    ans=s.substr(0,i)+(char)('a'+j);
                    answer=true;
                    break;
                }
            }
            if(answer)break;
        }
        if(!answer)ans="-1";
    }
    cout<<ans<<endl;
}
