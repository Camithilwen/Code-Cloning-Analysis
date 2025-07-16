#include <iostream>
#include <string>

class Baseball{
private:
	int point;
	int out_count;
	int runner;
public:
	Baseball();
	void singleHit();
	void homerun();
	void out();
	void new_inning();
	int get_out_count();
	int get_point();
	~Baseball() = default;
};

Baseball::Baseball(){
	new_inning();
}

void Baseball::singleHit(){
	if(runner < 3){
		++runner;
	}
	else if(runner == 3){
		++point;
	}
}

void Baseball::homerun(){
	point += runner + 1;
	runner = 0;

}

void Baseball::out(){
	++out_count;
}

void Baseball::new_inning(){
	point = 0;
	out_count = 0;
	runner = 0;
}

int Baseball::get_out_count(){
	return out_count;
}

int Baseball::get_point(){
	return point;
}

int main(){
	int num;
	std::cin >> num; //data set number
	Baseball baseball;
	std::string event;
	
	for(int i=0; i<num; ++i){
		baseball.new_inning();
		
		while(baseball.get_out_count() < 3){
			std::cin >> event;
			
			if(event == "HIT"){
				baseball.singleHit();
			}
			else if(event == "HOMERUN"){
				baseball.homerun();
			}
			else if(event == "OUT"){
				baseball.out();
			}
		}
		//output
		std::cout << baseball.get_point() << std::endl;
	}

}