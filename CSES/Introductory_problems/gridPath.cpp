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

vector<pair<string, ll>> allPaths;
vector<vector<bool>> vis(7, vector<bool>(7, false));

void getAllPaths(int x, int y, string pathStr, ll steps) {

  if (x < 0 || x >= 7 || y < 0 || y >= 7 || vis[x][y]) {
    return;
  }
  if (x == 6 && y == 0) {
    if (steps == 48) {
      allPaths.pb({pathStr, steps});
    }
    return;
  }

  // check if the grid is being splitted in two section or not
  // if yes then return

  vis[x][y] = true;
  getAllPaths(x, y + 1, pathStr + "R", steps + 1);
  getAllPaths(x + 1, y, pathStr + "D", steps + 1);
  getAllPaths(x, y - 1, pathStr + "L", steps + 1);
  getAllPaths(x - 1, y, pathStr + "U", steps + 1);
  vis[x][y] = false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  getAllPaths(0, 0, "", 0);
  cout << allPaths.size() << endl;
  string str;
  cin >> str;
  // iterate over all paths having steps equals str size

  ll ans = 0;
  int n = sz(str);
  for (auto it : allPaths) {
    if (it.second != n) {
      continue;
    }
    bool isPath = true;
    for (int i = 0; i < n; i++) {
      if (str[i] == '?') {
        continue;
      }
      if (str[i] != it.first[i]) {
        isPath = false;
        break;
      }
    }
    if (isPath) {
      ans++;
    }
  }

  cout << ans << endl;
}
