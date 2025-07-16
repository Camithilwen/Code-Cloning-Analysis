#include <iostream>
#include <climits>      // to use INT_MIN and INT_MAX
using namespace std;
typedef long long ll;

ll arr[100005];

ll gcd(ll a, ll b) {    // Euclidean algorithm
	if (b == 0) return a;
      return gcd(b, (a%b));
      // doing a%b will also help swap both numbers in the case b>a
}

bool multiples(ll N, ll K, ll min, ll max) {
      ll gcdRes = 0;
      
      // (1) CHECK FOR GCD IN ARRAY
      for(ll i=0; i<N; i++) {
            gcdRes = gcd(gcdRes, arr[i]);
      }

      // (2) CHECK IF TARGET K IS DIVISIBLE BY GCD
      bool flag = false;
      if(K % gcdRes != 0) {
            flag = true;
      }
      return flag;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      ll N, K, min = INT_MAX, max = INT_MIN;
      cin >> N >> K;

      for(int i=0; i<N; i++) {
            cin >> arr[i];
            
            if(arr[i] == K) { // box already contains target K
                  cout << "POSSIBLE" << endl;
                  exit(0);
            }
            if(arr[i] < min) min = arr[i];
            if(arr[i] > max) max = arr[i];
	}
      // If max (eg. 5) is less than target (eg. 10), 
      // Even if min=1 (smallest possible from constraints), abs diff will never reach target:
      if(max < K) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
      }
      if(multiples(N , K, min, max) == true){
		cout << "IMPOSSIBLE" << endl;
	}
	else cout << "POSSIBLE" << endl; 
}