#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    
    /*
    string s1;
    getline( cin, s1 );
    int n1 = s1.size();
    */
    int a, b;
    cin >> a >> b ;
    
    if( 2*a <= 16 && 2*b <= 16 ){
        cout << "Yay!" << endl;
    }
    else {
        cout << ":(" << endl;
    }
      
    return 0;
}
