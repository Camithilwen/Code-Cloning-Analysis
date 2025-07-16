#include<iostream>
#include<vector>
using namespace std;

string in;
vector<string> V;

string change(string in){
  for(int i = 0; i < in.length(); i++){
    if(in[i] != 'a') in[i]--;
    else in[i] = 'z';
  }
  return in;
}
string solve(){
  int status = 0;
  while(1){
    for(int i = 0; i < V.size(); i++){
      string str = V[i];
      if(str != "." && str != " ") V[i] = change(str);
      if(V[i] == "the" || V[i] == "this" || V[i] == "that") status = 1;
    }
    if(status)break;
  }
  string out;
  for(int i = 0; i < V.size(); i++){
    out += V[i];
  }
  return out;
}
int main(){
  while(getline(cin,in)){
    V.clear();
    in += "\n";
    string str;
    for(int i = 0; i < in.length(); i++){
      if(in[i] < 'a' || in[i] > 'z'){
	V.push_back(str);
	str = "";
	if(in[i] == '.') V.push_back(".");
	if(in[i] == ' ') V.push_back(" ");
      }else str += in[i];
    }
    cout << solve() << endl;
  }
  return 0;
}