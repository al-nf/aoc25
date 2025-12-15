#include <bits/stdc++.h>
using namespace std;

void dfs(string cur, const unordered_map<string, vector<string>>& graph,
        unordered_set<string>& visited, vector<string>&path, vector<vector<string>>& all_paths) {
    visited.insert(cur);
    path.push_back(cur);

    if (cur == "out") {
        all_paths.push_back(path);
    } else {
        auto it = graph.find(cur);
        if (it != graph.end()) {
            for (const string& edge : it->second) {
                if (visited.find(edge) == visited.end()) {
                    dfs(edge, graph, visited, path, all_paths);
                }
            }
        }
    }
    path.pop_back();
    visited.erase(cur);
}

void solve(const unordered_map<string,vector<string>>& graph) {
    vector<vector<string>> all_paths;
    vector<string> path;
    unordered_set<string> visited;

    dfs("you", graph, visited, path, all_paths);
    cout << all_paths.size() << endl;
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

    unordered_map<string, vector<string>> graph;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string vertex;
        ss >> vertex;
        vertex.pop_back();

        vector<string> edges;
        string edge;
        while (ss >> edge) {
            edges.push_back(edge);
        }
        graph[vertex] = edges;
    }

    solve(graph);
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
