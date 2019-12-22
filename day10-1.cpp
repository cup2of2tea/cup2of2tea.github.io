#include <bits/stdc++.h>

using namespace std;

string toString(int z)
{
    string res = "";
    while (z)
    {
        res += (char)(z % 10 + '0');
        z /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<string> v;
    while (1)
    {
        string s;
        cin >> s;
        if (s == "99")
            break;
        v.push_back(s);
    }

    int best = 0;
    for (int c = 0; c < v.size(); c++)
    {
        for (int c2 = 0; c2 < v[c].size(); c2++)
        {
            if (v[c][c2] != '#')
                continue;
            int sum = 0;
            for (int c3 = 0; c3 < v.size(); c3++)
            {
                for (int c4 = 0; c4 < v[c].size(); c4++)
                {
                    if (v[c3][c4] != '#')
                        continue;
                    bool ok = true;
                    for (int c5 = 0; c5 < v.size(); c5++)
                    {
                        for (int c6 = 0; c6 < v.size(); c6++)
                        {
                            if (v[c5][c6] != '#' || (c5 == c3 && c6 == c4))
                                continue;

                            int A = (c - c3) * (c4 - c6) - (c2 - c4) * (c3 - c5);

                            if (A == 0)
                            {

                                double AB = sqrt((c - c3) * (c - c3) + (c2 - c4) * (c2 - c4));
                                double BC = sqrt((c5 - c3) * (c5 - c3) + (c6 - c4) * (c6 - c4));
                                double AC = sqrt((c - c5) * (c - c5) + (c6 - c2) * (c6 - c2));
                                if (abs(AC - (AB + BC)) <= 1e-7)
                                {
                                    ok = false;
                                }
                            }
                        }
                    }
                    if (ok)
                        sum++;
                }
            }
            best = max(best, sum);
        }
    }
    cout << best << endl;
}
