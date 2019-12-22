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

void displayState(vector<int> &cursors, vector<vector<long long int>> &memory)
{
    for (int c = 0; c < cursors.size(); c++)
        cout << cursors[c] << " ";
    cout << endl;
    for (int c = 0; c < memory.size(); c++, cout << endl)
        for (int c2 = 0; c2 < memory[c].size(); c2++)
            cout << memory[c][c2] << " ";

    cout << endl
         << endl;
}

int main()
{
    vector<long long int> ori;
    long long int res = 0;
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

        v.push_back(99);
        v.push_back(99);
        v.push_back(99);
        v.push_back(99);
        v.push_back(99);
        v.push_back(99);
        ori.resize(v.size());
        copy(v.begin(), v.end(), ori.begin());
    }

    vector<long long int> permutation(5);
    for (int c = 0; c < permutation.size(); c++)
        permutation[c] = c + 5;
    int it = 0;
    bool debug = false;
    do
    {

        vector<vector<long long int>> amplifiers(5);
        vector<int> cursors(5, 0);
        int iAmpl = 0;
        int laMouvance = 0;
        long long int lastOutput = 0;

        for (int c = 0; c < 5; c++)
        {
            amplifiers[c].resize(ori.size());
            copy(ori.begin(), ori.end(), amplifiers[c].begin());
        }
        vector<queue<int>> inputs(5);

        for (int c = 0; c < 5; c++)
            inputs[c].push(permutation[c]);
        inputs[0].push(0);
        bool isStop = false;
        while (!isStop)
        {
            while (1)
            {
                it++;

                //if(it>=1e6) return 0;
                //displayState(cursors,amplifiers);
                if (amplifiers[iAmpl][cursors[iAmpl]] == 99)
                {
                    laMouvance++;
                    if (laMouvance > 5)
                    {
                        isStop = true;
                        break;
                    }
                    iAmpl++;
                    iAmpl %= 5;
                    continue;
                }

                vector<long long int> &v = amplifiers[iAmpl];
                int current = cursors[iAmpl];

                vector<bool> m;
                m = modes(v[current] / 100);
                //  cout << v[current] << endl;
                if (debug)
                {
                    cout << "NEW LINE =============" << endl;
                    for (int c = 0; c < m.size(); c++)
                        cout << (m[c] ? "true" : "false") << " ";
                    cout << endl;
                }

                int op = v[current] % 100;

                /*if(op >= 5) {
                    cout<<"?"<<endl;
                    //return 0;
                }*/

                long long int ori1 = v[current + 1];
                long long int ori2 = v[current + 2];
                long long int ori3 = v[current + 3];

                long long int par1 = ((v[current + 1] < 0 || v[current + 1] >= v.size()) ? v[current + 1] : (m[0] ? v[current + 1] : v[v[current + 1]]));
                long long int par2 = ((v[current + 2] < 0 || v[current + 2] >= v.size()) ? v[current + 2] : (m[1] ? v[current + 2] : v[v[current + 2]]));
                long long int par3 = ((v[current + 3] < 0 || v[current + 3] >= v.size()) ? v[current + 3] : (m[2] ? v[current + 3] : v[v[current + 3]]));
                // cout << par1 << " " << par2 << " " << par3 << endl;
                if (op == 1)
                {
                    v[ori3] = par1 + par2;
                    current += 4;
                }
                else if (op == 2)
                {
                    v[ori3] = par1 * par2;
                    current += 4;
                }
                else if (op == 3)
                {
                    if (inputs[iAmpl].size() == 0)
                    {
                        iAmpl++;
                        iAmpl %= 5;
                        laMouvance++;
                        if (laMouvance > 5)
                        {
                            isStop = true;
                            break;
                        }
                        break;
                    }
                    v[ori1] = inputs[iAmpl].front();
                    inputs[iAmpl].pop();
                    current += 2;
                }
                else if (op == 4)
                {
                    cout << "OUTPUT " << par1 << endl;
                    inputs[(iAmpl + 1) % 5].push(par1);
                    lastOutput = par1;
                    current += 2;
                }
                else if (op == 5)
                {
                    if (par1 != 0)
                        current = par2;
                    else
                        current += 3;
                }
                else if (op == 6)
                {
                    if (par1 == 0)
                        current = par2;
                    else
                        current += 3;
                }
                else if (op == 7)
                {
                    if (par1 < par2)
                        v[ori3] = 1;
                    else
                        v[ori3] = 0;
                    current += 4;
                }
                else if (op == 8)
                {
                    if (par1 == par2)
                        v[ori3] = 1;
                    else
                        v[ori3] = 0;
                    current += 4;
                }
                cursors[iAmpl] = current;
                laMouvance = 0;
            }
        }
        res = max(res, lastOutput);
        // return 0;
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << res << endl;
    //cout << v[0] << endl;
}
