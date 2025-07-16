# include <iostream>
# include <deque>
using namespace std;

string X;
deque<char> dchar;

int main()
{
    cin>>X;

    for (int i=0; i<X.size(); i++)
    {
        dchar.push_back(X[i]);

        if (dchar.size()>=2 && dchar[dchar.size()-2]=='S' && dchar[dchar.size()-1]=='T')
        {
            dchar.pop_back();
            dchar.pop_back();
        }
    }

    cout<<dchar.size()<<endl;
}