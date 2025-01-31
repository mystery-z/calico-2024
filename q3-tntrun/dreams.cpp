#include <iostream>
#include <vector>

using namespace std;

/**
 * Output YES if it is possible for the player to run on the course such that it
 * consists of blocks and banned otherwise.
 * 
 * N: the number of blocks in the course.
 * S: the list of starting blocks
 * E: the list of ending blocks
 */
void solve(int N, vector<char> S, vector<char> E) {
    vector<int> posWalked;
    int dist = 0;

    for (int i = 0; i < S.size(); i++)
    {
        dist++;
        if (S[i] != E[i])
        {
            posWalked.push_back(i);
            dist = 0;
        }

        if (dist > 4)
        {
            cout << "banned" << '\n';
            return;
        }
        
    }
    cout << "YES" << '\n';
    // for (int i = 0; i < posWalked.size()-1; i++)
    // {
    //     if (posWalked[i] - posWalked[i+1] > 4)
    //     {
    //         cout << "banned" << '\n';
    //         return;
    //     }
        
    // }
    return;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<char> S(N);
        for (char &item : S) {
            cin >> item;
        }
        vector<char> E(N);
        for (char &item : E) {
            cin >> item;
        }
        solve(N, S, E);
    }
}