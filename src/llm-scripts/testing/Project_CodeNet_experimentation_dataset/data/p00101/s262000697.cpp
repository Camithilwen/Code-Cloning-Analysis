#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n;
  string line;
  cin >> n;
  getline(cin, line);
  while(n--){
    int p;
    getline(cin, line);
    while((p = line.find("Hoshino")) != -1){
      line[p+6] = 'a';
    }
    cout << line << endl;
  }
  return 0;
}