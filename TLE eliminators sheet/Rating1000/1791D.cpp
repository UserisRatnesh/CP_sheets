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
  string s;
  cin >> s;

  set<char> st;
  // lets check at splitting at every index
  vector<ll> pref(n, 0);
  pref[0] = 1;
  st.insert(s[0]);
  for (ll i = 1; i < n; i++) {
    if (st.find(s[i]) == st.end()) {
      pref[i] = pref[i - 1] + 1;
      st.insert(s[i]);
    } else {
      pref[i] = pref[i - 1];
    }
  }

  st.clear();
  vector<ll> suff(n, 0);
  suff[n - 1] = 1;
  st.insert(s[n - 1]);
  for (ll i = n - 2; i >= 0; i--) {
    if (st.find(s[i]) == st.end()) {
      suff[i] = suff[i + 1] + 1;
      st.insert(s[i]);
    } else {
      suff[i] = suff[i + 1];
    }
  }

  ll ans = max(pref[n - 1], suff[0]);
  for (ll i = 0; i < n - 1; i++) {
    ans = max(ans, pref[i] + suff[i + 1]);
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
