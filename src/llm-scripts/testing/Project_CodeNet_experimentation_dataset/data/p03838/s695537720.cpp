#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  // 入力終了

  // 1.初めにBを押すか押さないか決める
  // 2.Aを0回以上押す
  // 3.最後にBを押すか押さないか決める
  int firstB[2] = {-1, 1}, secondB[2] = {-1, 1};

  int ans = 2000000000;
  int tmpx, tmpy;
  rep(i, 2){
    rep(j, 2){
      int tmp = 0;
      // 初めにBを押すなら-xを代入，押さないならxを代入
      tmpx = x*firstB[i];
      if(firstB[i] == -1)
	tmp++;
      // 最後にBを押すなら-yを代入，押さないならyを代入
      tmpy = y*secondB[j];
      if(secondB[j] == -1)
	tmp++;
      
      // tmpx > tmpyなら，Aを押しても題意を満たさない
      if(tmpx > tmpy)
	continue;

      // tmpxからtmpyまでAを押す
      tmp = tmp + tmpy - tmpx;
      ans = min(ans, tmp);
    }
  }

  // 解答
  cout << ans << endl;

  return 0;
}
