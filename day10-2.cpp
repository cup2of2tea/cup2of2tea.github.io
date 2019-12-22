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

    tuple<int, int, int> t;
    tuple<int, int, int> best = make_tuple(0, 0, 0);
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
            best = max(best, make_tuple(sum, c, c2));
        }
    }
    int xCenter = get<1>(best);
    int yCenter = get<2>(best);
    v[xCenter][yCenter] = '.';
    //xCenter = 3;
    //yCenter = 8;

    cout << "====" << endl;
    cout << xCenter << " " << yCenter << endl;
    cout << "====" << endl;
    int i = 0;
    while (1)
    {
        vector<tuple<double, int, int>> ast;
        for (int c3 = 0; c3 < v.size(); c3++)
        {
            for (int c4 = 0; c4 < v[c3].size(); c4++)
            {
                if (v[c3][c4] != '#')
                    continue;
                bool ok = true;
                for (int c5 = 0; c5 < v.size(); c5++)
                {
                    for (int c6 = 0; c6 < v[c5].size(); c6++)
                    {
                        if (v[c5][c6] != '#' || (c5 == c3 && c6 == c4))
                            continue;

                        int A = (xCenter - c3) * (c4 - c6) - (yCenter - c4) * (c3 - c5);
                        if (abs(atan2(c6 - yCenter, c5 - xCenter) - atan2(c4 - yCenter, c3 - xCenter)) <= 1e-8)
                        {
                            double AB = sqrt((xCenter - c3) * (xCenter - c3) + (yCenter - c4) * (yCenter - c4));
                            double BC = sqrt((c5 - c3) * (c5 - c3) + (c6 - c4) * (c6 - c4));
                            double AC = sqrt((xCenter - c5) * (xCenter - c5) + (c6 - yCenter) * (c6 - yCenter));
                            if (AC < AB)
                                ok = false;
                        }
                    }
                }
                if (ok)
                {
                    ast.push_back(make_tuple(atan2((double)c4 - yCenter, (double)c3 - xCenter), c3, c4));
                }
            }
        }
        sort(ast.rbegin(), ast.rend());
        if (ast.size() == 0)
            break;
        for (int c = 0; c < ast.size(); c++)
        {
            int x = get<1>(ast[c]);
            int y = get<2>(ast[c]);
            cout << x << " " << y << endl;
            cout << get<0>(ast[c]) << endl;
            i++;
            if (i == 200)
                cout << "=================" << endl;
            v[x][y] = '.';
            //cout<<endl<<endl;
            //for(int c2=0;c2<v.size();c2++) cout<<v[c2]<<endl;
        }
    }
}
