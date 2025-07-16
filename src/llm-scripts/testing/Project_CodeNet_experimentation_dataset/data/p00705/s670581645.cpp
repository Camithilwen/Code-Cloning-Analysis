#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, q;
    while(cin >> n >> q, n != 0 && q != 0){
        map<int,int> c;
        for(int i=0; i<n; ++i){
            int m;
            cin >> m;
            for(int j=0; j<m; ++j){
                int tmp;
                cin >> tmp;
                if(c.find(tmp) == c.end())
                    c.insert(map<int,int>::value_type(tmp,1));
                else
                    ++c[tmp];
            }
        }
        map<int,int>::iterator it = c.begin();
        int max = 0, res = 0;
        while(it!=c.end()){
            if(max < (*it).second && q <= (*it).second){
                max = (*it).second;
                res = (*it).first;
            }
            ++it;
        }
        cout << res << endl;
    }
    return 0;
}