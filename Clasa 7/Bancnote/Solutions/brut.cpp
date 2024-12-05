#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bancnote.in");
ofstream fout ("bancnote.out");
typedef long long ll;

ll c, n, ans, k, st, dr;
vector<int> sol;

int main()
{
    fin>>c>>n>>k;
    if (k>n*(n+1)/2){
        fout<<-1;
        return 0;
    }


    for (int i=n;i>0 && k>0;--i){
        if (k<=i){
            sol.push_back(k);
            k=0;
        }
        else{
            k-=i;
            sol.push_back(i);
        }
    }
    fout<<sol.size()<<'\n';
    if (c==1){
        for (auto i:sol){
            fout<<i<<' ';
        }
    }


    return 0;
}
