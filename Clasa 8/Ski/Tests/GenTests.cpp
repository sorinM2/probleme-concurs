#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
std::ifstream in("GenTests.in");

constexpr int valmax = 1e6 + 1;
void Randomize()
{
    std::srand ( (unsigned int) time(NULL));
}


unsigned int Random(unsigned int mod)
{
    unsigned int n1 = rand(); 
    unsigned int n2 = rand();
    return (unsigned int)n1 * (unsigned int)n2 % mod + 1;
}

void GenerateTest(std::string FileName);
void Generate(std::string FileName);
void GetEnter(){std::cin.get(); std::cin.get();}
std::vector<std::string> ConsoleInput;

int main(int argc, char* argv[])
{
    Randomize();
    for ( int i = 0; i < argc; ++i )
    {
        ConsoleInput.emplace_back(argv[i]);
    }

    for ( int i = 1; i < ConsoleInput.size(); ++i )
        GenerateTest(ConsoleInput[i]);

    return 0;
}

int nmin = 2, nmax = 1e5 + 1;
int mmin = 2, mmax = 1e5 + 1;

void GenerateTest(std::string FileName)
{
    system("clear");
    nmin = 2, nmax = 1e5 + 1;
    mmin = 2, mmax = 1e5 + 1;


    std::cout << "Generare testul '" << FileName << "'" << std::endl;
    
    std::cout <<  "n max: ";
    std::cin >> nmax;
    std::cout << std::endl;

    std::cout << "m max: ";
    std::cin >> mmax;
    std::cout << std::endl;

    {
        std::string confirmare = "";
        std::cout << "Scire 'CONFIRM' pentru a genera testul!" << std::endl;
        std::cin >> confirmare;
        if ( confirmare != "CONFIRM" ){
            std::cout << "Testul NU a fost generat. Apasa enter pentru a continua!" << std::endl;
            GetEnter();
            return;
        }
    }
    std::cout << "Se genereaza testul!" << std::endl;

    Generate(FileName);

    std::cout << "Testul a fost generat. Apasa enter pentru a continua!" << std::endl;
    GetEnter();

}

struct operatie
{
    operatie(int st, int dr, int q) : st(st), dr(dr), q(q)
    {} 
    int st, dr, q;
};

const int OpMax = 4000;

operatie GenOp(int n)
{
    int dr = Random(n);
    int st = Random(dr);
    int q = Random(OpMax);

    operatie op = operatie(st, dr, q);
    return op;
}

int mars[valmax];

void ResetMars(int n)
{
    for ( int i = 1; i <= n; ++i )
        mars[i] = 0;
}

void CalcMars(int n)
{
    for ( int i = 1; i <= n; ++i )
        mars[i] += mars[i - 1];
}

void Generate(std::string FileName)
{
    std::ofstream Intrare("TestsOutput\\" + FileName + ".in");
    std::ofstream Iesire("TestsOutput\\" + FileName + ".ok");
    std::vector<operatie> operatii;

    int n = Random(nmax);
    int m = Random(mmax);
    
    int OpInutile = Random(m);
    int OpUtile = m - OpInutile - 1;
    std::vector<int> a(n + 1, 0);
    for ( int i = 1; i <= n; ++i )
        a[i] = Random(10);

    ///////////////////////////////////////////////////////////
    ResetMars(n);
    for ( int i = 1; i <= OpInutile; ++i )
    {
        operatie op = GenOp(n);
        operatii.emplace_back(op);
        int st = op.st, dr = op.dr, q = op.q;
        mars[st] += q;
        mars[dr + 1] -= q;
    }

    CalcMars(n);
    int vmax = 0;

    for ( int i = 1; i <= n; ++i )
    {
        a[i] += mars[i] + 1;
        vmax = std::max(vmax, a[i]);
    }
    int k = vmax - 1;
    operatii.emplace_back(1, n, 1);

    //////////////////////////////////////////////////////////
    ResetMars(n);
    for ( int i = 1; i <= OpUtile; ++i )
    {
        operatie op = GenOp(n);
        operatii.emplace_back(op);
        int st = op.st, dr = op.dr, q = op.q;
        mars[st] += q;
        mars[dr + 1] -= q;
    }

    CalcMars(n);

    for ( int i = 1; i <= n; ++i )
    {
        a[i] += mars[i];
    }
    
    
    Iesire << OpUtile + 1;
    Intrare << n  << " " << m << " " << k << "\n";
    for ( int i = 1; i <= n; ++i )
        Intrare << a[i] << " ";
    Intrare << "\n";

    for ( int i = m - 1; i >= 0; i-- )
    {
        operatie op = operatii[i];
        Intrare << op.st << " " << op.dr << " " << op.q << "\n";
    }

    Intrare.close();
    Iesire.close();
}