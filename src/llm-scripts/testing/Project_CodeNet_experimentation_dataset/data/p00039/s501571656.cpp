#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str;
	while(cin>>str){
		vector<int> Vec;
		for(int i=0; i < str.size();i++){
			if(str[i] == 'I'){
				Vec.push_back(1);
			}else if(str[i] == 'V'){
				Vec.push_back(5);
			}else if(str[i] == 'X'){
				Vec.push_back(10);
			}else if(str[i] == 'L'){
				Vec.push_back(50);
			}else if(str[i] == 'C'){
				Vec.push_back(100);
			}else if(str[i] == 'D'){
				Vec.push_back(500);
			}else if(str[i] == 'M'){
				Vec.push_back(1000);
			}
		}
		
		int sum=0;
		bool flag = false;
		for(int i=0;i<Vec.size()-1;i++){
			// 右側に大きな数が続くとき
			if( Vec[i] < Vec[i+1] ){
				sum += Vec[i+1] - Vec[i];
				// iを一つ進める
				i++;
				flag = true;
			}else{  // 右側に同じ又は小さな数
				sum += Vec[i];
				flag = false;
			}
		}
		// 最後まで足せていない場合は、最後だけ足す
		if( !flag ){
			sum += Vec[ Vec.size()-1 ];
		}
		
		cout<<sum<<endl;
	}
	return 0;
}