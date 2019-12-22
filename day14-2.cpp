#include <bits/stdc++.h>

using namespace std;

long long res = 0;
bool valid = true;

void recu(string toDo, long long quantity, map<string, long long> &m, map<string, long long> &produit, map<string, vector<pair<long long, string>>> &v)
{

    //cout<<toDo<<" "<<quantity<<" "<<m[toDo]<<endl;

    long long already = min(quantity, m[toDo]);
    quantity -= already;
    m[toDo] -= already;

    if (toDo == "ORE")
    {
        res += quantity;
        if (res > 1000000000000)
            valid = false;
        return;
    }

    long long ratio = (quantity + produit[toDo] - 1) / produit[toDo];

    for (auto p : v[toDo])
    {
        recu(p.second, p.first * ratio, m, produit, v);
    }

    m[toDo] += ratio * produit[toDo] - quantity;
}

int main()
{
    ifstream in("input.txt");

    map<string, vector<pair<long long, string>>> reac;
    map<string, long long> produit;
    vector<pair<long long, string>> current;

    while (!in.eof())
    {
        long long z;
        in >> z;
        string chemical;
        if (z == -42)
        {
            in >> z;
            in >> chemical;

            reac[chemical] = current;
            current.clear();
            produit[chemical] = z;
        }
        else
        {
            in >> chemical;
            current.push_back(make_pair(z, chemical));
        }
    }

    map<string, long long> compte;
    long long gauche = 0, droite = 1e15;
    while (gauche != droite)
    {
        cout << gauche << " " << droite << endl;
        res = 0;
        compte.clear();
        valid = true;
        long long mid = (gauche + droite + 1) / 2;
        recu("FUEL", mid, compte, produit, reac);
        if (res <= 1000000000000 && valid)
        {
            gauche = mid;
        }
        else
        {
            droite = mid - 1;
        }
    }
    cout << gauche << endl;
}
