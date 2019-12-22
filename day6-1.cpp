#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, vector<string>> adj;
    set<string> s;
    map<string, bool> orbitingAround;
    while (1)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == "424" && s2 == "424")
            break;

        adj[s1].push_back(s2);
        s.insert(s1);
        s.insert(s2);

        orbitingAround[s2] = true;
    }

    vector<pair<int, string>> dfs;

    for (auto z : s)
    {
        if (!orbitingAround[z])
            dfs.push_back(make_pair(0, z));
    }

    int res = 0;

    while (dfs.size())
    {
        int steps = dfs.back().first;
        string current = dfs.back().second;
        dfs.pop_back();
        res += steps;
        for (int c = 0; c < adj[current].size(); c++)
        {
            dfs.push_back(make_pair(steps + 1, adj[current][c]));
        }
    }
    cout << res;
}
