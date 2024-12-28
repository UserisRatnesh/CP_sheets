#include <iostream>
#include <set>
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

bool isSafe(int row, int col, set<pair<int, int>> &st) {
  for (pair p : st) {
    if (row == p.first || col == p.second ||
        (row + col) == (p.first + p.second) ||
        (row - col) == (p.first - p.second)) {
      return false;
    }
  }
  return true;
}

ll solve(int row, char board[8][8], set<pair<int, int>> &st) {
  if (row == 8) {
    return 1;
  }

  ll ans = 0;
  for (int col = 0; col < 8; col++) {
    // check that row with column is suitable for queen placement or not
    if (board[row][col] == '.' && isSafe(row, col, st)) {
      // Put a queen here
      st.insert({row, col});
      ans += solve(row + 1, board, st);
      st.erase({row, col});
    }
  }

  return ans;
}

int main() {
  fastio(); // To enable fast IO.

  char board[8][8];
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> board[i][j];
    }
  }

  set<pair<int, int>> st;
  cout << solve(0, board, st) << endl;
}
