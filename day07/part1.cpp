#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve(vector<string>& space) {
    int splits = 0;
    set<int> beams;
    for (size_t i = 0; i < space[0].size(); ++i) {
        if (space[0][i] == 'S') {
            space[0][i] = '|';
            beams.insert(i);
            break;
        }
    }

    for (size_t i = 1; i < space.size(); ++i) {
        set<int> new_beams;
        for (int b : beams) {
            if (space[i][b] == '.') {
                space[i][b] = '|';
                new_beams.insert(b);
            } else if (space[i][b] == '^') {
                ++splits;
                if (b - 1 >= 0) {
                    space[i][b-1] = '|';
                    new_beams.insert(b-1);
                }
                if (b + 1 < space[0].size()) {
                    space[i][b+1] = '|';
                    new_beams.insert(b+1);
                }
            }
        }
        beams = new_beams;
    }
    cout << splits << endl;

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

    vector<string> space;
    string line;
    while (getline(inputFile, line)) {
        space.push_back(line);
    }
    solve(space);
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
