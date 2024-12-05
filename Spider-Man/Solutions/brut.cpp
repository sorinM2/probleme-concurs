#include <bits/stdc++.h>
using namespace std;
ifstream fin ("spiderman.in");
ofstream fout ("spiderman.out");

const int MAXN=2e5+10;

int n,a[MAXN];

int main()
{
    fin >>n;
    for (int i=1;i<=n;++i){
        fin >>a[i];
    }
    for (int i=1;i<=n;++i){
        int st=i,dr=i;
        while (st>1 and a[st]<=a[i]) st--;
        while (dr<n and a[dr]<=a[i]) dr++;
        fout <<dr-st+1<<' ';
    }
    return 0;
}
