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
        int painted = -1;
        //
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                if (painted < i)
                    return -1;
                if (last < i)
                {
                    ans++;
                    last = painted;
                }
            }
            if (s[i] == 'R')
                painted = max(painted, (i + d[i]));
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