#include <iostream>

using namespace std;

int harshad(int n)  {
    int res = 0;
    while (n > 0)   {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()  {
    int n;
    cin >> n;
    int sum_of_digits = harshad(n);
    if (n % sum_of_digits == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}