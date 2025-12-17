#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

class DSU {
    public:
        vector<int> parent;
        vector<int> size;
        
        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); 
            }
            return parent[x];
        }
        
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false; 
            
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            return true;
        }
        
        int getSize(int x) {
            return size[find(x)];
        }
};

void solve(const vector<tuple<int,int,int>>& boxes) {
    int n = boxes.size();
    DSU dsu(n);
    
    vector<tuple<ull, int, int>> edges; 
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            const auto [x1, y1, z1] = boxes[i];
            const auto [x2, y2, z2] = boxes[j];
            ull dist = (ull)(x2-x1)*(x2-x1) + (ull)(y2-y1)*(y2-y1) + (ull)(z2-z1)*(z2-z1);
            edges.push_back({dist, i, j});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    int num_components = n; 
    int connection_index = 0;
    
    for (const auto& [dist, i, j] : edges) {
        if (dsu.unite(i, j)) {
            num_components--; 
            connection_index++;
            
            if (num_components == 1) {
                const auto [x1, y1, z1] = boxes[i];
                const auto [x2, y2, z2] = boxes[j];
                
                cout << (ull)x1 * x2 << endl;
                break;
            }
        }
    }
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

    vector<tuple<int,int,int>> boxes;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int n1, n2, n3;
        char c; //comma
        ss >> n1 >> c >> n2 >> c >> n3;
        boxes.push_back({n1,n2,n3});
    }

    solve(boxes);

    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
