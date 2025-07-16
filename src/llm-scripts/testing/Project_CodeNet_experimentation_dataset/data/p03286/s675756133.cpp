#include<bits/stdc++.h>
#define ll long long
#define P pair<int ,int>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>vec = {};

    if(n == 0){
        cout << "0" << endl;
        return 0;
    }

    while(n != 1){
        if(n%2 == 1 || n%2 == -1){
            vec.push_back(1);
            n--;
            n /= (-2);
        }
        else { 
            vec.push_back(0);
            n /= (-2);
        }
    }vec.push_back(1);

    for(int i = (int)vec.size() - 1 ;i>=0;i--){
        cout << vec[i];
    }
    cout << endl;
}
