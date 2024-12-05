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
    if (c==1){

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
        for (auto i:sol){
            fout<<i<<' ';
        }
    }
    else{
        st=1;
        dr=n;
        while(st<=dr){
            ll mij=(st+dr)/2;
            if (k-(n*(n+1)/2-mij*(mij-1)/2)<mij)
                st=mij+1;
            else
                dr=mij-1;
        }
        st--;
        ans=n-st+1;
        if (k-(n*(n+1)/2-st*(st-1)/2))
            ans++;
        fout<<ans;
    }
    return 0;
}
