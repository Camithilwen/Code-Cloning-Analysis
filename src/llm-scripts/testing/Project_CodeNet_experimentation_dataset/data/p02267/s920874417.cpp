#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
  vector<int> S;
  int q = 0;
  int t = 0;
  int C = 0;
  int n = 0;
  int s = 0;


  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    S.push_back(s);
  }
  sort(S.begin(), S.end());

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s;
    int start = 0;
    int end = S.size();
    while (start < end) {
      // cout << start <<" "<< end << "\n";
      if (S[(int)((end + start)/2)] < s) {
	start = (int)((end+start)/2)+1;
      }else if(S[(int)((end + start)/2)] > s){
	end = (int)((end + start)/2);
      }
      else{
	C++;
	break;
      }
    }
      
  }
  cout << C << "\n";
  return 0;
}

