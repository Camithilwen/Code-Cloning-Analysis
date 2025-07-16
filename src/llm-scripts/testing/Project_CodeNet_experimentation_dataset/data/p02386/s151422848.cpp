#include<iostream>

using namespace std;

class Dice{
  private:
    int d_1,d_2,d_3,d_4,d_5,d_6;
  public:
    void setDice(int a,int b,int c,int d,int e,int f){
      d_1 = a;
      d_2 = b;
      d_3 = c;
      d_4 = d;
      d_5 = e;
      d_6 = f;
    }
    void roll_w(){
      int tmp = d_1;
      d_1 = d_3;
      d_3 = d_6;
      d_6 = d_4;
      d_4 = tmp;
    }
    void roll_e(){
      int tmp = d_1;
      d_1 = d_4;
      d_4 = d_6;
      d_6 = d_3;
      d_3 = tmp;
    }
    void roll_n(){
      int tmp = d_1;
      d_1 = d_2;
      d_2 = d_6;
      d_6 = d_5;
      d_5 = tmp;
    }
    void roll_s(){
      int tmp = d_5;
      d_5 = d_6;
      d_6 = d_2;
      d_2 = d_1;
      d_1 = tmp;
    }

    void spin(){
      int tmp = d_2;
      d_2 = d_3;
      d_3 = d_5;
      d_5 = d_4;
      d_4 = tmp;
    }

    int findRight(int top,int front){
      for(int i=0;i < 6;i++){
        for(int j=0;j < 4;j++){
          if((*this).d_1 == top && (*this).d_2 == front) return (*this).d_3;
          (*this).spin();
        }
        if(i % 2 == 0)
        (*this).roll_n();
        else
        (*this).roll_w();
      }
      return -1;
    }

    bool cmpDice(Dice d2){
      for(int i=0;i < 6;i++){
        for(int j=0;j < 4;j++){
          if((*this).d_1 == d2.d_1 && (*this).d_2 == d2.d_2 && (*this).d_3 == d2.d_3
          && (*this).d_4 == d2.d_4 && (*this).d_5 == d2.d_5 && (*this).d_6 == d2.d_6){
            return true;
          }
          d2.spin();
        }
        if(i % 2 == 0) d2.roll_n();
        else d2.roll_w();
      }
      return false;
    }

    int getDice(){
      return d_1;
    }

};

int main(){
  int n;
  int a,b,c,d,e,f;
  bool ok = true;
  Dice D[100];
  cin >> n;
  for(int i=0;i < n;i++){
    cin >> a >> b >> c >> d >> e >> f;
    D[i].setDice(a,b,c,d,e,f);
  }
  for(int i=0;i < n;i++){
    for(int j=0;j < n;j++){
      if(i==j) continue;
      if(D[i].cmpDice(D[j])){
        ok = false;
        break;
      }
    }
    if(!ok) break;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
