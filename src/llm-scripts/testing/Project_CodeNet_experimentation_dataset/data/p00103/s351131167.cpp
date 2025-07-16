#include <string>
#include <iostream>
#include <map>

class Baseball{
    private:
        int score;
        int out;
        int runner;
        int inning;

    public:
        Baseball(); //コンストラクタ
        int getScore() { return score; }
        int addScore(int score) { score += score; }
        int getInning() { return inning; }
        bool addOut(); //アウトを加える，チェンジならtrue
        void moveOnRunner(); //ヒット時にランナーを進塁させる
        void slamHomeRun(); //ホームランを打ったとき
        void changeInning(); //イニングを変える，スコア, ランナーも0に戻す
};
Baseball::Baseball(){
    score = 0;
    out = 0;
    runner = 0;
    inning = 1;
}

bool Baseball::addOut(){
    out = (out + 1) % 3;
    return out == 0 ? true : false;
}

void Baseball::moveOnRunner(){
    if(runner < 3){
        runner++;
    } else if(runner == 3){
        runner = 3;
        score += 1;
    }
}

void Baseball::slamHomeRun(){
    score += (runner + 1);
    runner = 0;
}

void Baseball::changeInning(){
    score = 0;
    runner = 0;
    inning += 1;
}

int main(){
    Baseball b;
    int totalInning = 0;
    bool change_flag = false;
    std :: string event;
    std :: map<std :: string, int> map;

    map["HIT"] = 1;
    map["HOMERUN"] = 2;
    map["OUT"] = 3;

    std :: cin >> totalInning;
    std :: getline(std :: cin, event);
    while(b.getInning() <= totalInning){
        std :: getline(std :: cin, event);
        switch(map[event]){
            case 1:
                b.moveOnRunner();
                break;
            case 2:
                b.slamHomeRun();
                break;
            case 3:
                change_flag = b.addOut();
                break;
            default:
                break;
        }
        if(change_flag) {
            std :: cout << b.getScore() << std :: endl;
            b.changeInning();
            change_flag = false;
        }
    }
}
