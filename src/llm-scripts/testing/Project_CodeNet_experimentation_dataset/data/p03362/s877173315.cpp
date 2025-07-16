#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> num(55556);
    for(int i = 0; i < 55556; i++) num[i] = i;
    num[0] = -1;
    num[1] = -1;
    for(int i = 2; i < 55556; i++){
        if(num[i] == -1) continue;
        int t = 2;
        while(i * t <= 55555){
            num[i * t] = -1;
            t++;
        }
    }
    vector<int> sosuu;
    for(int i = 0; i < 55556; i++){
        if(num[i] != -1) sosuu.push_back(num[i]);
    }
    vector<int> cnt(5, 0);
    for(int i = 0; i < sosuu.size(); i++){
        cnt[sosuu[i] % 5]++;
    }
    int t = 0;
    for(int i = 0; i < sosuu.size(); i++){
        if(t == N) break;
        if(sosuu[i] % 5 == 1) {
            cout << sosuu[i] << ' ';
            t++;
        }
    }
    cout << endl;
}