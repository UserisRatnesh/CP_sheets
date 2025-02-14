#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

// NOTE: Find xor of first n natural numbers in constant time
ll findXor(ll n) {
  if (n % 4 == 1) {
    return n - 1;
  }
  if (n % 4 == 2) {
    return 1;
  }
  if (n % 4 == 3) {
    return n;
  }
  return 0;
}

void solve() {
  ll a, b;
  cin >> a >> b;

  ll xr = findXor(a);
  if (xr == b) {
    cout << a << endl;
    return;
  }
  if ((xr ^ b) == a) {
    cout << a + 2 << endl;
    return;
  }
  cout << a + 1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}