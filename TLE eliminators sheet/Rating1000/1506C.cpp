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

// Without recursion
void solveBetter() {
  string a, b;
  cin >> a >> b;

  ll m = sz(a);
  ll n = sz(b);
  ll ans = 0;
  for (ll len = 1; len <= min(m, n); len++) {
    for (ll j = 0; j + len <= m; j++) {
      for (ll k = 0; k + len <= n; k++) {
        if (a.substr(j, len) == b.substr(k, len)) {
          ans = max(len, ans);
        }
      }
    }
  }

  cout << m + n - 2 * ans << nline;
}

// With recursion
// NOTE: find the maximum length of subarray of a that is present b
ll helper(string a, string b, map<string, ll>& mpp) {
  if (sz(a) == 0) {
    return 0;
  }
  if (mpp.find(a) != mpp.end()) {
    return mpp[a];
  }
  if (b.find(a) != string::npos) {
    return sz(a);
  }

  ll removeFirst = helper(a.substr(1), b, mpp);
  ll removeLast = helper(a.substr(0, sz(a) - 1), b, mpp);

  mpp[a] = max(removeLast, removeFirst);
  return mpp[a];
}

void solve() {
  string a, b;
  cin >> a >> b;

  ll ans = 0;
  ll subArrLen = INF;
  map<string, ll> mpp;
  if (sz(a) > sz(b)) {
    subArrLen = helper(b, a, mpp);
  } else {
    subArrLen = helper(a, b, mpp);
  }
  ans = sz(a) + sz(b) - 2 * subArrLen;

  cout << ans << endl;
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
    solveBetter();
  }
}