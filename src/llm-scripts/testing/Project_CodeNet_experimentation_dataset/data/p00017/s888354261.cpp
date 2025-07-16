#include <iostream>
#include <string>

using namespace std;

string line;
int str_len;

bool is_finish() {
  for(int i=0; i<str_len-3; i++) {
    if(line[i] == 't') {
      if(line[i+1] == 'h') {
        if(line[i+2] == 'e') { return true; }
        else if(line[i+2] == 'i' && line[i+3] == 's') { return true; }
        else if(line[i+2] == 'a' && line[i+3] == 't') { return true; }
      }
    }
  }
  return false;
};


int main() {
  while(getline(cin, line)) {
    str_len = line.length();

    for(int j=0; j<26; j++) {
      if(is_finish()) { 
        cout << line << endl;
        break; 
      }

      for(int j=0; j<str_len; j++) {
        if('a' <= line[j] && line[j] < 'z') {
          line[j] += 1;
        }
        else if(line[j] == 'z') {
          line[j] = 'a';
        }
      }
    }
  }
  return 0;
}