#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <map>
#include <string>
#include <valarray>
// #include <cctype>

using namespace std;

typedef pair<int, int> Coordinate;
typedef vector<Coordinate> Coordinates;

void output(const vector<int> &);
bool place(const vector<int> &, int pos);
void back_trace(vector<int> & queen, Coordinates & coordinates, int current, int total);
bool match(const vector<int> & queen, const Coordinates & coordinates);


int main()
{
    Coordinates coordinates;
    vector<int> queen(8);

    int n;
    cin >> n;

    coordinates.resize(n);

    int i = 0;
    while (i < n)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
        i++;
    }

    back_trace(queen, coordinates, 0, 8);

}


void output(const vector<int> & queen)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            if (queen[i] == j)
                cout << 'Q';
            else
                cout << '.';
        cout << endl;        
    }


}


bool place(const vector<int> & queen, int current)
{
    for (int i = 0; i < current; i++)
        if (queen[current]==queen[i] || abs(current-i)==abs(queen[current]-queen[i]))
            return false;
    return true;
}




void back_trace(vector<int> & queen, Coordinates & coordinates, int current, int total)
{
    if (current >= total)
    {
        if (match(queen, coordinates))
            output(queen);        
    }
    else
    {
        for (int i = 0; i < total; i++)
        {
            queen[current] = i;
            if (place(queen, current))
                back_trace(queen, coordinates, current+1, total);
        }
    }

}


bool match(const vector<int> & queen, const Coordinates & coordinates)
{
    for (int i = 0; i < coordinates.size(); i++)
    {
        if (queen[coordinates[i].first] != coordinates[i].second)
            return false;
    }
    return true;
}
