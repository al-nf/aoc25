#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve(const vector<vector<char>>& digits, const vector<char>& ops) {
    vector<int> problem;
    ull sum = 0;
    ull res = 0;
    size_t op_nr = ops.size()-1;
    for (int j = digits[0].size() - 1; j >= 0; --j) {
        string col = "";
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i][j] != ' ') {
                col += (char)digits[i][j];
            }
        }
        if (col != "") {
            problem.push_back(stoi(col));
        } else {
            if (ops[op_nr] == '+') {
                res = 0;
                for (int i : problem) {
                    res += i;
                }
            }
            else if (ops[op_nr] == '*') {
                res = 1;
                for (int i : problem) {
                    res *= i;
                }
            }
            op_nr--;
            sum += res;
            problem.clear();
        }
    }
    if (ops[op_nr] == '+') {
        res = 0;
        for (int i : problem) {
            res += i;
        }
    }
    else if (ops[op_nr] == '*') {
        res = 1;
        for (int i : problem) {
            res *= i;
        }
    }
    sum += res;
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

    vector<vector<char>> digits;
    vector<char> ops;
    string line;
    while (getline(inputFile, line)) {
        if (!isalnum(line[0]) && line[0] != ' ') break;
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        digits.push_back(row);
    }

    stringstream ss(line);
    char c;
    while (ss >> c) {
        ops.push_back(c);
    }

    solve(digits, ops);
}
