#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    for (int i = n-1; i>=1; i--){
        cout << a[i] << " ";
    }
    cout <<a[0]<< endl;

}
