#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string str;
    int ret=0;
    vector<pair<char,int> > v;
    cin >> str;

    int cnt=1;
    char tmp=str[0];
    for(int i=1;i<str.size();++i){
        if(str[i] == tmp){
            cnt++;
        }else{
            v.push_back(make_pair(tmp,cnt));
            cnt=1;
            tmp = str[i];
        }
    }
    v.push_back(make_pair(tmp,cnt));
    for(int i=0;v.size() >=3 && i<v.size()-2;++i){
        if(v[i].first == 'J' &&
           v[i+1].first == 'O' &&
           v[i+2].first == 'I'){
            if(v[i].second >= v[i+1].second &&
               v[i+2].second >= v[i+1].second){
                ret = max(ret, min(v[i].second, min(v[i+1].second,v[i+2].second)));
            }
        }
    }
    cout << ret << endl;
}