///BRUT
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("andrei.in");
ofstream fout ("andrei.out");

bool prim (int x){
    if (x<2) return 0;
    if (x==2) return 1;
    if (x%2==0) return 0;
    for (int d=3;d*d<=x;d+=2){
        if (x%d==0) return 0;
    }
    return 1;
}

int main()
{
    int n;
    fin >>n;
    for (int i=1;i<=n;++i){
        int x;
        fin >>x;
        int rez=0;
        for (int j=1;j<=x;++j){
            if (prim (j)) rez++;
        }
        fout <<rez<<' ';
    }
    return 0;
}
