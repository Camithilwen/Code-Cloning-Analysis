#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    string s;
    cin >> s;
    smatch smatch;
    if (regex_search(s,smatch,regex("^A[a-z]+C[a-z]+$")))
    {
        cout << "AC" << endl;
    }
    else
    {
        cout << "WA" << endl;
    }
}