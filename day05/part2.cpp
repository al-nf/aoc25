#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void fresh(vector<pair<ull,ull>> ranges) {
    sort(ranges.begin(), ranges.end());
    
    vector<pair<ull,ull>> merged;
    for (auto [start, end] : ranges) {
        if (merged.empty() || merged.back().second < start - 1) {
            merged.push_back({start, end});
        } else {
            merged.back().second = max(merged.back().second, end);
        }
    }
    
    ull count = 0;
    for (auto [start, end] : merged) {
        count += (end - start + 1);
    }
    cout << count << endl;
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

    vector<pair<ull,ull>> ranges;

    string line;
    while (getline(inputFile, line) && line != "") {
        string first;
        int i = 0;
        for (;i < line.size() && line[i] != '-'; ++i) {
            first.push_back(line[i]);
        }
        ++i;
        string second;
        for (;i < line.size(); ++i) {
            second.push_back(line[i]);
        }
        ranges.push_back({stoull(first), stoull(second)});
    }
    fresh(ranges);
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
