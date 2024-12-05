#include <iostream>
#include <fstream>

std::ifstream in("ski.in");
std::ofstream out("ski.out");

constexpr int nmax = 1e6 + 1;
int h[nmax];
int main()
{
    int n, m, k;
    in >> n >> m >> k;
    for ( int i = 1; i <= n; ++i )
        in >> h[i];

    int rez = -1;
    for ( int i = 1; i <= m; ++i )
    {
        int st, dr, q;
        in >> st >> dr >> q;
        for ( int j = st; j <= dr; ++ j )
            h[j] -= q;
        bool ok = true;
        for ( int j = 1; j <= n; ++j )
            if ( h[j] > k )
            {
                ok = false;
                break; 
            }
        if ( ok )
        {
            rez = i;
            break;
        }
    }
    out << rez;
}