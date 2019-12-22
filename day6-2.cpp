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
        adj[s2].push_back(s1);
        s.insert(s1);
        s.insert(s2);

        orbitingAround[s2] = true;
    }

    queue<pair<int, string>> bfs;

    bfs.push(make_pair(0, "SAN"));

    map<string, bool> seen;
    seen["SAN"] = true;

    while (bfs.size())
    {
        int steps = bfs.front().first;
        string current = bfs.front().second;
        bfs.pop();
        if (current == "YOU")
        {

            cout << steps - 2;
            return 0;
        }
        for (int c = 0; c < adj[current].size(); c++)
        {
            string newState = adj[current][c];
            if (seen[newState])
                continue;
            seen[newState] = true;
            bfs.push(make_pair(steps + 1, newState));
        }
    }
}
