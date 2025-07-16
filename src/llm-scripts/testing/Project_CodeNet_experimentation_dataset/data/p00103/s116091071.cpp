#include <iostream>
#include <vector>
#include <algorithm>

class Baseball {
private:
	int out;
	int runner;
	int score;

public:
	//constructor
	Baseball() {
		out = 0; 
		runner = 0;
		score = 0;
	}

	//getter
	int getOut() { return out; }
	int getRunner() { return runner; }
	int getScore() { return score; }
	//input OUT
	void execOut() { ++out; }
	//input HIT
	void execHit() {
		if(runner == 3)++score;
		else ++runner;
	}
	//input HOMERUN
	void execHomerun() {
		score += runner + 1;
		runner = 0;
	}

};

int main(){
	int dataSetNum;
	std::cin >> dataSetNum;

	std::vector< Baseball > baseball;
	baseball.resize(dataSetNum);

	for(int i = 0; i < dataSetNum; ++i){

		while(baseball[i].getOut() != 3){
			//input
			std::string tmp;
			std::cin >> tmp;

			if(tmp == "OUT")baseball[i].execOut();
			else if(tmp == "HIT")baseball[i].execHit();
			else if(tmp == "HOMERUN")baseball[i].execHomerun();
		}

	}
	//output
	std::for_each(baseball.begin(), baseball.end(),
    [](Baseball x) { std::cout << x.getScore() << std::endl; } );

	return 0;
}