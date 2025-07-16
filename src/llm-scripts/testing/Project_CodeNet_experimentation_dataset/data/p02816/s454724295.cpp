        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
           int n;
           cin>>n;
           int a[n],b[n];
           for(int i=0;i<n;i++)cin>>a[i];
           for(int i=0;i<n;i++)cin>>b[i];
           int x[3*n],y[3*n];
           for(int i=0;i<n;i++)x[i]=b[i%n]^(b[(i+1)%n]);
           for(int i=0;i<n;i++){
               x[i+n]=a[i%n]^a[(i+1)%n];
               x[i+2*n]=a[i%n]^a[(i+1)%n];
           }
           y[0] = 3*n;
int i = 1, j = 0;
while (i < 3*n) {
  while (i+j < 3*n && x[j] == x[i+j]) ++j;
  y[i] = j;
  if (j == 0) { ++i; continue;}
  int k = 1;
  while (i+k < 3*n && k+y[k] < j) y[i+k] = y[k], ++k;
  i += k; j -= k;
}
for(int i=n;i<2*n;i++){
    if(y[i]>=n)cout<<i-n<<' '<<(a[i-n]^b[0])<<endl;
}

         return 0;

        }
