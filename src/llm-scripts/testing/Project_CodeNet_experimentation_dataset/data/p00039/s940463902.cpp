#include<iostream>
#include<string>
using namespace std;


int main(){
  int sum,i,j,kari;
  string data;
  while(getline(cin, data)) {
    data = data.insert(data.length(), "KKKKKK");
    sum = j = 0;
    
    for(j = 0; j < data.length(); j++) {
      if(data[j] == 'M'){
	sum += 1000;
      }else if(data[j] == 'D'){
	if(data[j + 1] == 'M'){
	  sum += 900;
	    j++;
	}else{
	  sum += 500;
	}
      }else if(data[j] == 'C'){
	if(data[j + 1] == 'D' || data[j + 1] == 'M'){
	  if(data[j + 1] == 'D'){
	    sum += 400;
	    j++;
	  }else{
	    sum += 900;
	    j++;
	  }
	}else{
	  sum += 100;
	}
      }else if(data[j] == 'L'){
	sum += 50;
      }else if(data[j] == 'X'){
	if(data[j+1] == 'L' || data[j+1] == 'C'){
	  if(data[j+1] == 'L'){
	    sum += 40;
	    j++;
	  }else{
	    sum += 90;
	    j++;
	  }
	}else{
	  sum += 10;
	}
      }else if(data[j] == 'V'){
	sum += 5;
      }else if(data[j] == 'I'){
	if(data[j + 1] == 'V' || data[j + 1] == 'X'){
	  if(data[j + 1] == 'V'){
	    sum += 4;
	    j++;
	  }else{
	    sum += 9;
	    j++;
	  }
	}
	else{
	  sum += 1;
	}
      }
    }
    
    cout << sum << endl;
  }
  
  return 0;
}