#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    while (1)
    {
        int z;
        cin >> z;
        if (z == -1)
            break;
        v.push_back(z);
    }

    int current = 0;

    v[1] = 12;
    v[2] = 2;

    while (v[current] != 99)
    {

        if (v[current] == 1)
        {
            v[v[current + 3]] = v[v[current + 1]] + v[v[current + 2]];
            current += 4;
        }
        else if (v[current] == 2)
        {
            v[v[current + 3]] = v[v[current + 1]] * v[v[current + 2]];
            current += 4;
        }
    }
    cout << v[0] << endl;
}
