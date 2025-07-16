#include <bits/stdc++.h>
using namespace std;

int main() {
string az="abcdefghijklmnopqrstuvwxyz";
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    int i=0,j=0;
    for(int j=0;j<s.length();j++) {
        if(az[i]==s[j]) {
		i++;
		}
        if(i==26) {
		cout << "None" << endl;
		return 0;
		}
    }
    cout << az[i];
}
