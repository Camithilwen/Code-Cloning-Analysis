#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int k , n;
 cin >> k >> n;
 if(k % n == 0)cout << 0 << endl;
 else cout << 1 << endl;
}