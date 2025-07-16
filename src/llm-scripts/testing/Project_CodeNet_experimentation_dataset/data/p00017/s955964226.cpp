#include<iostream>
#include<string>
#include<cstring>

bool find(const std::string &text, const std::string pattern){
	int text_i=0,pattern_i=0;
	while(text_i<text.size()&&pattern_i<pattern.size()){
		if(text[text_i]==pattern[pattern_i]) {
			text_i++;
			pattern_i++;
		}else{
			pattern_i=0;
			text_i=text_i-pattern_i+1;
		}
	}
	return (pattern_i==pattern.size()?true:false);
}


void decode( std::string &coded_data,int diff){
	for(int i=0;i<coded_data.size();i++){
		if(isalpha(coded_data[i])){
			coded_data[i]-=diff;
			if(!isalpha(coded_data[i])) coded_data[i]+=26;
		}
	}
}

int main(void){
	std::string coded_data;
	while(std::getline(std::cin,coded_data)){
		for(int i=0;i<26;i++){
			decode(coded_data,1);
			if(find(coded_data,"the") || find(coded_data,"this")||find(coded_data,"that"))
				std::cout<<coded_data<<std::endl;
		}
	}

	return 0;
}

