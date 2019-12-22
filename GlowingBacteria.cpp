#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <cstdio>
#include <ctime>

using namespace std;

class GlowingBacteria {
public:
    int N;
    int K;
    int D;
    int sqrtK;

    vector<vector<int> > neighbours;


    vector<char> simulate(vector<char> &v, int D2=-1) {
        if(D2 == -1) D2 = D;
        vector<char> res(v.size());
        vector<char> current(v.size());
        copy(v.begin(),v.end(),current.begin());
        vector<int> perColour(10,0);
        for(int c=0;c<D2;c++) {

            for(int c3=0;c3<current.size();c3++) {
                int x1 = c3/N;
                int y1 = c3%N;
                for(int c2=0;c2<10;c2++) perColour[c2] = 0;

                for(int c2=0;c2<neighbours[c3].size();c2++) {
                    int neigh = neighbours[c3][c2];
                    perColour[current[neigh]]++;

                }

                int iMax = 0;
                int notOk = 0;
                for(int c2=1;c2<10;c2++) {
                    if(perColour[iMax] == perColour[c2]) notOk = 1;
                    if( (perColour[iMax]==0||perColour[iMax] > perColour[c2]) && perColour[c2] > 0) iMax = c2,notOk=0;
                }
                if(notOk) res[c3]= current[c3];
                else
                res[c3] = iMax;
            }
            copy(res.begin(),res.end(),current.begin());
        }
        return res;
    }

    vector<char> cross(vector<char> &v1, vector<char> &v2) {
        vector<char> res(v1.size());
        for(int c=0;c<v1.size();c++){
            if(rand()%2==0) res[c] = v1[c];
            else res[c] = v2[c];
        }
        return res;
    }



    int diff(vector<char> &v1, vector<char> &v2) {
        int res = 0;
        for(int c=0;c<v1.size();c++) if(v1[c] != v2[c]) res++;
        return res;
    }


    //predict the same colours as in the input grid
    vector<char> findSolution(int N, int C, int D, int K, char grid[])
    {
        srand(time(NULL));

        neighbours.resize(N*N);
        for(int c=0;c<N*N;c++) {
            int x1 = c/N;
            int y1 = c%N;
            for(int c2=0;c2<N*N;c2++) {
                int x2 = c2/N;
                int y2 = c2%N;
                if(x2==x1&&y2==y1) continue;

                if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=K) {
                    neighbours[c].push_back(c2);
                }
            }
        }


        for(int c=0;c<N*N;c++) grid[c] -= '0';
        this->N = N;
        this->K = K;
        this->sqrtK = sqrt(K)+1;
        //cerr<<sqrtK;
        this->D = D;
        vector<int> perColour(10,0);
        vector<char> current(N*N);

        vector<char> ori(N*N);
        for(int c=0;c<N*N;c++) ori[c] = grid[c];
        vector<char> sblue(N*N);
        for(int c=0;c<N*N;c++) sblue[c] = grid[c];
        vector<pair<int,vector<char> > > population(10);
        for(int c=0;c<5;c++) {
            population[c].second.resize(N*N);
            copy(sblue.begin(),sblue.end(),population[c].second.begin());
            sblue = simulate(sblue,1);
        }
        for(int c=5;c<population.size();c++) {
            population[c].second.resize(N*N);
            for(int c2=0;c2<N*N;c2++) population[c].second[c2] = rand()%C;
        }

        vector<char> best(N*N);
        int bestDist = 1e6;
        for(int c=0;c<200;c++) {
            for(int c2=0;c2<population.size();c2++) {
                vector<char> s = simulate(population[c2].second);
                int d = diff(s,ori);
                population[c2].first = d;
            }
            sort(population.begin(),population.end());
            //cerr<<population[0].first<<endl;
            if(population[0].first < bestDist) {
                bestDist = population[0].first;
                //cerr<<" "<<bestDist<<endl;
                copy(population[0].second.begin(),population[0].second.end(),best.begin());
                vector<char> s = simulate(population[0].second);
                //cerr<<"ori"<<endl;
                //for(int c=0;c<N;c++) {
                //    for(int c2=0;c2<N;c2++) {
                //        cerr<<(char)(population[0].second[c*N+c2]+'0');
                //    }
                //    cerr<<endl;
                //}
                //cerr<<"simu"<<endl;
                //for(int c=0;c<N;c++) {
                //    for(int c2=0;c2<N;c2++) {
                //        cerr<<(char)(s[c*N+c2]+'0');
                //    }
                //    cerr<<endl;
                //}
                //cerr<<endl;
            }

            for(int c2=5;c2<population.size();c2++) {
                population[c2].second = cross(population[rand()%5].second, population[rand()%5].second);
            }

            for(int c2=0;c2<population.size();c2++) {
                for(int c3=0;c3<3;c3++) {
                    int z = rand()%(N*N);
                    population[c2].second[z] = rand()%C;
                }

            }

        }


        for(int c=0;c<N*N;c++) best[c]+='0';
        return best;
    }
};

int main() {
    GlowingBacteria gb;
    int N;
    int C;
    int D;
    int K;
    cin >> N;
    cin >> C;
    cin >> D;
    cin >> K;
    char grid[N*N];
    for (int i=0; i<N*N; i++) cin >> grid[i];

    vector<char> ret = gb.findSolution(N, C, D, K, grid);
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << endl;
    cout.flush();
}
