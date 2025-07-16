#include <iostream>
#include <string>
#include <queue>


using namespace std;

class Player{
private:
  int  base;

public:
  Player(int i){
    base=1;
  }


  void SetBase(int a){
    this->base =a;
  }

  int GetBase(){
    return this->base;
  }
};

class Baseball{
private:
  int score;
  int out;
  queue<Player> que;

public:
  Baseball(){
      score = out=0;
  }

  void add_hit(int num){
    Player one(1);
    this->que.push(one);
    int length=this->que.size();

    for(int i= 0;i<length;i++){
      Player tmp = this->que.front();
      this->que.pop();
      int tmp_base=tmp.GetBase();
      if((tmp_base+num)>4){
        score++;
      }else{
        tmp.SetBase(tmp_base+num);
        this->que.push(tmp);
      }
    }
  }

  void add_out(){
    this->out++;
  }

  void add_score(){
    this->score++;
  }

  int GetOut(){
    return this->out;
  }

  int GetScore(){
    return this->score;
  }

  void show_score(){
    cout<<this->score<<endl;
  }

};

int main(void){
  int time;
  cin >> time;

  for(int i=0;i<time;i++){
    Baseball baseball;
    while(baseball.GetOut()!=3){
      string judge;
      cin>>judge;
      if(judge == "HIT"){
        baseball.add_hit(1);
      }else if(judge=="OUT"){
        baseball.add_out();
      }else if(judge=="HOMERUN"){
        baseball.add_hit(4);
      }

    }

    cout<<baseball.GetScore()<<endl;
  }

  return 0;
}

