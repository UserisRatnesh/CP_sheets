#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
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
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
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

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll d = c - b;
  ll new_a = b - d;
  if (new_a % a == 0 && new_a > 0) {
    cout << "Yes" << endl;
    return;
  }

  d = (c - a) / 2;
  ll new_b = a + d;
  if ((c - a) % 2 == 0 && new_b % b == 0 && new_b > 0) {
    cout << "Yes" << endl;
    return;
  }

  d = b - a;
  ll new_c = b + d;
  if (new_c > 0 && new_c % c == 0) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
