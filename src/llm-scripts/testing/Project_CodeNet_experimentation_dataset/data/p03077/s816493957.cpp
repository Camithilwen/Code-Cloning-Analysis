#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    long long N;
    long long travel[5];
    cin >> N;
    for (int i = 0; i < 5; i++){
        cin >> travel[i];
    }
    sort(travel, travel + 5);
    cout << 4 + (N + travel[0] - 1)/ travel[0] << endl;
    
    return 0;
}
