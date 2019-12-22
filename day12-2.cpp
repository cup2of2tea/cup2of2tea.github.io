#include <bits/stdc++.h>

using namespace std;


long long gcd(long long a, long long b) {
    if(a==0) return b;
    return gcd(b%a,a);
}

long long lcm (long long a, long long b) {
    return a*b/gcd(a,b);
}


int main()
{
    vector<tuple<int,int,int,int,int,int> > v(4);
    v[0]=make_tuple(-15,1,4,0,0,0);
    v[1]=make_tuple(1,-10,-8,0,0,0);
    v[2]=make_tuple(-5,4,9,0,0,0);
    v[3]=make_tuple(4,6,-2,0,0,0);


    /*v[0]=make_tuple(-1,0,2,0,0,0);
    v[1]=make_tuple(2,-10,-7,0,0,0);
    v[2]=make_tuple(4,-8,8,0,0,0);
    v[3]=make_tuple(3,5,-1,0,0,0);
*/
    vector<tuple<int,int,int,int,int,int> > vOri(4);

    copy(v.begin(),v.end(),vOri.begin());

    int cycleX = -1, cycleY = -1, cycleZ = -1;

    int steps=0;
    while(1) {
        steps++;
        if(steps%1000==0) {
            cout<<steps<<endl;
        }
        vector<tuple<int,int,int,int,int,int> > copie(4);
        copy(v.begin(),v.end(),copie.begin());

        for(int c2=0;c2<v.size();c2++) {

            int x = get<0>(copie[c2]);
            int y = get<1>(copie[c2]);
            int z = get<2>(copie[c2]);
            int vx = get<3>(copie[c2]);
            int vy = get<4>(copie[c2]);
            int vz = get<5>(copie[c2]);


            for(int c3=0;c3<v.size();c3++) {
                int x2 = get<0>(copie[c3]);
                int y2 = get<1>(copie[c3]);
                int z2 = get<2>(copie[c3]);
                int vx2 = get<3>(copie[c3]);
                int vy2 = get<4>(copie[c3]);
                int vz2 = get<5>(copie[c3]);

                if(x2 > x) vx++;
                if(x2 < x) vx--;
                if(y2 > y) vy++;
                if(y2 < y) vy--;
                if(z2 > z) vz++;
                if(z2 < z) vz--;

           }

           x += vx;
           y += vy;
           z += vz;

           v[c2] = make_tuple(x,y,z,vx,vy,vz);
           //cout<<x<<" "<<y<<" "<<z<<" "<<vx<<" "<<vy<<" "<<vz<<endl;
        }

        if(cycleX == -1) {
            bool ok = true;
            for(int c=0;c<v.size();c++) {
                if(get<0>(v[c])!=get<0>(vOri[c]) || get<3>(v[c])!=get<3>(vOri[c]))
                    ok = false;
            }
            if(ok) cycleX = steps;
        }

        if(cycleY == -1) {
            bool ok = true;
            for(int c=0;c<v.size();c++) {
                if(get<1>(v[c])!=get<1>(vOri[c]) || get<4>(v[c])!=get<4>(vOri[c]))
                    ok = false;
            }
            if(ok) cycleY = steps;
        }

        if(cycleZ == -1) {
            bool ok = true;
            for(int c=0;c<v.size();c++) {
                if(get<2>(v[c])!=get<2>(vOri[c]) || get<5>(v[c])!=get<5>(vOri[c]))
                    ok = false;
            }
            if(ok) cycleZ = steps;
        }

        if(cycleX != -1 && cycleY != -1 && cycleZ != -1) break;

    }
    cout<<cycleX<<" "<<cycleY<<" "<<cycleZ<<endl;
    cout<<lcm(cycleX,lcm(cycleY,cycleZ));
    return 0;

    int res = 0;
    for(int c=0;c<v.size();c++) {
        int x = get<0>(v[c]);
        int y = get<1>(v[c]);
        int z = get<2>(v[c]);
        int vx = get<3>(v[c]);
        int vy = get<4>(v[c]);
        int vz = get<5>(v[c]);

        res += (abs(x)+abs(y)+abs(z))*(abs(vx)+abs(vy)+abs(vz));
    }
    cout<<res;

}
