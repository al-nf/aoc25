#include <bits/stdc++.h>
using namespace std;

typedef uint16_t u16;

int solve(u16 lights, const vector<u16>& buttons) {
    u16 start = 0x0;
    unordered_map<u16, int> dp; // mask, steps
    queue<u16> q; // states
    dp[start] = 0;
    q.push(start);

    while (!q.empty()) {
        u16 state = q.front();
        q.pop();

        int presses = dp[state];
        for (auto button : buttons) {
            u16 next_state = state ^ button;
            if (!dp.count(next_state)) {
                dp[next_state] = presses + 1;
                q.push(next_state);
            }
        }
    }
    return dp[lights];
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
        u16 lights = 0x0;
        vector<u16> buttons;

        stringstream ss(line);
        char c;

        while (ss >> c)
        {
            if (c == '[') {
                string content;
                getline(ss, content, ']');

                lights = 0x0;
                for (size_t i = 0; i < content.size() && i < 16; ++i) {
                    if (content[i] == '#')
                        lights |= (1u << i);
                }
            }

            else if (c == '(') {
                string content;
                getline(ss, content, ')');

                stringstream ps(content);
                u16 button = 0x0;
                int idx;
                char comma;

                while (ps >> idx) {
                    if (idx >= 0 && idx < 16)
                        button |= (1u << idx);
                    ps >> comma;
                }
                buttons.push_back(button);
            }

            else if (c == '{') {
                string junk;
                getline(ss, junk, '}');
            }
        }
        sum += solve(lights,buttons);
    }
    cout << sum << endl;

    auto end = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << "μs" << endl;
}
