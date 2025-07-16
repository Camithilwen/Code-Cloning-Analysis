#include <bits/stdc++.h>
using namespace std;

class dice{
public:
	int init_label[6];
    int label[6];
    int tmp1, tmp2;
    int order[4] = {1,2,4,3};
	void setnumber(){
		for(int i=0; i<6; i++)
			cin >> init_label[i];
    }

    int check(int over, int front, int right, int left, int back, int bottom){
    	for(int i=0; i<4; i++){
    		if(over == label[0] && front == label[order[i]] && right == label[order[(i+1)%4]] && back == label[order[(i+2)%4]] && left == label[order[(i+3)%4]] && bottom == label[5]){
            cout << "No" << endl;
    		return 1;
    		}
    	}
    	return 0;
    }
    	
    void rotation(string sign){
            tmp1 = label[0];
            tmp2 = label[5];
            if(sign == "N"){
                label[0] = label[1];
                label[5] = label[4];
                label[1] = tmp2;
                label[4] = tmp1;
            }
            if(sign == "S"){
                label[0] = label[4];
                label[5] = label[1];
                label[4] = tmp2;
                label[1] = tmp1;
            }
            if(sign == "W"){
                label[0] = label[2];
                label[5] = label[3];
                label[2] = tmp2;
                label[3] = tmp1;
            }
            if(sign == "E"){
                label[0] = label[3];
                label[5] = label[2];
                label[3] = tmp2;
                label[2] = tmp1;
            }
            if(sign == "NN"){
            	label[0] = tmp2;
            	label[5] = tmp1;
            	int tmp3 = label[4];
            	label[4] = label[1];
            	label[1] = tmp3;
            }
        }

    void initialization(void){
    	for(int i=0; i<6; i++){
    		label[i] = init_label[i];
    	}
    }
};

int main(){
    int n; cin >> n;
	vector<dice> d(n);
	for(int i=0; i<n; i++){
        d[i].setnumber();
    }
	string rot_info[6] = {"","N","W","E","S","NN"};
	int flag=0;
        for(int i=0; i<n; i++){
            d[i].initialization();
            for(int k=i+1; k<n; k++){
    		      for(int j=0; j<6; j++){
                        d[k].initialization();
                        d[k].rotation(rot_info[j]);
                        flag = d[k].check(d[i].label[0],d[i].label[1],d[i].label[2],d[i].label[3],d[i].label[4],d[i].label[5]);
                        if(flag == 1)
				            break;
                }
                if(flag == 1)
                    break;
            }
            if(flag == 1)
                break;
        }
    if(flag == 0)
        cout << "Yes" << endl;
	
    return 0;
}