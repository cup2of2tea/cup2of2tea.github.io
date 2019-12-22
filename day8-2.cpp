#include <bits/stdc++.h>

using namespace std;

int main()
{
    int width = 25;
    int height = 6;

    ifstream in("day8-1.txt");

    string s = "";
    while (!in.eof())
    {

        string z;
        in >> z;
        s += z;
    }
    vector<vector<vector<int>>> layers(s.size() / (width * height), vector<vector<int>>(height, vector<int>(width)));

    int i = 0;
    int maxi = 1e6;
    long long res = 0;
    for (int c = 0; c < layers.size(); c++)
    {
        vector<int> counts(5, 0);
        for (int c2 = 0; c2 < layers[c].size(); c2++)
            for (int c3 = 0; c3 < layers[c][c2].size(); c3++)
            {
                layers[c][c2][c3] = s[i++] - '0';
                counts[layers[c][c2][c3]]++;
            }
        if (counts[0] < maxi)
        {

            res = counts[1] * counts[2];
            maxi = counts[0];
        }
    }
    cout << res;
}
