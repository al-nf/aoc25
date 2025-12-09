#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve(vector<string>& space) {
    vector<map<int, ull>> dp(space.size());
    
    int startCol = -1;
    for (int j = 0; j < space[0].size(); ++j) {
        if (space[0][j] == 'S') {
            startCol = j;
            break;
        }
    }
    
    dp[0][startCol] = 1;
    
    for (int i = 0; i < space.size() - 1; ++i) {
        for (auto& [col, count] : dp[i]) {
            char nextCell = space[i + 1][col];
            
            if (nextCell == '.' || nextCell == 'S') {
                dp[i + 1][col] += count;
            } else if (nextCell == '^') {
                if (col - 1 >= 0) {
                    dp[i + 1][col - 1] += count;
                }
                if (col + 1 < space[0].size()) {
                    dp[i + 1][col + 1] += count;
                }
            }
        }
    }
    
    ull totalTimelines = 0;
    for (auto& [col, count] : dp[space.size() - 1]) {
        totalTimelines += count;
    }
    
    cout << totalTimelines << endl;
}

int main(int, char *argv[]) 
{
    auto start = chrono::high_resolution_clock::now();

    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    vector<string> space;
    string line;
    while (getline(inputFile, line)) {
        space.push_back(line);
    }
    solve(space);
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
