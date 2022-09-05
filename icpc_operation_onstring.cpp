#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int32_t main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int ans = 0;
        vector<int> block;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ans++;
            }
            else
            {
                int count = 0;
                while (s[i] == '0' && i < n)
                {
                    count++;
                    i++;
                }
                block.push_back(count);
                count = 0;
                i--;
            }
        }
        sort(block.begin(), block.end(), greater<int>());
        for (auto it : block)
        {
            if (x > 2 * it)
            {
                ans += it;
                x = x - (2 * it + 1);
            }
            else
            {
                ans += (x - 1) / 2;
                break;
            }
            if (x < 3)
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}

// x= 2*k+1