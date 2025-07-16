#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
  int wc[10], wsum=0, kc[10], ksum=0;
  
  for(int i = 0 ; i < 10 ; i++) {
    cin >> wc[i];
  }
  for(int i = 0 ; i < 10 ; i++) {
    cin >> kc[i];
  }
  sort(wc, wc+10);
  sort(kc, kc+10);
  
  for(int i = 9 ; i > 6 ; i--) {
    wsum += wc[i];
    ksum += kc[i];
  }
  cout << wsum << ' ' << ksum << endl;
  return 0;
}