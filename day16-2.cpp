#include <bits/stdc++.h>

using namespace std;



int main()
{
    vector<int> pattern = {0,1,0,-1};
    string s;
    cin>>s;
    string sOri = s;
    for(int c=0;c+1<10000;c++) {
        s += sOri;
    }

    int z = 0;
    for(int c=0;c<7;c++) {
        z*= 10;
        z+=sOri[c]-'0';
    }
    cout<<z<<endl;

    for(int c=0;c<100;c++) {
        for(int c2=s.size()-2;c2>=0;c2--) {
            s[c2] = (s[c2]-'0'+s[c2+1]-'0')%10+'0';
        }
    }

    cout<<s.substr(z,8)<<endl;

}
