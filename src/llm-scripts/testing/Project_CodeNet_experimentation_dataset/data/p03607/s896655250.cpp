#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(s.count(a)) s.erase(a);
        else s.insert(a);
    }
    cout << s.size() << endl;
}