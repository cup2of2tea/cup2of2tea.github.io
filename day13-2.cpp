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

    ifstream in("input.txt");
#define cin in
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

    int miniX = 1000, maxiX = 0;
    int miniY = 1000, maxiY = 0;

    int x = -2, y = -2, color = -2;

    int it = 0;

    int res = 0;

    int score = 0;

    map<pair<int, int>, int> board;

    while (v[current] != 99)
    {
        it++;
        vector<int> m;
        m = modes(v[current] / 100);
        //cout << v[current] << endl;
        //return 0;
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

            /*cout<<endl<<endl;
            for(int y=miniY; y<=maxiY;y++) {
                for(int x=miniX; x<=maxiX;x++) {
                    cout<<board[make_pair(x,y)]<<" ";
                }
                cout<<endl;
            }*/

            int miniPaddle = 1e8;
            int maxiPaddle = -1e8;
            int miniBall = 1e8;
            int maxiBall = -1e8;

            for (auto z : board)
            {
                int x = z.first.first;
                int y = z.first.second;
                int color = z.second;
                if (color == 3)
                {

                    miniPaddle = min(miniPaddle, x);
                    maxiPaddle = max(maxiPaddle, x);
                }
                else if (color == 4)
                {
                    miniBall = min(miniBall, x);
                    maxiBall = max(maxiBall, x);
                }
            }

            if ((miniPaddle + maxiPaddle) / 2 > (miniBall + maxiBall) / 2)
            {
                input = -1;
            }
            else if ((miniPaddle + maxiPaddle) / 2 < (miniBall + maxiBall) / 2)
            {
                input = 1;
            }
            else
            {
                input = 0;
            }

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
            //cout << current << " "
            //    << "OUTPUT " << par[0] << endl;

            if (x < -1)
            {
                x = par[0];
            }
            else if (y < -1)
            {
                y = par[0];
            }
            else if (color < -1)
            {
                color = par[0];
                if (par[0] == 2)
                {
                    res++;
                }

                if (x == -1 && y == 0)
                    score = color;
                else
                {
                    board[make_pair(x, y)] = color;
                    miniX = min(miniX, x);
                    maxiX = max(maxiX, x);
                    miniY = min(miniY, y);
                    maxiY = max(maxiY, y);
                }

                x = -2;
                y = -2;
                color = -2;
            }
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
    cout << res << endl;
    cout << score << endl;
}
