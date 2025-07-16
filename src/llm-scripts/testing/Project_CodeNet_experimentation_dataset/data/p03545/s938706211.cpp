#include<bits/stdc++.h>
using namespace std;

bool is_sum (vector<int> s, int n){
    if(s.size() == 1) {
        if(s.at(0) == n) return true;
        else return false;
    }
    else{
        int a = s.at(s.size()-1);
        s.pop_back();
        if(is_sum(s,n+a) || is_sum(s,n-a)) return true;
        else return false;
    }

}

vector<string> cal_sum (vector<int> s, int n){
    if(s.size() == 1) return {};
    else{
        int a = s.at(s.size()-1);
        s.pop_back();
        if(is_sum(s,n-a)){
            vector<string> v = cal_sum(s,n-a);
            v.push_back("+");
            return v;
        }
        if(is_sum(s,n+a)){
            vector<string> v = cal_sum(s,n+a);
            v.push_back("-");
            return v;
        }
    }
}

int main(){
    string s ;
    cin >> s;
    vector<int> v(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        v.at(i)  = s.at(i) -48;
    }

    vector<string> sign = cal_sum(v,7);
    cout << s.at(0);
    for (int i = 1; i < 4; i++)
    {
        cout << sign.at(i-1) << v.at(i) ;
    }
    cout << "=7" << endl;
    
}