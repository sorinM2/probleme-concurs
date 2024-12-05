#include <iostream>
#include <fstream>

std::ifstream in("ski.in");
std::ofstream out("ski.out");

constexpr int nmax = 1e6 + 11;
constexpr int mmax = 1e6 + 11;

struct prognoza
{
    int st, dr, q;
};

int h[nmax], mars[nmax];
prognoza p[mmax];

int main()
{
    int n, m, k;
    in >> n >>  m >> k;
    for ( int i = 1; i <= n; ++i )
        in >> h[i];

    for ( int i = 1; i <= m; ++i )
        in >> p[i].st >> p[i].dr >> p[i].q;

int l = 1, r = m, rez = -1;
while ( l <= r )
    {
        for ( int i = 1; i <= n; ++i )
            mars[i] = 0;
        int mij = ( l + r ) / 2;
        for ( int i = 1; i <= mij; ++i ){
            int st = p[i].st;
            int dr = p[i].dr;
            int q = p[i].q;
            mars[st] -= q;
            mars[dr + 1] += q;
        }

        for ( int i = 1; i <= n; ++i )
            mars[i] += mars[i - 1];

        bool ok = true;
        for ( int i = 1; i <= n; ++i )
            if ( h[i] + mars[i] > k )
                {
                    ok = false;
                    break;
                }
        if ( ok )
            rez = mij, r = mij - 1;
        else l = mij + 1;
    }

out << rez;

    return 0;
}