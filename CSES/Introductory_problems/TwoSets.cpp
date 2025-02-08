#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if ((n & 1) == 0) {
    if (((n / 2) & 1) == 0) {
      cout << "YES" << endl << 2 * n / 4 << endl;

      // print first set
      for (int i = 1; i <= n / 4; ++i) {
        cout << i << " ";
      }
      for (int i = n; i > 3 * n / 4; --i) {
        cout << i << " ";
      }
      cout << endl << 2 * n / 4 << endl;

      // print second set
      for (int i = n / 4 + 1; i <= 3 * n / 4; ++i) {
        cout << i << " ";
      }
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (((n / 2) & 1) == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if ((n / 4) == 0) {
        cout << (n + 1) / 2 << endl;
      } else {

        cout << n / 2 << endl;
      }
      int mid = (n + 1) / 2;
      for (int i = 1; i < n / 4; ++i) {
        cout << i << " ";
      }
      for (int i = n; i > 3 * (n + 1) / 4; --i) {
        cout << i << " ";
      }
      cout << mid << " " << mid - 1 << endl;

      // print second half
      if ((n / 4) == 0) {
        cout << n / 2 << endl;
      } else {

        cout << (n + 1) / 2 << endl;
      }
      for (int i = n / 4; i <= 3 * (n + 1) / 4; ++i) {
        if (i == mid || i == mid - 1) {
          continue;
        }
        if (i > 0) {
          cout << i << " ";
        }
      }
    }
  }
}

void solveBetter() {
  long n;
  cin >> n;
  long sum = n * (n + 1) / 2;
  if (sum & 1) {
    cout << "NO" << endl;
    return;
  }

  vector<bool> vis(n + 1, false);
  vector<long> first, second;
  long hs = 0;
  for (long i = n; i > 0; --i) {
    long diff = sum / 2 - hs;
    if (diff < i) {
      break;
    }
    hs += i;
    first.push_back(i);
    vis[i] = true;
  }

  if (hs != sum / 2) {
    long rem = sum / 2 - hs;
    first.push_back(rem);
    vis[rem] = true;
  }

  for (long i = 1; i < n; i++) {
    if (!vis[i]) {
      second.push_back(i);
    }
  }

  // printing the ans
  cout << "YES" << endl << first.size() << endl;
  for (long value : first) {
    cout << value << " ";
  }
  cout << endl << second.size() << endl;
  for (long value : second) {
    cout << value << " ";
  }
}

int main() {

  solveBetter();
  return 0;
}
