#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

// [neither, dac only, fft only, both]
array<ull, 4> dfs(const string& cur, const unordered_map<string, vector<string>>& graph, unordered_map<string, array<ull, 4>>& dp) {

    if (dp.count(cur)) return dp[cur];

    array<ull, 4> res = {0, 0, 0, 0};

    if (cur == "out") {
        res[0] = 1;
        return dp[cur] = res;
    }

    auto it = graph.find(cur);
    if (it != graph.end()) {
        for (const auto& child : it->second) {
            auto c = dfs(child, graph, dp);
            if (cur == "dac") {
                res[3] += c[2] + c[3];
                res[1] += c[0] + c[1];
            } else if (cur == "fft") {
                res[3] += c[1] + c[3];
                res[2] += c[0] + c[2];
            } else {
                res[0] += c[0];
                res[1] += c[1];
                res[2] += c[2];
                res[3] += c[3];
            }
        }
    }
    return dp[cur] = res;
}

void solve(const unordered_map<string, vector<string>>& graph) {
    unordered_map<string, array<ull, 4>> dp;
    auto result = dfs("svr", graph, dp);
    cout << result[3] << endl;
}

int main(int, char* argv[]) 
{
    auto start = chrono::high_resolution_clock::now();

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "error opening file" << endl;
        return 1;
    }

    unordered_map<string, vector<string>> graph;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string vertex;
        ss >> vertex;
        vertex.pop_back();

        vector<string> edges;
        string edge;
        while (ss >> edge) edges.push_back(edge);

        graph[vertex] = edges;
    }

    solve(graph);

    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}

