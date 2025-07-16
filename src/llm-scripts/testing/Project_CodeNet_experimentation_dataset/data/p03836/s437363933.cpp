#include <bits/stdc++.h>
using namespace std;

int moveX(vector<char>& str, int posX, int targetX)
{
    while(posX < targetX)
    {
        posX += 1;
        str.push_back('R');
    }
    while(targetX < posX)
    {
        posX -= 1;
        str.push_back('L');
    } 

    return posX;
}

int moveY(vector<char>& str, int posY, int targetY)
{
    while(posY < targetY)
    {
        posY += 1;
        str.push_back('U');
    }
    while(targetY < posY)
    {
        posY -= 1;
        str.push_back('D');
    }

    return posY;
}

int main() {
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int posX=sx;
    int posY=sy;
    vector<char> str;

    // step1
    posX = moveX(str, posX, tx);
    posY = moveY(str, posY, ty);
    
    // step2
    posX = moveX(str, posX, sx);
    posY = moveY(str, posY, sy);

    // final step
    if(sx < tx && sy < ty)
    {
        posX -= 1;
        str.push_back('L');
        posY = moveY(str, posY, ty+1);
        posX = moveX(str, posX, tx);
        posY = moveY(str, posY, ty);

        posX += 1;
        str.push_back('R');
        posY = moveY(str, posY, sy-1);
        posX = moveX(str, posX, sx);
        posY = moveY(str, posY, sy);
    }else if(tx < sx && sy < ty)
    {
        posX += 1;
        str.push_back('R');
        posY = moveY(str, posY, ty+1);
        posX = moveX(str, posX, tx);
        posY = moveY(str, posY, ty);       

        posX -= 1;
        str.push_back('L');
        posY = moveY(str, posY, sy-1);
        posX = moveX(str, posX, sx);
        posY = moveY(str, posY, sy);
    }else if(tx < sx && ty < sx)
    {
        posX += 1;
        str.push_back('R');
        posY = moveY(str, posY, ty-1);
        posX = moveX(str, posX, tx);
        posY = moveY(str, posY, ty);

        posX -= 1;
        str.push_back('L');
        posY = moveY(str, posY, sy+1);
        posX = moveX(str, posX, sx);
        posY = moveY(str, posY, sy);   
    }else
    {
        posX -= 1;
        str.push_back('L');
        posY = moveY(str, posY, ty-1);
        posX = moveX(str, posX, tx);
        posY = moveY(str, posY, ty);

        posX += 1;
        str.push_back('R');
        posY = moveY(str, posY, sy+1);
        posX = moveX(str, posX, sx);
        posY = moveY(str, posY, sy);   
    }
    
    for(int i=0; i<str.size(); i++) cout << str[i];
    cout << endl;

    return 0;
}