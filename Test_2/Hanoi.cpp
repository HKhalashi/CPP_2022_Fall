#include <iostream>


void han(int n, int f, int l) {
  int t = 6 - f - l;
  if (n > 0)
    if (f % l == f) {
      han(n - 1, f, l);
      std::cout << n << " " << f << " " << t << std::endl;
      han(n - 1, l, f);
      std::cout << n << " " << t << " " << l << std::endl;
      han(n - 1, f, l);
    }
  else {
    han(n - 1, f, t);
    std::cout << n << " " << f << " " << l << std::endl;
    han(n - 1, t, l);
  }

}

int main() {
  int n;
  std::cin >> n;
  han(n, 1, 3);
  return 0;
}
