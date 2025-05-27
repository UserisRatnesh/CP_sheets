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
#define nl "\n"
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

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

/*
   _____          _        ____       _
  / ____|        | |      |  _ \     | |
 | |     ___   __| | ___  | |_) | ___| | _____      __
 | |    / _ \ / _` |/ _ \ |  _ < / _ \ |/ _ \ \ /\ / /
 | |___| (_) | (_| |  __/ | |_) |  __/ | (_) \ V  V /
  \_____\___/ \__,_|\___| |____/ \___|_|\___/ \_/\_/

*/

// TC : O(n^2) => TLE
int dfs(int node, string &colors, vector<vector<int>> &adj, map<char, int> &mpp,
        vector<bool> &vis, int &ans) {

  if (vis[node]) {
    return -1;
  }

  vis[node] = true;
  char color = colors[node];
  mpp[color]++;

  for (auto it : mpp) {
    ans = max(ans, it.second);
  }

  int n = colors.size();
  for (int i = 0; i < n; i++) {

    if (adj[node][i] == 1) {
      int smallAns = dfs(i, colors, adj, mpp, vis, ans);
      if (smallAns == -1) {
        return -1;
      }
    }
  }

  mpp[color]--;
  vis[node] = false;

  return 0;
}

int largestPathValue(string colors, vector<vector<int>> &edges) {
  int n = colors.size();
  vector<vector<int>> adj(n, vector<int>(n, 0));
  for (auto it : edges) {
    int u = it[0];
    int v = it[1];
    adj[u][v] = 1;
  }

  // we will do dfs
  int ans = -1;
  vector<bool> vis(n, false);
  map<char, int> mpp;
  for (int i = 0; i < n; i++) {
    if (vis[i] == false) {
      mpp.clear();
      int smallAns = dfs(i, colors, adj, mpp, vis, ans);
      if (smallAns == -1) {
        return -1;
      }
    }
  }

  return ans;
}

// Better approach
int largestPathValueBetter(string colors, vector<vector<int>> &edges) {

  int n = colors.size();
  vector<vector<int>> adj(n);
  vector<int> indeg(n, 0);

  for (auto it : edges) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    indeg[v]++;
  }

  vector<vector<int>> countCol(n, vector<int>(26, 0));
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      que.push(i);
      int col = colors[i] - 'a';
      countCol[i][col] = 1;
    }
  }

  int ans = -1;
  int countNodes = 0;

  while (!que.empty()) {

    int node = que.front();
    que.pop();
    countNodes++;

    ans = max(ans, countCol[node][colors[node] - 'a']);

    for (int child : adj[node]) {

      for (int col = 0; col < 26; col++) {
        countCol[child][col] =
            max(countCol[child][col],
                countCol[node][col] + (colors[child] - 'a' == col));
      }
      indeg[child]--;
      if (indeg[child] == 0) {
        que.push(child);
      }
    }
  }

  if (countNodes < n) {
    return -1;
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();

  string colors = "abaca";
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
  int ans = largestPathValueBetter(colors, edges);
  cout << ans << nl;
}
