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

  string s, t;
  cin >> s >> t;
  vector<int> freq(26, 0);
  for (char c : s) {
    freq[c - 'A']++;
  }

  map<int, int> mpp;
  for (char c : t) {
    int p = c - 'A';
    mpp[p]++;

    // t holds a char that s does not have
    // special case
    if (freq[p] == 0) {
      cout << "NO" << endl;
      return;
    }
  }

  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'A';
    if (freq[c] > mpp[c]) {
      // remove this char
      s[i] = '0';
      freq[c]--;
    }
  }

  // remove all occurances of '0' from s
  s.erase(remove(s.begin(), s.end(), '0'), s.end());

  if (s == t) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
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
