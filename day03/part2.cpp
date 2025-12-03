#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

void solve(const vector<vector<int>>& data) {
    ull sum = 0;
    for (const vector<int>& row : data) {
        vector<int> selected;
        int remaining = 12;
        
        // sliding window! :3
        for (size_t i = 0; i < row.size() && remaining > 0; ++i) {
            int max_digit = -1;
            size_t max_pos = i;
            size_t window_end = row.size() - remaining + 1;
            
            for (size_t j = i; j < window_end; ++j) {
                if (row[j] > max_digit) {
                    max_digit = row[j];
                    max_pos = j;
                }
            }
            
            selected.push_back(max_digit);
            i = max_pos;
            remaining--;
        }
        
        ull num = 0;
        for (int digit : selected) {
            num = num * 10 + digit;
        }
        
        sum += num;
        //cout << num << endl;
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
