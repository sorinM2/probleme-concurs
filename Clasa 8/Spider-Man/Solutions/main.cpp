#include <bits/stdc++.h>

using namespace std;

ifstream fin ("spiderman.in");
ofstream fout ("spiderman.out");

const int MAXN=2e5+5;

int n, l[MAXN], r[MAXN];
stack <pair<int, int>> st;

int main()
{
    fin>>n;
    for (int i=1;i<=n;++i){
        pair<int, int> x;
        fin>>x.first;
        x.second=i;
        while(!st.empty() && st.top().first<x.first){
            pair<int, int> y=st.top();
            r[y.second]=x.second;
            st.pop();
        }
        if (!st.empty()){
            if (st.top().first==x.first)
                l[x.second]=l[st.top().second];
            else
                l[x.second]=st.top().second;
        }
        else
            l[x.second]=1;
        st.push(x);
    }
    while(!st.empty()){
        pair<int, int> y=st.top();
        r[y.second]=n;
        st.pop();
    }
    for (int i=1;i<=n;++i){
        fout<<r[i]-l[i]+1<<' ';
    }
    return 0;
}
