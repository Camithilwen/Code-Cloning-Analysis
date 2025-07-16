#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef pair<string, string> P;

P next_word(string sentence) {
  if (sentence.empty()) return make_pair(string(""), string(""));
  if (sentence[0] == ' ' || sentence[0] == '.') {
    return make_pair("", sentence.substr(1));
  } else {
    P recur = next_word(sentence.substr(1));
    return make_pair(sentence[0] + recur.first, recur.second);
  }
}

bool acceptable(string sentence) {
  P p = next_word(sentence);

  while (! p.first.empty() ) {
    if (p.first == "this" || p.first == "the" || p.first == "that")
      return true;

    p = next_word(p.second);
  }
  return false;
}

char slip(char c) {
  if (c < 'a' || 'z' < c) return c;
  
  string alphabet = "abcdefghijklmnopqrstuvwxyza";
  int index = (int)(c - 'a');
  return alphabet[index + 1];
}

char slip(char c, int n) {
  for (int i = 0; i < n; i++)
    c = slip(c);

  return c;
}

string slip(string code, int n) {
  string val;
  for (int i = 0, len = code.length(); i < len; i++)
    val += slip(code[i], n);

  return val;
}

string decode(string code) {
  for (int i = 1; i < 27; i++) {
    string sentence = slip(code, i);
    if (acceptable(sentence))
      return sentence;
  }

  return "";
}

int main() {
  string code;
  while ( getline(cin, code) )
    cout << decode(code) << endl;
}