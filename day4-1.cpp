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

string toString(int n) {
    string res = "";
    while(n!=0) {
        res = res + (char)(n%10+'0');
        n/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    int res = 0;
  for(int i = 307237; i <= 769058; i++) {
        string s = toString(i);
        int rep = 0;

        bool valid = true;
        char act = s[0];
        int current = 1;
        for(int c=0;c+1<s.size();c++) {
            if(s[c] > s[c+1]) valid = false;
            if(s[c+1]==act){
                current++;
            } else {
                act = s[c+1];
                current = 1;
            }
            if(current==2) rep++;
        }
        if(current==2) rep++;
        if(rep==0) valid=false;

        if(valid) res++;
  }
  cout<<res;
}
