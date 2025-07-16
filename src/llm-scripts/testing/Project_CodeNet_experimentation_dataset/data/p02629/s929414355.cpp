#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;

long double a = 25.0;
long double b = 26.0;
long double c = 1.0;

long long seek(long long Ntemp){

    long double X = a*( (long double)  Ntemp ) + b ;

    return (long long) ceil( log10(X)/log10(b) - c );
}

int main(){
    long long N;
    cin >> N;

    string S;

    long long n = seek(N);
    N = N - ( (long long) ( pow(b, ((long double) n) ) - b + eps ) /a );

    //cout << "N n " << N << " " << n << endl;

    // # S is n characters

    long long ntemp = n;

    for(int i=0; i<n; i++){
        ntemp = ntemp - 1;
        long long A = (long long) ( pow( b, (long double) (ntemp) ) + eps );
        int ctmp = (int) ( (N-1)/A );

        char ctmp2 = 'a' + ctmp;

        S.push_back(ctmp2);
        
        //cout << "i ntemp  A ctmp N S " << i << " " << ntemp << " " << A << " " << ctmp << " " << N << " " << S << endl; 
        N = N - ( (long long) ctmp )*A;
    }

    cout << S << endl;

    return 0;
}