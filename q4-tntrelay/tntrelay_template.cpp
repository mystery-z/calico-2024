#include <iostream>
#include <string>

using namespace std;

/**
 * Return the maximum number of players that can make it across the TNT bridge.
 * If infinitely many players can complete the course, return -1
 *
 * N: number of blocks in the course
 * K: maximum jump distance of every player
 * S: description of the TNT bridge
 */

// Handle check to see if this is start pos
pair<int, string> getFarthestJump(int K, int curPos, string &S) {
    for (int i = K; i >= 0; i--)
    {
        // Checks if can jump to the end
        int len = S.length();
        if (i+curPos >= len)
        {
            // Checks if can jump from start to end (infinity)
            if (curPos == -1)
            {
                // cout << S.length() << " " << i << " " << curPos << " " << i+curPos;
                return make_pair(-4, S);
            }
            
            return make_pair(-3, S);
        }
        
        // No Jumps being made
        if (i == 0) 
        {
            return make_pair(-2, S);
        }

        // Checks if next jump is possible
        if (S[curPos+i] == '#')
        {
            S[curPos+i] = '-';
            return make_pair(curPos+i, S);
        }

        
    }
    

    return make_pair(-2, S);
}

int solve(int N, int K, string S)
{
    int totalPlayers = 0;

    pair<int, string> output = make_pair(-1, S);
    int i = 0;
    while (true)
    {
        // cout << "ITER: " << i << " POS: " << output.first << " String: " << output.second << endl;
        output = getFarthestJump(K+1, output.first, output.second);
    
        if (output.first == -4)  return -1; // For infinite runs
        
        if (output.first == -3) {
            output.first = -1;
            totalPlayers++; // Reached end
        }

        if (output.first == -2)  return totalPlayers; // Can't reach end
        
        i++;
    }

    return totalPlayers;
}




int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        cout << solve(N, K, S) << '\n';
    }
}
