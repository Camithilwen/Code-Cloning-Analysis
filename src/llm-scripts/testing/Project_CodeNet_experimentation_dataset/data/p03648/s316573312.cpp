#include <iostream>

using namespace std ;

long long int arr[60] ;

int main()
{
    long long int k ;

    cin >> k ;

    // vorodi
    if (k == 0) {
        cout << 2 << endl;
        cout << 1 << " " << 1;
        return 0;
    }

    for(int i = 0 ; i < 50 ; i++)
        arr[i] = i ;

    for(int i = 0 ; i < 50 ; i++)
        arr[i] += (k) / 50 ;

    if (k % 50 != 0) {
        for(int i = 0 ; i < k % 50 ; i++)
        {
            arr[i] += 50 ;

            for(int j = 0 ; j < 50 ; j++)
                if(j != i)
                    arr[j]-- ;
        }
    }

    cout << 50 << endl ;
    for(int i = 0 ; i < 50 ; i++)
        cout << arr[i] << " " ;

    cout << endl ;
	return 0 ;
}
