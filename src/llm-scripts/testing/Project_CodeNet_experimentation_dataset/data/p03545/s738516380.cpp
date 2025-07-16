#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string str;
    int A, B, C, D;
    int N[15];

    cin >> str;

    transform(begin(str), end(str), N, [](char c) {return c - '0'; });
    A = N[0];
    B = N[1];
    C = N[2];
    D = N[3];


    for (int i=0;i<2;++i) {
        for (int j=0;j<2;++j) {
            for (int k=0;k<2;++k) {
                int ans =0;
                string op1 = (i%2==0) ? "+" :"-";
                string op2 = (j%2==0) ? "+" :"-";
                string op3 = (k%2==0) ? "+" :"-";
                if (op1=="+") {
                    ans =A+B;
                }
                else {
                    ans = A-B;
                }
                if (op2=="+") {
                    ans +=C;
                }
                else {
                    ans -= C;
                }
                if (op3=="+") {
                    ans +=D;
                }
                else {
                    ans -= D;
                }
                if (ans==7) {
                    cout << A<<op1<<B<<op2<<C<<op3<<D<<"="<<7<<endl;
                    return 0;
                }



            }

        }
    }


}
