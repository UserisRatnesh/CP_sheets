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

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vec;
  for (ll i = 0; i < n; i++) {
    ll val;
    cin >> val;
    vec.pb(mp(val, i));
  }

  // NOTE: finding the totalMinCost
  sort(all(vec));
  ll totalCost = 0;
  ll pos = 1;
  ll count = 0;

  // To Store position of each building
  vector<ll> position(n);

  for (ll i = n - 1; i >= 0; i--) {
    ll val = vec[i].first;
    totalCost += 2 * (val * pos);
    count++;
    if (count == 2) {
      position[vec[i].second] = -pos;
      pos++;
      count = 0;
    } else {
      position[vec[i].second] = pos;
    }
  }

  cout << totalCost << nline;
  cout << 0 << " ";
  for (auto it : position) {
    cout << it << " ";
  }
  cout << nline;
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