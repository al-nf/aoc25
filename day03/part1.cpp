#include <bits/stdc++.h>
using namespace std;

void solve(const vector<vector<int>>& data) {
    int sum = 0;
    for (vector<int> row : data) {
        // for each row, find the max
        // then find the max after that
        int max = -1;
        int max_index = 0;
        for (size_t i = 0; i < row.size()-1; ++i) {
            if (row[i] > max){
                max = row[i];
                max_index = i;
            }
        }

        int second_max = -1;
        for (size_t i = max_index + 1; i < row.size(); ++i) {
            if (row[i] > second_max) second_max = row[i];
        }

        sum += (max*10 + second_max);
    }
    cout << sum << endl;
}

int main(int argc, char *argv[]) 
{
    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    vector<vector<int>> data;
    string line;
    while(getline(inputFile, line)) {
        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        data.push_back(row);
    }

    solve(data);
}
