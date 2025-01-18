#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h" // Local include for your setup
#else
#include <bits/stdc++.h> // Standard include for online judges
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
  vector<string> adj(n);
  for (ll i = 0; i < n; i++) {
    cin >> adj[i];
  }

  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    // Try to find the position of i

    int pos = 0;
    for (int j = 0; j < n; j++) {
      if (j < i && adj[i][j] == '1') {
        pos++;
      } else if (j > i && adj[i][j] == '0') {
        pos++;
      }
    }
    ans[pos] = i;
  }

  for (ll val : ans) {
    cout << val + 1 << " ";
  }
  cout << endl;
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

  return 0;
}
