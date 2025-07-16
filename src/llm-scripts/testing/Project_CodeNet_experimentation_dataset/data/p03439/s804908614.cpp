#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(){

    int n;
    cin >> n;
    cout << 0 << endl;
    string ss;
    cin >> ss;
    if (ss == "Vacant") return 0;
    int l = 0, r = n;
    while(true){
        int mid = (l+r)/2;
        cout << mid << endl;
        string s;
        cin >> s;
        if (s == "Vacant") return 0;
        if (mid % 2 == 1 && s != ss || mid % 2 == 0 && s == ss)
            l = mid + 1;
        else
            r = mid;
    }
}
