#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    vector<int> t1,t2;
    int input = 0;
    
    for(int i = 0;i < 6;i++){
        if(i < 4){
            cin >> input;
            t1.push_back(input);
        }else{
            cin >> input;
            t2.push_back(input);
        }
    }
    
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    
    int result = t1[3] + t1[2] + t1[1] + t2[1];
    cout << result << endl;
    
    return 0;
}