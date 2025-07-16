#include <iostream>
#include <string>

using namespace std;

int roma[128];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    roma['I']=1;
    roma['V']=5;
    roma['X']=10;
    roma['L']=50;
    roma['C']=100;
    roma['D']=500;
    roma['M']=1000;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    while(getline(cin, str)){
        int ans=roma[(unsigned)str[str.length()-1]];
        for(int i=str.length()-2; i>=0; i--){
            int rn=roma[(unsigned)str[i]];
            if(rn>=roma[(unsigned)str[i+1]]) ans+=rn;
            else ans-=rn;
        }
        cout<<ans<<'\n';
    }
    return 0;
}