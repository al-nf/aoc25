#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve(const vector<string>& data) {
}

int main(int argc, char *argv[]) 
{
    ifstream inputFile(argv[1]);
    vector<string> data;

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) 
    {
        data.push_back(line);
    }

    solve(data);
}
