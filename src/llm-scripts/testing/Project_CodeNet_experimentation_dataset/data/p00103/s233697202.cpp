
#include <iostream>
#include <string>

class Baseball{
public:
    Baseball();
    void init();
    int getPoint();
    void hit();
    void homerun();
    // @return false - the inning ends.
    bool out();
    
private:
    int point;
    unsigned int outs;
    bool base[3];
};

Baseball::Baseball(){
    init();
}

void Baseball::init(){
    point = 0;
    outs = 0;
    for (int i=0; i<3; ++i) {
        base[i] = false;
    }
}

inline int Baseball::getPoint(){
    return point;
}

void Baseball::hit(){
    if (base[2]) {
        ++point;
    }
    for (int i=2; i>0; --i) {
        base[i] = base[i-1];
    }
    base[0] = true;
}

void Baseball::homerun(){
    ++point;    // batter's point
    // runner's point
    for (int i=0; i<3; ++i) {
        if (base[i]) {
            ++point;
        }
    }
    
    for (int i=0; i<3; ++i) {
        base[i] = false;
    }
}

bool Baseball::out(){
    ++outs;
    if (outs > 2) {
        return false;
    }else{
        return true;
    }
}


int main(){
    int n;  // number of data sets
    
    std::cin >> n;
    
    for (int i=0; i<n; ++i) {
        Baseball inning;
        std::string str;
        
        while (true) {
            std::getline(std::cin,str);
            if (str=="HIT"){
                inning.hit();
            }
            else if (str=="HOMERUN"){
                inning.homerun();
                
            }
            else if (str=="OUT"){
                if (!inning.out()) {
                    break;
                }
            }
        }
        
        // output
        std::cout << inning.getPoint() << std::endl;
    }
    
    return 0;
}