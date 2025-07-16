#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    std::vector<string> d(3);
    for(ll i=0;i<3;++i){
        cin>>d[i];
    }
    ll a=0,b=0,c=0;
    char now='a';
    while(1){
        switch(now){
            case 'a':
                if(a>=d[0].length()){
                    cout<<char(now+'A'-'a');
                    return 0;
                }
                now=d[0][a];
                a++;
            break;
            case 'b':
                if(b>=d[1].length()){
                    cout<<char(now+'A'-'a');
                    return 0;
                }
                now=d[1][b];
                b++;
            break;
            case 'c':
                if(c>=d[2].length()){
                    cout<<char(now+'A'-'a');
                    return 0;
                }
                now=d[2][c];
                c++;
            break;
        }
    }
    return 0;
}