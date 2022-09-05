#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long int
const ll MOD = 1e9 + 7;

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll powerLL(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}
ll powerStrings(string sa, string sb)
{
    // We convert strings to number

    ll a = 0, b = 0;

    // calculating  a % MOD
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;

    // calculating  b % (MOD - 1)
    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);
    b /= 2;
    // Now a and b are long long int. We
    // calculate a^b using modulo exponentiation
    return powerLL(a, b);
}
int32_t main()
{
    fast();
    int tt;
    cin >> tt;
    while (tt--)
    {
        string a, b;
        cin >> a >> b;
        if (a[0] == '-')
        {
            cout << "1\n";
            continue;
        }
        // ll remainderB = 0;
        // for (int i = 0; i < b.length(); i++)
        //     remainderB = (remainderB * 10 + b[i] - '0') % (MOD - 1);
        cout << powerStrings(a, b) << endl;
    }
    return 0;
}