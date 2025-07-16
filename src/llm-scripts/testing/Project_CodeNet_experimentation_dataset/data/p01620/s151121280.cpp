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
    int ansNum;
    char station[102];
    char ans[102];
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //vector<char> ans;
    
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
        ansNum = 0;

	// Output
	now = 0;
        for(int i=0; i<102; i++) {
            scanf("%c", &station[i]);
            if(station[i] == '\n') {
                break;
            }
            ansNum++;

	    int tmp;
	    tmp = alpha.find(station[i]);
	    ans[i] = alpha[(tmp-k[now]+52)%52];
	    now++;
            if(now == n) {
                now = 0;
            }
        }

        for(int i=0; i<ansNum; i++) {
            cout<<ans[i];
        }
        cout<<endl;
    }
}