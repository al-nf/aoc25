#include <bits/stdc++.h>

using namespace std;

void solve_pass(const vector<string>& rotations) {
    int pos = 50;
    int ans = 0;
    int rot;

    for (string line : rotations) {
        rot = stoi(line.substr(1));
        while (rot > 99) {
            rot -= 100;
        }
        switch (line[0]) {
            case 'L':
                pos -= rot;
                if (pos < 0) {
                    pos += 100;
                }
                break;
            case 'R':
                pos += rot;
                if (pos > 99) {
                    pos -= 100;
                }
                break;
            default:
                break;
        }
        if (pos == 0) ans++;
    }
    cout << ans << endl;
}

int main(int, char *argv[]) 
{
    auto start = chrono::high_resolution_clock::now();
    ifstream inputFile(argv[1]);
    vector<string> data;

    if (!inputFile) 
    {
        cerr << "error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) 
    {
        data.push_back(line);
    }

    solve_pass(data);
    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
