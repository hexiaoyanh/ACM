//
// Created by mika on 18-6-12.
//

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int num, s;
        cin >> num >> s;
        int flag = 0;
        if (num <= s)
            flag = 1;
        for (int i = 0; i < s; ++i)
        {
            int a, b;
            cin >> a >> b;
        }
        if (flag)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
    }
}