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


ll c, n, ans, k, st, dr;
vector<int> sol;
void Generate(std::string FileName)
{
    sol.clear();
    std::ofstream Intrare("TestsOutput\\" + FileName + ".in");
    std::ofstream Iesire("TestsOutput\\" + FileName + ".ok");

    std::cout << "c: ";
    std::cin >> c;
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "k: ";
    std::cin >> k;

    Intrare << c << " ";
    Intrare << n << " " << k;
    if (k>n*(n+1)/2){
        Iesire<<-1;
    }
    else if (c==1){

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
        Iesire<<sol.size()<<'\n';
        for (auto i:sol){
            Iesire<<i<<' ';
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
        Iesire<<ans;
    }


    Intrare.close();
    Iesire.close();
}