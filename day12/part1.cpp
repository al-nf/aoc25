#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve(const vector<vector<int>>& nums, const vector<char>& ops) {
    ull sum = 0;
    
    for (size_t i = 0; i < nums[0].size(); ++i) {
        ull res;
        if (ops[i] == '+') {
            res = 0;
            for (size_t j = 0; j < nums.size(); ++j) {
                res += nums[j][i];
            }
            sum += res;

        } else if (ops[i] == '*') {
            res = 1;
            for (size_t j = 0; j < nums.size(); ++j) {
                res *= nums[j][i];
            }
            sum += res;
        }
    }
    cout << sum << endl;
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

    string line;
    while (getline(inputFile, line)) {
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
