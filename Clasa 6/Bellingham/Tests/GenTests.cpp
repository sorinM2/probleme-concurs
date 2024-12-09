#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
using namespace std;
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
    std::cout << "Se genereaza testul!" << std::endl;

    Generate(FileName);

    std::cout << "Testul a fost generat. Apasa enter pentru a continua!" << std::endl;
    GetEnter();

}

const int MAXN=1001;

int c,n,a[MAXN];

int cmmdc (int x, int y){
    int r;
    while (y){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

void Generate(std::string FileName)
{
    std::ofstream Intrare("TestsOutput\\" + FileName + ".in");
    std::ofstream Iesire("TestsOutput\\" + FileName + ".ok");

    std::cout << "Cerinta: ";
    std :: cin >>c;
    std::cout << "Numar de numere: ";
    std::cin >>n;
    int h;
    std::cout << "Numar maxim: ";
    std::cin >> h;

    Intrare << c << " " << n << std::endl;
    for (int i=1;i<=n;++i){
        a[i] = Random(h);
        Intrare << a[i] << " ";
    }

    if (c==1){

        int rez=0;
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                if (cmmdc (a[i],a[j])==1)
                    rez++;
            }
        }
        Iesire <<rez;
    }
    else{
        int rez=0;
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                for (int k=j+1;k<=n;++k){
                    if (cmmdc (cmmdc (a[i],a[j]),a[k]) == 1)
                        rez++;
                }
            }
        }
        Iesire <<rez;
    }

    Intrare.close();
    Iesire.close();
}