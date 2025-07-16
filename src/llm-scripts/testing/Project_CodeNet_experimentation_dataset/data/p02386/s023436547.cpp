#include<iostream>
using namespace std;
#include<string>

class dice
{
public:
    int F[6];
    int q1, q2;
    dice();
	void input();
    void roll_a();
    void roll_b();
    bool check(const dice& d);
    bool equal(const dice& d);
};

dice::dice(){}

void dice::input()
{
    int i;
    for(i = 0; i < 6; i++) cin >> F[i];
    q1 = F[0] + F[1] + F[2] + F[3] + F[4] + F[5];
    q2 = F[0] * F[5] + F[1] * F[4] + F[2] * F[3];
}

void dice::roll_a()
{
    int i;
    i = F[0]; F[0] = F[2]; F[2] = F[1]; F[1] = i;
    i = F[3]; F[3] = F[4]; F[4] = F[5]; F[5] = i;
}

void dice::roll_b()
{
    int i;
    i = F[0]; F[0] = F[5]; F[5] = i;
    i = F[1]; F[1] = F[3]; F[3] = i;
    i = F[2]; F[2] = F[4]; F[4] = i;
}
 
bool dice::check(const dice& d)
{
    int l, m;
    if((d.F[0] != F[0]) || (d.F[5] != F[5])) return false;

    for(l = 1; l <= 4; l++){
        for(m = 1; m <= 4; m++){
            if(d.F[m] != F[(l * m) % 5]) break;
        }
        if(m == 5) return true;
    }
    return false;
}

bool dice::equal(const dice& d)
{
    bool eq;
    if((q1 != d.q1) || (q2 != d.q2)) return false;
    for(int i = 0; i < 2; i++){
        eq = check(d);
        if(!eq){ roll_a(); eq = check(d); }
        if(!eq){ roll_a(); eq = check(d); }
        if(eq || i == 1) break;
        roll_b();
    }
    return eq;
}

int main()
{
    dice d[100];
    int n, i, j;

    cin >> n;
    for(i = 0; i < n; i++){ d[i].input(); }

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(d[i].equal(d[j])) break;
        }
        if(j < n) break;
    }
    if(i + j == 2 * n){ cout << "Yes"; }else{ cout << "No"; }
    cout << endl;

    return 0;
}