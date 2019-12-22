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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

map<pair<int, int>, char> board;
map<pair<int, int>, long long> board2;

pair<int, int> bfs(int x, int y, int &d, bool go = false)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    map<pair<int, int>, pair<int, int>> backtrack;

    backtrack[make_pair(x, y)] = make_pair(x, y);
    pair<int, int> p;
    while (q.size())
    {
        p = q.front();
        q.pop();

        if (board.find(p) == board.end() && !go)
        {
            break;
        }
        if (go && board[p] == 'O')
            break;

        for (int d = 0; d < 4; d++)
        {
            int x2 = p.first + dx[d];
            int y2 = p.second + dy[d];

            pair<int, int> p2 = make_pair(x2, y2);

            if (board.find(p2) == board.end() || board[p2] != '#')
            {
                if (backtrack.find(p2) == backtrack.end())
                {
                    backtrack[p2] = p;
                    q.push(p2);
                }
            }
        }
    }

    if (board.find(p) != board.end() && !go)
    {
        return make_pair(-424242, -424242);
    }
    d = 0;

    while (backtrack[p].first != x || backtrack[p].second != y)
    {
        d++;
        p = backtrack[p];
    }

    d++;
    return p;
}

bool simulate(int it)
{
    bool caBouge = false;
    for (auto z : board2)
    {
        if (z.second == it)
        {
            for (int d = 0; d < 4; d++)
            {
                int x2 = z.first.first + dx[d];
                int y2 = z.first.second + dy[d];

                if (board2[make_pair(x2, y2)] == 0)
                {
                    board2[make_pair(x2, y2)] = it + 1;
                    caBouge = true;
                }
            }
        }
    }
    return caBouge;
}

int main()
{
    map<long long int, long long> v;
    long long i = 0;
    ifstream in("input.txt");
    while (!in.eof())
    {
        long long int z;
        in >> z;
        v[i++] = z;
    }

    long long int current = 0;
    long long base = 0;
    long long int input = 2;
    bool debug = false;

    int x2 = 0;
    int y2 = 0;

    int x = 0;
    int y = 0;

    int d;

    board[make_pair(0, 0)] = '.';

    int miniX = 0, maxiX = 0, miniY = 0, maxiY = 0;

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
            pair<int, int> p = bfs(x, y, d);

            if (p.first == -424242)
                break;

            if (p.first < x)
            {
                input = 1;
            }
            else if (p.first > x)
            {
                input = 2;
            }
            else if (p.second < y)
            {
                input = 3;
            }
            else if (p.second > y)
            {
                input = 4;
            }
            //cout<<"INPUT "<<input<<endl;
            x2 = p.first;
            y2 = p.second;

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
            //     << "OUTPUT " << par[0] << endl;
            if (par[0] == 0)
            {
                board[make_pair(x2, y2)] = '#';
            }
            else if (par[0] == 1)
            {
                board[make_pair(x2, y2)] = '.';
                x = x2;
                y = y2;
            }
            else
            {
                board[make_pair(x2, y2)] = 'O';
                x = x2;
                y = y2;
            }
            miniX = min(x2, miniX);
            maxiX = max(x2, maxiX);
            miniY = min(y2, miniY);
            maxiY = max(y2, maxiY);

            current += 2;

            /*for(int c=miniX;c<=maxiX;c++) {
                for(int c2=miniY;c2<=maxiY;c2++) {
                    pair<int,int> p = make_pair(c,c2);
                    if(board.find(p)==board.end()) {
                        cout<<"?";
                    } else {
                        cout<<board[p];
                    }
                }
                cout<<endl;
            }
            cout<<endl<<endl;
            */
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
    bfs(0, 0, d, true);
    for (auto z : board)
    {
        if (z.second == 'O')
            board2[z.first] = 100;
        else if (z.second == '.')
            board2[z.first] = 0;
        else if (z.second == '#')
            board2[z.first] = 1;
        else
            board2[z.first] = 1;
    }

    int it2 = 100;
    while (simulate(it2++))
        ;
    cout << (it2 - 1) - 100;
    //cout << v[0] << endl;
}
