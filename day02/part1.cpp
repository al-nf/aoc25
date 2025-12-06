#include <bits/stdc++.h>
using namespace std;

bool invalid(long n) {
    int dig = log10(n)+1;
    if (dig % 2 == 1) {
        return false;
    }
    
    int half = n / (pow(10, dig/2));
    if ((half * (pow(10, dig/2)) + half) == n) {
        return true;
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

int main(int, char *argv[]) 
{
    auto startt = chrono::high_resolution_clock::now();
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
    auto endt = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(endt-startt).count() << "μs" << endl;
}
