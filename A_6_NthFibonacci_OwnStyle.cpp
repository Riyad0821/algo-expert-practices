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

vi g[N];
int a[N];

//Time O(n^2) | Space(n)

int Fib0(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        return Fib0(n - 1) + Fib0(n - 2);
    }
}

//Time O(n) | Space(n)

int Fib1Helper(int n, int a[], bool flag[])
{
    if (flag[n])
        return a[n];
    else
    {
        flag[n] = true;
        a[n] = Fib1Helper(n - 1, a, flag) + Fib1Helper(n - 2, a, flag);
        return a[n];
    }
}

int Fib1(int n)
{
    int arr[n + 1];
    bool flag[n + 1];
    memset(flag, 0, sizeof(flag) + 1);
    memset(arr, 0, sizeof(arr) + 1);
    arr[1] = 0;
    arr[2] = 1;
    flag[1] = true;
    flag[2] = true;
    arr[n] = Fib1Helper(n, arr, flag);
    return arr[n];
}

//Time O(n) | Space(1)

int Fib2(int n)
{
    int prev1 = 0, prev2 = 1;
    for (int i = 3; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
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
    r = Fib0(n);
    x = Fib1(n);
    y = Fib2(n);
    pi(r);
    pi(x);
    pi(y);

    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}
