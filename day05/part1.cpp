#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) 
{
    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    vector<vector<char>> data;
    string line;
    while (getline(inputFile, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        data.push_back(row);
    }
    solve(data);
}
