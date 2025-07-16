#include <bits/stdc++.h>
using namespace std;
 
void fail(){
    cout << "No" << endl;
    exit(0);
}
 
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> task_p, task_n;
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        int s = 0, mn = 0;
        for(char c : S){
            s += (c == '(' ? 1 : -1);
            mn = min(mn, s);
        }
        int a = -mn, b = s;
        (b >= 0 ? task_p : task_n).emplace_back(a, b);
    }
    sort(task_p.begin(), task_p.end());
    int R = 0;
    for(auto& p : task_p){
        if(R < p.first) fail();
        R += p.second;
    }
    sort(task_n.begin(), task_n.end(), [](auto a , auto b){ return a.first+a.second > b.first+b.second; });
    for(auto& p : task_n){
        if(R < p.first) fail();
        R += p.second;
    }
    if(R) fail();
    cout << "Yes" << endl;
    return 0;
}
