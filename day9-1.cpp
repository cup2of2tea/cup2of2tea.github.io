#include <bits/stdc++.h>

using namespace std;

vector<int> modes(long long int s)
{
    vector<int> res;
    for (int c = 0; c < 3; c++)
    {
        res.push_back(s % 10);
        s /= 10;
    }

    return res;
}

int main()
{
    map<long long int, long long> v;
    long long i = 0;
    while (1)
    {
        long long int z;
        cin >> z;
        if (z == -4242)
            break;
        v[i++] = z;
    }

    long long int current = 0;
    long long base = 0;
    long long int input = 2;
    bool debug = false;

    int it = 0;
    while (v[current] != 99)
    {
        it++;
        vector<int> m;
        m = modes(v[current] / 100);
        //cout << v[current] << endl;
        if (debug)
        {
            cout << base << endl;
            for (auto z : v)
            {
                cout << z.second << " ";
            }
            cout << endl;
        }

        long long int op = v[current] % 100;

        /*if(op >= 5) {
            cout<<"?"<<endl;
            //return 0;
        }*/

        long long int ori1 = v[current + 1];
        long long int ori2 = v[current + 2];
        long long int ori3 = v[current + 3];

        long long par[3];

        for (int c = 0; c < 3; c++)
            if (m[c] == 0)
                par[c] = v[v[current + c + 1]];
            else if (m[c] == 1)
                par[c] = v[current + c + 1];
            else
                par[c] = v[base + v[current + c + 1]];

        if (op == 1)
        {
            if (m[2] == 0)
                v[v[current + 2 + 1]] = par[0] + par[1];
            else if (m[2] == 1)
                v[current + 2 + 1] = par[0] + par[1];
            else
                v[base + v[current + 2 + 1]] = par[0] + par[1];
            current += 4;
        }
        else if (op == 2)
        {
            if (m[2] == 0)
                v[v[current + 2 + 1]] = par[0] * par[1];
            else if (m[2] == 1)
                v[current + 2 + 1] = par[0] * par[1];
            else
                v[base + v[current + 2 + 1]] = par[0] * par[1];
            current += 4;
        }
        else if (op == 3)
        {

            if (m[0] == 0)
                v[v[current + 0 + 1]] = input;
            else if (m[0] == 1)
                v[current + 0 + 1] = input;
            else
                v[base + v[current + 0 + 1]] = input;
            current += 2;
        }
        else if (op == 4)
        {
            cout << current << " "
                 << "OUTPUT " << par[0] << endl;
            current += 2;
        }
        else if (op == 5)
        {
            if (par[0] != 0)
                current = par[1];
            else
                current += 3;
        }
        else if (op == 6)
        {
            if (par[0] == 0)
                current = par[1];
            else
                current += 3;
        }
        else if (op == 7)
        {
            if (par[0] < par[1])
            {
                if (m[2] == 0)
                    v[v[current + 2 + 1]] = 1;
                else if (m[2] == 1)
                    v[current + 2 + 1] = 1;
                else
                    v[base + v[current + 2 + 1]] = 1;
            }
            else
            {
                if (m[2] == 0)
                    v[v[current + 2 + 1]] = 0;
                else if (m[2] == 1)
                    v[current + 2 + 1] = 0;
                else
                    v[base + v[current + 2 + 1]] = 0;
            }
            current += 4;
        }
        else if (op == 8)
        {
            if (par[0] == par[1])
            {
                if (m[2] == 0)
                    v[v[current + 2 + 1]] = 1;
                else if (m[2] == 1)
                    v[current + 2 + 1] = 1;
                else
                    v[base + v[current + 2 + 1]] = 1;
            }
            else
            {
                if (m[2] == 0)
                    v[v[current + 2 + 1]] = 0;
                else if (m[2] == 1)
                    v[current + 2 + 1] = 0;
                else
                    v[base + v[current + 2 + 1]] = 0;
            }
            current += 4;
        }
        else if (op == 9)
        {
            base += par[0];
            current += 2;
        }
    }
    //cout << v[0] << endl;
}
