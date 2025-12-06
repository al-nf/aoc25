#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void fresh(const vector<pair<ull,ull>>& ranges, const vector<ull>& fruit) {
    int count = 0;
    for (ull f : fruit) {
        for (auto r : ranges) {
            if (f >= r.first && f <= r.second) {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}

int main(int, char *argv[]) 
{
    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    vector<pair<ull,ull>> ranges;
    vector<ull> fruit;

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

    while (getline(inputFile, line)) {
        fruit.push_back(stoull(line));
    }

    fresh(ranges, fruit);

}
