#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    string s, sub;
    int a;
    vector<int> v;
    cin >> s;
    for(int i = 0; i < s.size()-2; i++){
        sub = s.substr(i, 3);
        a = stoi(sub);
        v.push_back(abs(753-a));
    }
    sort(v.begin(), v.end());
    cout << v.front();
}





///promy_pompom
//hello world
