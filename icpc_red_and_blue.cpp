#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int d[n];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        int ans = 0;
        int painted = -1; // stores till where we have painted..
        //
        int last = 0; // which last blue was painted. 
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                if (painted < i)  // agar yha tk paint nhi hua hai toh -1,, example   BRR ,, here first blue can never be painted
                    return -1;
                if (last < i)   // agr av jo blue aaya hai wo pahle paint nhi hua toh ans++ aur painted ko wha tk shift nhi toh continue.
                {
                    ans++;
                    last = painted;
                }
            }
        //    if (s[i] == 'R')
                painted = max(painted, (i + d[i]));   // paint karte jao jha tk ho rha pr count nhi krna 
        }
        return ans;
    }
};

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solution object;
        cout << object.solve() << "\n";
    }
    return 0;
}
