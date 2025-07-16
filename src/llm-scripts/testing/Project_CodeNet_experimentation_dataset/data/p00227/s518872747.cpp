#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,sum;
    int p[1010];
    
    while(cin >> n >> m,n!=0&&m!=0){
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        sort(p,p+n);
        reverse(p,p+n);
        sum = 0;
        for(int i=0;i<n;i++){
            if( (i+1)%m != 0) sum += p[i];
        }
        cout << sum << endl;
    }
    return 0;
}

