//
// Created by mika on 18-6-11.
//

#include<bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;
#define MAX 100005
bool s[MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    int a, b, i, len, num, v;
    for (i = 0; i < 100001; ++i) s[i] = false;
    len = 0, num = 0, v = 0;
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        if (a == 0 && b == 0)
        {
            if (v == 0)
            {
                printf("Yes\n");
                continue;
            }
            if (num == len - 1)
                printf("Yes\n");
            else
                printf("No\n");
            num = len = v = 0;
            memset(s, false, sizeof(s));
            continue;
        }
        v = 1;
        if (!s[a])
            len++;
        if (!s[b])
            len++;
        s[a] = s[b] = true;
        num++;
    }
}


