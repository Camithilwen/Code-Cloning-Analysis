#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N,x;
    cin >> N >> x;
    int a;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> a;
        A.at(i) = a;
    }
    sort(A.begin(), A.end());
    int count=0;
    for(int i=0;i<N;i++){
        x = x - A.at(i);
        if((x>0)&&(i!=N-1)){
            count = count + 1;
        }
        else if(x==0){
            count = count + 1;
        }
        
        else{
            break;
        }
    }
    cout << count << endl;
}