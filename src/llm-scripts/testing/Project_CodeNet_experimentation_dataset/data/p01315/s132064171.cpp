#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(void){
  while(true){
    int n;
    cin >> n;
    if(n == 0){ break; }

    vector<pair<double, string> > moonlight;
    string l;
    int p, a, b, c, d, e, f, s, m;
    for(int i = 0; i < n; i++){
      cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      int income = f * m * s - p;
      int time = a + b + c + (d + e) * m;
      moonlight.push_back(make_pair(-income/(double)time, l));
    }
    sort(moonlight.begin(), moonlight.end());
    for(int i = 0; i < n; i++){ cout << moonlight[i].second << endl; }
    cout << "#" << endl;
  }

  return 0;
}