#include <bits/stdc++.h>

using namespace std;

int main()
{
    int res = 0;
    while (!cin.eof())
    {
        int z;
        cin >> z;
        if (z == -1)
            break;
        int current = z;
        while (current != 0)
        {
            int f = current / 3;
            f -= 2;
            if (f <= 0)
                break;
            res += f;
            current = f;
        }
    }
    cout << res;
}
