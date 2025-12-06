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
    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    vector<vector<int>> nums;
    vector<char> ops;
    string line;
    while (getline(inputFile, line)) {
        if (!isalnum(line[0]) && line[0] != ' ') break;
        vector<int> row;
        stringstream ss(line);
        int n;
        while (ss >> n) {
            row.push_back(n);
        }
        nums.push_back(row);
    }

    stringstream ss(line);
    char c;
    while (ss >> c) {
        ops.push_back(c);
    }


    solve(nums, ops);
}
