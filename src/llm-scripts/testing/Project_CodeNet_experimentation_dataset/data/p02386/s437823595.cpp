#include <iostream>
#include <sstream>
using namespace std;

class Dice {
public:
    static int rollingface[][4];
    static int sideface[][4];
    int face[6];

    Dice(string &face_data);
    // ~Dice();
    void roll(const char &op);
    int top();
    int front_face(int top, int right);
    void print_faces();
    bool operator==(const Dice& other);
};

int Dice::rollingface[][4] = {
    {0, 2, 5, 3},
    {0, 4, 5, 1},
    {0, 1, 5, 4},
    {0, 3, 5, 2},
};

int Dice::sideface[][4] = {
    {1, 3, 4, 2},
    {0, 2, 5, 3},
    {0, 4, 5, 1},
    {0, 1, 5, 4},
    {0, 3, 5, 2},
    {1, 2, 4, 3},
};

Dice::Dice(string &face_data) {
    istringstream strm;
    strm.str(face_data);
    for (int i = 0; i < 6; i++) {
        strm >> face[i];
    }
}

void Dice::roll(const char &op) {
    int *fseq;
    switch (op) {
        case 'E': fseq = Dice::rollingface[0]; break;
        case 'N': fseq = Dice::rollingface[1]; break;
        case 'S': fseq = Dice::rollingface[2]; break;
        case 'W': fseq = Dice::rollingface[3]; break;
        default: break;
    }
    int t, p = face[fseq[3]];
    for (int i = 0; i < 4; i++) {
        t = face[fseq[i]];
        face[fseq[i]] = p;
        p = t;
    }
}

int Dice::front_face(int top, int right) {
    int i;
    for (i = 0; i < 6; i++) {
        if (face[i] == top) break;
    }
    int *fseq = Dice::sideface[i];
    for (i = 0; i < 4; i++) {
        if (face[fseq[i]] == right) return face[fseq[(i-1+4)%4]];
    }
    return -1;
}

void Dice::print_faces() {
    cout << "face:" << endl;
    cout << "   " << face[4] << endl;
    cout << face[3] << " " << face[0] << " " << face[2] << endl;
    cout << "   " << face[1] << endl;
    cout << "   " << face[5] << endl;
    cout << endl;
}

bool Dice::operator==(const Dice& other) {
    int i;
    for (i = 0; i < 6; i++) {
        if (other.face[i] == face[0]) {
            if (other.face[5-i] != face[5]) continue;
            int *f = Dice::sideface[0], *of = Dice::sideface[i];
            for (int j = 0; j < 4; j++) {
                if (face[f[0]] == other.face[of[j]]) {
                    for (int k = 1; k < 4; k++) {
                        if (face[f[k]] != other.face[of[(j+k)%4]]) goto NOT_MATCH;
                    }
                    return true;
                }
            }
            NOT_MATCH:;
        }
    }
    return false;
}

int Dice::top() {
    return face[0];
}

int main() {
    int n, i;
    string buf;
    istringstream strm;
    Dice *dice[100];

    getline(cin, buf);
    strm.str(buf);
    strm >> n;
    for (i = 0; i < n; i++) {
        getline(cin, buf);
        dice[i] = new Dice(buf);
    }
    
    for (i = 0; i < n-1; i++) {
        Dice *s = dice[i];
        for (int j = i + 1; j < n; j++) {
            if (*s == *dice[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}