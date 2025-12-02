#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool invalid(long n) {
    string s = to_string(n);
    int len = s.length();
    
    for (int pattern_len = 1; pattern_len <= len / 2; ++pattern_len) {
        if (len % pattern_len != 0) {
            continue;
        }
        
        string pattern = s.substr(0, pattern_len);
        
        bool matches = true;
        for (int i = pattern_len; i < len; i += pattern_len) {
            if (s.substr(i, pattern_len) != pattern) {
                matches = false;
                break;
            }
        }
        
        if (matches) {
            return true;
        }
    }
    
    return false;
}

void sum(const vector<pair<long, long>>& ranges) {
    unsigned long long ans = 0;
    for (const auto& p : ranges) {
        for (long i = p.first; i <= p.second; ++i) {
            if (invalid(i)) {
                ans += i;
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) 
{
    ifstream inputFile(argv[1]);

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    string line;
    getline(inputFile, line);
    size_t start = 0;
    size_t end;
    vector<pair<long, long>> data;

    while (start < line.length()) {
        end = line.find('-', start);
        if (end == string::npos) break;
        
        long low = stol(line.substr(start, end - start));
        start = end + 1;
        
        end = line.find(',', start);
        long high;
        if (end == string::npos) {
            high = stol(line.substr(start));
            data.push_back(make_pair(low, high));
            break;
        } else {
            high = stol(line.substr(start, end - start));
            data.push_back(make_pair(low, high));
            start = end + 1;
        }
    }
    sum(data);
}
