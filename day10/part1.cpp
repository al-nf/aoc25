#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(int, char *argv[]) 
{
    auto start = chrono::high_resolution_clock::now();

    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
