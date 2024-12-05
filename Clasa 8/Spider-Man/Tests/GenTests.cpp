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

const int MAXN=2e5+5;

int n, l[MAXN], r[MAXN];
stack <pair<int, int>> st;

void Generate(std::string FileName)
{
    std::ofstream Intrare("TestsOutput\\" + FileName + ".in");
    std::ofstream Iesire("TestsOutput\\" + FileName + ".ok");

    std::cout << "NMax: ";
    std::cin >> n;
    int h;
    std::cout << "Inaltime maxima cladire: ";
    std::cin >> h;
    Intrare << n << std::endl;

    for (int i=1;i<=n;++i){
        pair<int, int> x;
        x.first = Random(h);
        Intrare << x.first << " ";
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
        Iesire<<r[i]-l[i]+1<<' ';
    }


    Intrare.close();
    Iesire.close();
}