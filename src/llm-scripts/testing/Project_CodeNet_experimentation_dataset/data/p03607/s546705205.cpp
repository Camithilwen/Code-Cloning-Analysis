#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> memo;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(memo.count(a)) memo.erase(a);
        else memo[a] = 1;
    }

    cout << memo.size() << endl;
    return 0;
}