#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delim)
{
    vector<string> res;
    s += delim;
    string current = "";
    for (int c = 0; c < s.size(); c++)
    {

        if (s[c] == delim[0])
        {
            res.push_back(current);
            current = "";
        }
        else
        {
            current += s[c];
        }
    }
    return res;
}

int main()
{
    map<pair<int, int>, bool> seen;
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<string>> v(2);
    v[0] = split(s1, ",");
    v[1] = split(s2, ",");

    pair<int, int> best = make_pair(1e6, 1e6);
    int dist = 1e8;

    for (int c = 0; c < 2; c++)
    {
        int x = 0;
        int y = 0;
        for (int c2 = 0; c2 < v[c].size(); c2++)
        {
            int dx = 0, dy = 0;
            switch (v[c][c2][0])
            {
            case 'U':
                dx = -1;
                break;
            case 'D':
                dx = 1;
                break;
            case 'L':
                dy = -1;
                break;
            case 'R':
                dy = 1;
                break;
            }
            int d = 0;
            for (int c3 = 1; c3 < v[c][c2].size(); c3++)
            {
                d *= 10;
                d += v[c][c2][c3] - '0';
            }

            for (int c4 = 0; c4 < d; c4++)
            {
                x += dx;
                y += dy;
                if (c == 1 && seen[make_pair(x, y)])
                {
                    int disttmp = abs(x) + abs(y);
                    if (disttmp < dist)
                    {
                        dist = disttmp;
                        best = make_pair(x, y);
                    }
                }
                if (c == 0)
                    seen[make_pair(x, y)] = true;
            }
        }
    }
    cout << dist;
}
