#include <iostream>
using namespace std;

int main(){
    while(1){
        int n, nums[10] = {0};
        cin >> n;
        if(!n) break;

        for(int i = 0;i < n;i++){
            int k;
            cin >> k;
            nums[k]++;
        }

        for(int i = 0;i < 10;i++){
            if(nums[i] == 0) cout << "-";
            else{
                for(int j = 0;j < nums[i];j++) cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}