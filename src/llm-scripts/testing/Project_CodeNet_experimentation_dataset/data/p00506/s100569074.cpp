#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int num[3];

    cin >> n;
    
    if (n == 2){
        cin >> num[0] >> num[1];
        sort(num, num + 1);
        for (int i = 1; i < num[0]; i++){
            if (num[0] % i == 0 && num[1] % i == 0){
                cout << i << endl;
            }
        }
    }

    else if (n == 3){
        cin >> num[0] >> num[1] >> num[2];
        sort(num, num + 3);
        for (int i = 1; i < num[0]; i++){
            if (num[0] % i == 0 && num[1] % i == 0 && num[2] % i == 0){
                cout << i << endl;
            }
        }
    }
    return (0);
}

