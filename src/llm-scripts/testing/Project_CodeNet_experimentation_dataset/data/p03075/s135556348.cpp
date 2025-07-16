//
//  main.cpp
//  usaco
//
//  Created by 김현수 on 2020/08/30.
//  Copyright © 2020 김현수. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
int main()
{
    int a, b, c, d, e, k;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k);
    if(e-a<=k)
    {
        printf("Yay!");
    }
    else if(e-a>k)
    {
        printf(":(");
    }
}
