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
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  bool isProduct = false;
  ll even = 0;
  ll minRemDiff = LLONG_MAX;
  for (ll i = 0; i < n; i++) {
    cin >> vec[i];
    if (vec[i] % 2 == 0) {
      even++;
    }
    ll rem = vec[i] % k;
    if (rem == 0) {
      isProduct = true;
    } else {
      minRemDiff = min(minRemDiff, abs(k - rem));
    }
  }
  if (isProduct) {
    cout << 0 << endl;
    return;
  }

  if (k == 4) {
    ll ans = LLONG_MAX;
    if (even >= 2) {
      ans = 0;
    } else if (even == 1) {
      ans = min(minRemDiff, 1ll);
    } else {
      ans = min(minRemDiff, 2ll);
    }
    cout << ans << endl;
    return;
  }

  cout << minRemDiff << endl;
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
