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

    v.push_back(99);
    v.push_back(99);
    v.push_back(99);
    v.push_back(99);
    v.push_back(99);
    v.push_back(99);
    int res = 0;
    vector<int> ori(v.size());
    copy(v.begin(), v.end(), ori.begin());

    vector<vector<int> > amplifiers;

    vector<int> permutation(5);
    for (int c = 0; c < permutation.size(); c++)
        permutation[c] = c+5;

    bool debug = false;
    do {
        vector<int> inputs(2);
        inputs[1]=0;
        for(int c=0;c<5;c++)   {
            int i = 0;
            int current = 0;
            inputs[0]=permutation[c];
            copy(ori.begin(),ori.end(),v.begin());
            while (v[current] != 99)
            {
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

                int ori1 = v[current + 1];
                int ori2 = v[current + 2];
                int ori3 = v[current + 3];

                int par1 = ((v[current + 1] < 0 || v[current + 1] >= v.size()) ? v[current + 1] : (m[0] ? v[current + 1] : v[v[current + 1]]));
                int par2 = ((v[current + 2] < 0 || v[current + 2] >= v.size()) ? v[current + 2] : (m[1] ? v[current + 2] : v[v[current + 2]]));
                int par3 = ((v[current + 3] < 0 || v[current + 3] >= v.size()) ? v[current + 3] : (m[2] ? v[current + 3] : v[v[current + 3]]));
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
                    v[ori1] = inputs[i++];
                    current += 2;
                }
                else if (op == 4)
                {
                    cout << "OUTPUT " << par1 << endl;
                    inputs[1] = par1;
                    break;
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
            }
        }
        res=max(res,inputs[1]);
    }while(next_permutation(permutation.begin(),permutation.end()));

    cout<<res<<endl;
    //cout << v[0] << endl;
}