#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve(const vector<pair<ll,ll>>& reds) {
    ll max_area = 0;
    ll area;

    for (const auto [x1, y1] : reds) {
        for (const auto [x2, y2] : reds) {
            area = (abs(x2-x1)+1) * (abs(y2-y1)+1);
            if (area > max_area) {
                max_area = area;
            }
        }
    }

    cout << max_area << endl;
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

    vector<pair<ll,ll>> reds;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        ll n1, n2;
        char c; //comma
        ss >> n1 >> c >> n2;
        reds.push_back({n1,n2});
    }

    solve(reds);

    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
