#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    string a,b,c;cin>>a>>b>>c;
    int acc = 0;
    for (int i=0;i<n;i++){
        vector<char> letters;
        letters.push_back(a[i]);
        letters.push_back(b[i]);
        letters.push_back(c[i]);

        sort(letters.begin(), letters.end());
        letters.erase(unique(letters.begin(), letters.end()), letters.end());
        if (letters.size() == 2){
            acc++;
        } else if (letters.size() == 3){
            acc += 2;
        }
    }
    cout << acc << endl;
    return 0;


}