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
    std::cout << "Se genereaza testul!" << std::endl;

    Generate(FileName);

    std::cout << "Testul a fost generat. Apasa enter pentru a continua!" << std::endl;
    GetEnter();

}


const int OpMax = 4000;

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

void Generate(std::string FileName)
{
    std::ofstream Intrare("TestsOutput\\" + FileName + ".in");
    std::ofstream Iesire("TestsOutput\\" + FileName + ".ok");

    prec();
    int n, m;
    std::cout << "MAX n: ";
    std::cin >> n;
    std:: cout << "Max numar ";
    std::cin >> m; 

    Intrare << n << std::endl;
    for ( int i = 1; i <= n; ++i )
    {
        int numar = Random(m);
        Intrare << numar << " ";
        Iesire << s[numar] << " ";
    } 

    Intrare.close();
    Iesire.close();
}