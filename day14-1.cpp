#include <bits/stdc++.h>

using namespace std;

long long res = 0;

void recu(string toDo, int quantity, map<string, int> &m, map<string, int> &produit, map<string, vector<pair<int, string>>> &v)
{

    cout << toDo << " " << quantity << " " << m[toDo] << endl;

    int already = min(quantity, m[toDo]);
    quantity -= already;
    m[toDo] -= already;

    if (toDo == "ORE")
    {
        res += quantity;
        return;
    }

    int ratio = (quantity + produit[toDo] - 1) / produit[toDo];

    for (auto p : v[toDo])
    {
        recu(p.second, p.first * ratio, m, produit, v);
    }

    m[toDo] += ratio * produit[toDo] - quantity;
}

int main()
{
    ifstream in("input.txt");

    map<string, vector<pair<int, string>>> reac;
    map<string, int> produit;
    vector<pair<int, string>> current;

    while (!in.eof())
    {
        int z;
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

    map<string, int> compte;
    /*long long gauche = 0, droite = 1e12;
    while(gauche!=droite) {
        
    }*/
    recu("FUEL", 1, compte, produit, reac);
    cout << res << endl;
}
