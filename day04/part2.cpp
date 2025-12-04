#include <bits/stdc++.h>
using namespace std;

bool accessible(const vector<vector<char>>& data, int x, int y) {
    int count = 0;
    for (int i = x-1; i <= x+1; ++i) {
        for (int j = y-1; j <= y+1; ++j) {
            if (i >= 0 && j >= 0 && (i != x || j != y) && (i < data.size() && j < data[0].size())) {
                if (data[i][j] == '@') {
                    count++;
                }
            }
        }
    }
    return (count < 4);
}
void solve(vector<vector<char>>& data) {
    int sum = 0;
    while (true) {
        int removed = 0;
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                if (data[i][j] == '@' && accessible(data, i, j)) {
                    sum++; removed++;
                    data[i][j] = 'x';
                }
            }
        }
        if (removed == 0) {
            cout << sum << endl;
            return;
        }
    }
}

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
