#include <iostream>

int min(int a, int b, int c, int d) {
  return a < b ? (c < a ? (d < c ? d : min(a, b, d, c)) : min(c, b, a, d)) : min(b, a, c, d);
}
int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << min(a, b, c, d);
  return 0;
}
