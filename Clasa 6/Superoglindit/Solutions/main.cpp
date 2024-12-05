#include <bits/stdc++.h>
using namespace std;
ifstream fin ("superoglindit.in");
ofstream fout ("superoglindit.out");

int c,n,f[10],s,m;

int main()
{
    fin >>c>>n>>m;
    for (int i=1;i<=n;++i){
        int x;
        fin >>x;
        f[x]++;
        s+=x;
    }
    if (c==1){
        fout <<s;
    }
    else{
        if (m%2){
            for (int i=9;i>=1;--i){
                while (f[i]){
                    fout <<i<<' ';
                    f[i]--;
                }
            }
        }
        else{
            for (int i=1;i<=9;++i){
                while (f[i]){
                    fout <<i<<' ';
                    f[i]--;
                }
            }
        }
    }
    return 0;
}
