#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        if(n + k == 0)  break;
        string x[n];
        for(int i = 0; i < n; i++)  cin >> x[i];
        sort(x, x+n);

        set<int> ans;
        do{
            string tmp = "";
            for(int i = 0; i < k; i++)  tmp = tmp + x[i];
            ans.insert(stoi(tmp));
        }while(next_permutation(x, x+n));

        cout << ans.size() << endl;
    }
    return 0;
}
