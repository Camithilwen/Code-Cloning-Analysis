#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Dice{
public:
	long top, front, right, left, back, bottom;
	Dice(long top, long front, long right, long left, long back, long bottom);
	void north();
	void south();
	void west();
	void east();
	void rightTurn();
	void ChangeTop(long top);
};

Dice::Dice(long top, long front, long right, long left, long back, long bottom){
	this->top = top;
	this->front = front;
	this->right = right;
	this->left = left;
	this->back = back;
	this->bottom = bottom;
}

void Dice::north(){
	long sv[6];
	sv[0] = this->front;
	sv[1] = this->bottom;
	sv[2] = this->right;
	sv[3] = this->left;
	sv[4] = this->top;
	sv[5] = this->back;

	this->top = sv[0];
	this->front = sv[1];
	this->right = sv[2];
	this->left = sv[3];
	this->back = sv[4];
	this->bottom = sv[5];
}

void Dice::south(){
	long sv[6];
	sv[0] = this->back;
	sv[1] = this->top;
	sv[2] = this->right;
	sv[3] = this->left;
	sv[4] = this->bottom;
	sv[5] = this->front;

	this->top = sv[0];
	this->front = sv[1];
	this->right = sv[2];
	this->left = sv[3];
	this->back = sv[4];
	this->bottom = sv[5];
}

void Dice::west(){
	long sv[6];
	sv[0] = this->right;
	sv[1] = this->front;
	sv[2] = this->bottom;
	sv[3] = this->top;
	sv[4] = this->back;
	sv[5] = this->left;

	this->top = sv[0];
	this->front = sv[1];
	this->right = sv[2];
	this->left = sv[3];
	this->back = sv[4];
	this->bottom = sv[5];
}

void Dice::east(){
	long sv[6];
	sv[0] = this->left;
	sv[1] = this->front;
	sv[2] = this->top;
	sv[3] = this->bottom;
	sv[4] = this->back;
	sv[5] = this->right;

	this->top = sv[0];
	this->front = sv[1];
	this->right = sv[2];
	this->left = sv[3];
	this->back = sv[4];
	this->bottom = sv[5];
}

void Dice::rightTurn(){
	long vs[4];
	vs[0] = this->left;
	vs[1] = this->right;
	vs[2] = this->front;
	vs[3] = this->back;
	this->left = vs[2];
	this->right = vs[3];
	this->front = vs[1];
	this->back = vs[0];
}

void Dice::ChangeTop(long top){
	if (top == this->top) return;
	else if (top == this->back) Dice::south();
	else if (top == this->front) Dice::north();
	else if (top == this->left) Dice::east();
	else if (top == this->right) Dice::west();
	else for (long i = 0; i < 2; i++) Dice::north();
	return;
}

int main(){
	bool judge = 1;
	long n;
	cin >> n;
	//n = 4;
	vector< vector<long> > roll(n);
	for (long i = 0; i < n; i++){
		roll[i].resize(6);
		cin >> roll[i][0] >> roll[i][1] >> roll[i][2] >> roll[i][3] >> roll[i][4] >> roll[i][5];
	}
	/*
	roll[0][0] = 1;
	roll[0][1] = 2;
	roll[0][2] = 3;
	roll[0][3] = 4;
	roll[0][4] = 5;
	roll[0][5] = 6;
	roll[1][0] = 1;
	roll[1][1] = 2;
	roll[1][2] = 3;
	roll[1][3] = 4;
	roll[1][4] = 5;
	roll[1][5] = 7;
	roll[2][0] = 6;
	roll[2][1] = 2;
	roll[2][2] = 3;
	roll[2][3] = 4;
	roll[2][4] = 5;
	roll[2][5] = 1;
	roll[3][0] = 2;
	roll[3][1] = 4;
	roll[3][2] = 5;
	roll[3][3] = 6;
	roll[3][4] = 3;
	roll[3][5] = 1;
	*/
	for (long i = 0; i < n; i++){
		for (long j = i + 1; j < n; j++){
			long isum = 0, jsum = 0;
			for (long k = 0; k < 6; k++){
				isum += roll[i][k];
				jsum += roll[j][k];
			}
			//cout << isum << " " << jsum << endl;
			if (isum != jsum) continue;
			Dice *di, *dj;
			di = new Dice(roll[i][0], roll[i][1], roll[i][2], roll[i][3], roll[i][4], roll[i][5]);
			dj = new Dice(roll[j][0], roll[j][1], roll[j][2], roll[j][3], roll[j][4], roll[j][5]);
			di->ChangeTop(roll[0][0]);
			dj->ChangeTop(roll[0][0]);
			//cout << di->top << " " << dj->top << endl;
			for (long k = 0; k < 3; k++) if (di->front != dj->front) dj->rightTurn();
			//cout << di->front << " " << dj->front << endl;
			if (di->top == dj->top && di->front == dj->front && di->right == dj->right && di->left == dj->left && di->back == dj->back && di->bottom == dj->bottom){
				//cout << i << " " << j << endl;
				judge = 0;
				break;
			}
			delete di;
			delete dj;
		}
		if (judge == 0) break;
	}
	if (judge == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}