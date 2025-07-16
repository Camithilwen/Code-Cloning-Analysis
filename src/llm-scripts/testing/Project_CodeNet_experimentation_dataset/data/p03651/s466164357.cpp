# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define ll long long

int fpb(int a, int b){
  return (b == 0 ? a : fpb(b, a%b));
}

int main(){
 
  int n, k;
  cin >> n >> k;
  int f = 0, largest = 0;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    largest = max(largest, num);
    f = fpb(f, num);
  }  
  
  if (k <= largest && k % f == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
} 

