#include <bits/stdc++.h>
using namespace std;
ifstream fin ("bellingham.in");
ofstream fout ("bellingham.out");


const int MAXN=1001;

int c,n,a[MAXN];

int cmmdc (int x, int y){
    int r;
    while (y){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    fin >>c>>n;
    for (int i=1;i<=n;++i){
        fin >>a[i];
    }
    if (c==1){

        int rez=0;
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                if (cmmdc (a[i],a[j])==1)
                    rez++;
            }
        }
        fout <<rez;
    }
    else{
        int rez=0;
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                for (int k=j+1;k<=n;++k){
                    if (cmmdc (cmmdc (a[i],a[j]),a[k]) == 1)
                        rez++;
                }
            }
        }
        fout <<rez;
    }
    return 0;
}
