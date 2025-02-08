
#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    long long col, row;
    cin >> col >> row;
    col--; // Adjusting 1-based indexing
    row--; // Adjusting 1-based indexing

    long long ans = 0;

    if (row > col) {
      if (row % 2 == 0) {
        ans = (row + 1) * (row + 1) - col;
      } else {
        ans = row * row + col + 1;
      }
    } else {
      if (col % 2 == 0) {
        ans = col * col + row + 1;
      } else {
        ans = (col + 1) * (col + 1) - row;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
