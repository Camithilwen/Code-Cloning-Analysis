#include <iostream>
using namespace std;

int main() {
	int a,b,c,n,buhin[300],kensa[1000][4];
	while(1){
	for(int i = 0;i < 300;i++) buhin[i] = 2; 
	cin >> a >> b >> c >> n;
	if(a == 0 && b == 0 && c == 0) break;
	for(int i = 0;i < n;i++){
		cin >> kensa[i][0] >> kensa[i][1] >> kensa[i][2] >> kensa[i][3];
		if(kensa[i][3]){
			buhin[kensa[i][0] - 1] = 1;
			buhin[kensa[i][1] - 1] = 1;
			buhin[kensa[i][2] - 1] = 1;
		}
	}
	for(int i = 0;i < n;i++){
		if(!kensa[i][3]){
			if(buhin[kensa[i][0] - 1] == 1 && buhin[kensa[i][1] - 1] == 1) buhin[kensa[i][2] - 1] = 0;
			if(buhin[kensa[i][0] - 1] == 1 && buhin[kensa[i][2] - 1] == 1) buhin[kensa[i][1] - 1] = 0;
			if(buhin[kensa[i][2] - 1] == 1 && buhin[kensa[i][1] - 1] == 1) buhin[kensa[i][0] - 1] = 0;
		}
	}
	for(int i = 0;i < a + b + c;i++) cout << buhin[i] << endl;
	}
	return 0;
}