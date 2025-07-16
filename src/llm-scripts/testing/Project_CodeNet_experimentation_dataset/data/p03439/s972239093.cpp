#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    string v = "Vacant";
    
    vector<string> s(n);
    int l = 0;
    int r = n-1;
    cout << l << endl;
    cin >> s[l];
    if(s[l] == v) return 0;
    cout << r << endl;
    cin >> s[r];
    if(s[r] == v) return 0;

    while(r-l > 0){
        int mid = (l+r) / 2;
        cout << mid << endl;
        cin >> s[mid];
        if(s[mid] == v) return 0;

        if(s[mid] == s[l]){
            if((mid-l)%2 == 0) l = mid;
            else r = mid;
        }
        else{
            if((mid-l)%2 == 0) r = mid;
            else l = mid;
        }
    }

    return 0;

}