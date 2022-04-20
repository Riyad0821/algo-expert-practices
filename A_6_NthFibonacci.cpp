#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define si(x) scanf("%d", &x)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

//O(2^n) time | O(n) space
int getNthFib0(int n)
{
    if (n == 2)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 0;
    }
    else
    {
        return getNthFib0(n - 1) + getNthFib0(n - 2);
    }
}

int getNthFib1(int n);
int helper(int n, unordered_map<int, int> memoize);

//O(n) time | O(n) space
int getNthFib1(int n)
{
    unordered_map<int, int> memoize({{1, 0}, {2, 1}});
    return helper(n, memoize);
}

int helper(int n, unordered_map<int, int> memoize)
{
    if (memoize.find(n) != memoize.end())
    {
        return memoize[n];
    }
    else
    {
        memoize[n] = helper(n - 1, memoize) + helper(n - 2, memoize);
        return memoize[n];
    }
}

//O(n) time | O(1) space

int getNthFib2(int n)
{
    int lastTwo[] = {0, 1};
    int counter = 3;
    while (counter <= n)
    {
        int nextFib = lastTwo[0] + lastTwo[1];
        lastTwo[0] = lastTwo[1];
        lastTwo[1] = nextFib;
        counter++;
    }
    return n > 1 ? lastTwo[1] : lastTwo[0];
}
int main()
{
    ios_base::sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, j, k, p, q, r, x, y, u, v, n, m;
    si(n);
    r = getNthFib0(n);
    x = getNthFib1(n);
    y = getNthFib2(n);
    pi(r);
    pi(x);
    pi(y);

    return 0;
}
