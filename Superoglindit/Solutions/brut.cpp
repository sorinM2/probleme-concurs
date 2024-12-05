#include <bits/stdc++.h>
using namespace std;
ifstream fin ("superoglindit.in");
ofstream fout ("superoglindit.out");

const int MAXN=2e5+10;

int c,n,v[MAXN],m;


int main()
{
    fin >>c>>n>>m;
    int s=0;
    for (int i=1;i<=n;++i){

        fin >>v[i];
        s+=v[i];
    }

    if (c==1){
        fout <<s;
    }
    else{
        //aplicam o sortare neeficienta de tip bubble sort
        bool sortat;
        do
        {
          sortat = true;
          for(int i = 0 ; i < n - 1 ; i ++)
            if(v[i] > v[i+1])
            {
              int aux = v[i];
              v[i] = v[i+1];
              v[i+1] = aux;
              sortat = false;
            }
        }
        while(!sortat);
        if (m%2){
            for (int i=n;i>=1;--i)
                fout <<v[i]<<' ';
        }
        else{
            for (int i=1;i<=n;++i){
                fout <<v[i]<<' ';
            }
        }
    }
    return 0;
}
