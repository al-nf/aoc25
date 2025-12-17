#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve(const vector<pair<ll,ll>>& reds) {
    set<pair<ll,ll>> boundary;

    for (size_t i = 0; i < reds.size(); ++i) {
        ll x1 = reds[i].first;
        ll y1 = reds[i].second;
        ll x2 = reds[(i + 1) % reds.size()].first;
        ll y2 = reds[(i + 1) % reds.size()].second;
        
        if (x1 == x2) {
            ll start = min(y1, y2);
            ll end = max(y1, y2);
            for (ll y = start; y <= end; ++y) {
                boundary.insert({x1, y});
            }
        } else {
            ll start = min(x1, x2);
            ll end = max(x1, x2);
            for (ll x = start; x <= end; ++x) {
                boundary.insert({x, y1});
            }
        }
    }
    
    auto is_inside = [&](ll x, ll y) {
        if (boundary.count({x, y})) return true;
        
        int crossings = 0;
        for (size_t i = 0; i < reds.size(); ++i) {
            ll x1 = reds[i].first;
            ll y1 = reds[i].second;
            ll x2 = reds[(i + 1) % reds.size()].first;
            ll y2 = reds[(i + 1) % reds.size()].second;
            
            if (x1 == x2 && x1 < x) {
                ll min_y_edge = min(y1, y2);
                ll max_y_edge = max(y1, y2);
                if (min_y_edge <= y && y < max_y_edge) {
                    crossings++;
                }
            }
        }
        return crossings % 2 == 1;
    };
    
    
    ll max_area = 0;

    for (const auto [x1, y1] : reds) {
        for (const auto [x2, y2] : reds) {
            ll min_rx = min(x1, x2);
            ll max_rx = max(x1, x2);
            ll min_ry = min(y1, y2);
            ll max_ry = max(y1, y2);
            
            ll area = (max_rx - min_rx + 1) * (max_ry - min_ry + 1);
            if (area <= max_area) continue;
            
            if (!is_inside(min_rx, min_ry) || !is_inside(max_rx, min_ry) ||
                !is_inside(min_rx, max_ry) || !is_inside(max_rx, max_ry)) {
                continue;
            }
            
            bool good = true;
            for (ll x = min_rx; x <= max_rx && good; ++x) {
                if (!is_inside(x, min_ry) || !is_inside(x, max_ry)) {
                    good = false;
                }
            }
            for (ll y = min_ry; y <= max_ry && good; ++y) {
                if (!is_inside(min_rx, y) || !is_inside(max_rx, y)) {
                    good = false;
                }
            }
            
            if (good) {
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
