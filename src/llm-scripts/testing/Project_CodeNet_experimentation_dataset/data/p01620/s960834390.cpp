#include <iostream>
#include <vector>
#include <string>
using namespace std;

char Decryption(int k, char s) {
  char station[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                    'n','o','p','q','r','s','t','u','v','w','x','y','z',
                    'A','B','C','D','E','F','G','H','I','J','K','L','M',
                    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  int num;

  for(int i = 0; i < 52; i++) {
    if(s >= 'a' && s <= 'z')
      num = s - 'a';
    else
      num = s - 39;
  }
  return station[(52 + num - k) % 52];
}

int main() {
  vector<int> K;
  int n;
  string s_in;
  string s_out;

  while(1) {
    cin >> n;
    if(n == 0)
      break;

    for(int i = 0; i < n; i++) {
      int k;
      cin >> k;
      K.push_back(k);
    }

    cin >> s_in;

    for(int i = 0; i < s_in.size(); i++) {
      s_out += Decryption(K[i%n], s_in[i]);
    }

    cout << s_out << endl;

    s_out.erase();
    K.clear();
  }
  return 0;
}

