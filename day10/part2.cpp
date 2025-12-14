#include <bits/stdc++.h>
using namespace std;

typedef uint16_t u16;

void solve(const vector<int>& jolts, const vector<vector<int>>& buttons) {
    
}

int main(int, char *argv[])
{
    auto start = chrono::high_resolution_clock::now();

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "error opening file" << endl;
        return 1;
    }

    int sum = 0;
    string line;
    while (getline(inputFile, line))
    {
        vector<int> jolts;
        vector<vector<int>> buttons;

        stringstream ss(line);
        char c;

        while (ss >> c)
        {
            if (c == '(') {
                string content;
                getline(ss, content, ')');

                stringstream ps(content);
                int idx;
                char comma;
                vector<int> row;

                while (ps >> idx) {
                    row.push_back(idx);
                    ps >> comma;
                }
                buttons.push_back(row);
            }
            else if (c == '{') {
                string content;
                getline(ss, content, '}');

                stringstream ps(content);
                int idx;
                char comma;

                while (ps >> idx) {
                    jolts.push_back(idx);
                    ps >> comma;
                }
            }
        }
    }

    solve(jolts, buttons);
    cout << sum << endl;

    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
