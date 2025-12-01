#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve_pass(const vector<string>& rotations) {
    int pos = 50;
    int ans = 0;
    int last = pos;
    bool passed;
    int rot;

    for (string line : rotations) {
        rot = stoi(line.substr(1));
        while (rot > 99) {
            ans++;
            rot -= 100;
        }
        switch (line[0]) {
            case 'L':
                pos -= rot;
                if (pos < 0) {
                    pos += 100;
                    if (last != 0) ans++;
                    passed = true;
                }
                break;
            case 'R':
                pos += rot;
                if (pos > 99) {
                    pos -= 100;
                    if (last != 0) ans++;
                    passed = true;
                }
                break;
            default:
                break;
        }
        if (pos == 0 && !passed) ans++;
        last = pos;
        passed = false;
    }
    cout << ans;
}

int main(int argc, char *argv[]) 
{
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
}
