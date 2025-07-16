#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<int> array;

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        array.push_back(a);
    }

    for(int i=array.size()-1; i>=1; i--){
        cout << array[i] << " ";
    }cout << array[0] << endl;

    return 0;
}
    