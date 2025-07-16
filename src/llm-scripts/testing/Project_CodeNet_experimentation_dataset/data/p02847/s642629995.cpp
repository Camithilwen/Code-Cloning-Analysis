#include <bits/stdc++.h>

using namespace std;

int main() {

    string arr[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string s;
    cin>>s;
    int x = find(arr,arr+7,s)-arr;
    cout<<7-x<<endl;



    return 0;
}
