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
typedef long long ll;

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

int c,n,f[10],s,m;

void Generate(std::string FileName)
{
    std::ofstream Intrare("TestsOutput\\" + FileName + ".in");
    std::ofstream Iesire("TestsOutput\\" + FileName + ".ok");

    std::cout << "C: ";
    std::cin >> c;
    std::cout << "N: ";
    std::cin >> n;
    std::cout << "M: ";
    std::cin >> m;
    Intrare << c << " " << n << " " << m << std::endl;
    for (int i=1;i<=n;++i){
        int x;
        x = Random(9);
        Intrare << x << " ";
        f[x]++;
        s+=x;
    }
    if (c==1){
        Iesire <<s;
    }
    else{
        if (m%2){
            for (int i=9;i>=1;--i){
                while (f[i]){
                    Iesire <<i<<' ';
                    f[i]--;
                }
            }
        }
        else{
            for (int i=1;i<=9;++i){
                while (f[i]){
                    Iesire <<i<<' ';
                    f[i]--;
                }
            }
        }
    }
    

    Intrare.close();
    Iesire.close();
}