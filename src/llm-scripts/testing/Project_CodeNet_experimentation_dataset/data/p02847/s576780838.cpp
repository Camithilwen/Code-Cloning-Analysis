#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<string,int>;

int main() {
    map<string,int> day{P("SUN",7),P("MON",6),P("TUE",5),P("WED",4),P("THU",3),P("FRI",2),P("SAT",1)};
    string S;cin>>S;
    cout<<day[S]<<endl;
}