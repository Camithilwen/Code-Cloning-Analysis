#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
        int n,m,i,p,cnt_p=0,cnt_a=0;
        string s;
        cin >> n >> m;
        vector<int> pen(n);
        vector<bool> done(n);
        for(i=0;i<m;++i){
                cin >> p >> s;
                --p;
                if(done.at(p)) continue;
                if(s=="WA") ++pen.at(p);
                else{
                        cnt_p += pen.at(p);
                        ++cnt_a;
                        done.at(p) = true;
                }
        }
        cout << cnt_a << " " << cnt_p << endl;
        return 0;
}