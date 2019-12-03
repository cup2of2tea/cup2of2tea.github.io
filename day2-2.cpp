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

    vector<int> copie(v);
    for (int c = 0; c <= 99; c++)
    {
        for (int c2 = 0; c2 <= 99; c2++)
        {
            v[1] = c;
            v[2] = c2;
            current = 0;
            while (v[current] != 99)
            {

                if (v[current] == 1)
                {
                    v[v[current + 3]] = v[v[current + 1]] + v[v[current + 2]];
                }
                else if (v[current] == 2)
                {
                    v[v[current + 3]] = v[v[current + 1]] * v[v[current + 2]];
                }

                current += 4;
            }
            cout << v[0] << endl;
            if (v[0] == 19690720)
            {
                cout << c << " " << c2 << endl;
                return 0;
            }
            copy(copie.begin(), copie.end(), v.begin());
        }
    }
}
