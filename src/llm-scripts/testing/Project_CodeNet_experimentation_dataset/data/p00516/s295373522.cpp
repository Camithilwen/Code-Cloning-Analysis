#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    while(true){
    int n,m;
    cin >> n ;
    if(cin.eof()) break;
    cin >> m;

    vector<int> a(1000);
    vector<int> b(1000);
    vector<int> c(1000);
    vector<bool> u(1000);
    vector<int> ans(1000);
    fill(u.begin(),u.end(),true);
    for(int i=0;i<n;i++){
	cin >> a[i];
    };
    for(int i=0;i<m;i++){
	cin >> b[i];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(u[j] && a[i] <= b[j]){
		u[j] = false;
		ans[i]++;
	    }
	}
    }
    int res = -1,ansnum = 0;;
    for(int i=0;i<n;i++){
	if(res < ans[i]){
	    res = ans[i];
	    ansnum = i + 1;
	}
    }

    cout << ansnum << endl;
    }

    return 0;
}