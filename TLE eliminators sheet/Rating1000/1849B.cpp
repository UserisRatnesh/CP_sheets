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
  for (ll i = 0; i < n; i++) {
    ll val;
    cin >> val;
    if (val % k == 0) {
      vec[i] = k;
    } else {
      vec[i] = val % k;
    }
  }

  vector<ll> ord(n);

  // NOTE: fills the ord array with values starting with 0 and increamet by one
  // each time
  iota(all(ord), 0);

  // NOTE: Why stable sort ?
  // Because jab vec[i] == vec[j] then the orderign is not fixed in simple sort,
  // but in stable_sort if i appears before sorting then even after sorting it
  // will appear before in this special case.
  stable_sort(all(ord),
              [&](const ll i, const ll j) { return vec[i] > vec[j]; });

  for (auto it : ord) {
    cout << it + 1 << " ";
  }
  cout << endl;
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
