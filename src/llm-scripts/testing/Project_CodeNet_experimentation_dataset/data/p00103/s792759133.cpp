#include <iostream>
#include <string>

//class
class Baseball{
public:
	int firstbase, secondbase, thirdbase;
	int inningNumber, out, score;

	Baseball(int num){
		inningNumber = num;
		firstbase = 0;
		secondbase = 0;
		thirdbase = 0;
		out = 0;
		score = 0;
	}

	void playball(){
		for(int i = 0; i < inningNumber; ++i)
			inning();
	}

	void inning(){
		out = 0;
		firstbase = 0;
		secondbase = 0;
		thirdbase = 0;
		score = 0;

		while(out != 3){
			std::string str;
			std::cin >> str;

			if(str == "HIT")
				hit();
			if(str == "HOMERUN")
				homerun();
			if(str == "OUT")
				out++;
		}

		std::cout << score << std::endl;
	}

	void hit(){
		score += thirdbase;
		thirdbase = secondbase;
		secondbase = firstbase;
		firstbase = 1;
	}

	void homerun(){
		score += thirdbase + secondbase + firstbase + 1;
		firstbase = 0;
		secondbase = 0;
		thirdbase = 0;
	}
};
//main
int main(){
	int n;
	std::cin >> n;
	
	Baseball *baseball = new Baseball(n);
	baseball->playball();
	delete baseball;

	return 0;
}
