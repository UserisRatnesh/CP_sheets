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
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  vector<ll> freqA(2 * n + 1, 0);
  ll prev = -1;
  ll count = 1;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == prev) {
      count++;
    } else {
      count = 1;
      prev = a[i];
    }
    freqA[a[i]] = max(freqA[a[i]], count);
  }

  vector<ll> freqB(2 * n + 1, 0);
  prev = -1;
  count = 1;
  for (ll i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == prev) {
      count++;
    } else {
      count = 1;
      prev = b[i];
    }
    freqB[b[i]] = max(freqB[b[i]], count);
  }

  ll ans = LLONG_MIN;
  for (ll i = 0; i < 2 * n + 1; i++) {
    ans = max(ans, freqA[i] + freqB[i]);
  }
  cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
