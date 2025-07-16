// King's Inspection

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    int now=0;
    int k[102];
    string station;
    string ans;
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while(1) {
      // Input
        cin>>n;
        if(n == 0) {
            break;
        }
        for(int i=0; i<n; i++) {
            cin>>k[i];
        }
        cin.ignore();

	// Output
	now = 0;
	getline(cin, station);

	for(int i=0; i<station.length(); i++) {
	    int tmp;
	    tmp = alpha.find(station[i]);
	    ans[i] = alpha[(tmp-k[now]+52)%52];
	    now++;
            if(now == n) {
                now = 0;
            }
	}
        for(int i=0; i<station.length(); i++) {
            cout<<ans[i];
        }
        cout<<endl;
    }
}