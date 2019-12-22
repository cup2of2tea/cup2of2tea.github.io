#include <bits/stdc++.h>

using namespace std;

vector<bool> modes(int s)
{
    vector<bool> res;
    for (int c = 0; c < 3; c++)
    {
        res.push_back(s % 10 == 0 ? false : true);
        s /= 10;
    }

    return res;
}

int main()
{
    vector<int> v;
    while (1)
    {
        int z;
        cin >> z;
        if (z == -4242)
            break;
        v.push_back(z);
    }

    int current = 0;

    int input = 1;
    bool debug = false;
    while (v[current] != 99)
    {
        vector<bool> m;
        m = modes(v[current] / 100);
        if (debug)
        {
            cout << "NEW LINE =============" << endl;
            cout << v[current] << endl;
            for (int c = 0; c < m.size(); c++)
                cout << (m[c] ? "true" : "false") << " ";
            cout << endl;
        }

        int op = v[current] % 10;

        int par1 = (op > 2 ? v[current + 1] : (m[0] ? v[current + 1] : v[v[current + 1]]));
        int par2 = (op > 2 ? 0 : (m[1] ? v[current + 2] : v[v[current + 2]]));
        int par3 = (op > 2 ? 0 : v[current + 3]);
        if (debug)
            cout << op << " " << par1 << " " << par2 << " " << par3 << endl;

        if (op == 1)
        {
            v[par3] = par1 + par2;
            current += 4;
        }
        else if (op == 2)
        {
            v[par3] = par1 * par2;
            current += 4;
        }
        else if (op == 3)
        {
            v[par1] = input;
            current += 2;
        }
        else if (op == 4)
        {
            cout << v[par1] << endl;
            current += 2;
        }
    }
    //cout << v[0] << endl;
}
