#include <bits/stdc++.h>
using namespace std;
ifstream fin ("andrei.in");
ofstream fout ("andrei.out");

const int MAXN=4e6+10;

int ciur[MAXN],s[MAXN];

void prec(){
    for (int i=2;i<MAXN;++i){
        if (ciur[i]==0){
            for (int j=2*i;j<MAXN;j+=i){
                ciur[j]=1;
            }
        }
    }

    for (int i=2;i<MAXN;++i){
        s[i]=s[i-1]+1-ciur[i];
    }
}


int main()
{
    prec ();

    int n;
    fin >>n;
    for (int i=1;i<=n;++i){
        int x;
        fin >>x;
        fout <<s[x]<<' ';
    }
    return 0;
}
