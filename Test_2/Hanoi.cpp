#include <iostream>

void han(int n, int f, int l) {
  if (n > 0) {
    int temp = 6 - f - l;
    if ((l - f) % 3 == 1) {
      han(n - 1, f, temp);
      std::cout << n << " " << f << " " << l << std::endl;
      han(n - 1, temp, l);
    } else {
      han(n - 1, f, l);
      std::cout << n << " " << f << " " << temp << std::endl;
      han(n - 1, l, f);
      std::cout << n << " " << temp << " " << l << std::endl;
      han(n - 1, f, l);
    }
  }

}

int main() {
  int n;
  std::cin >> n;
  han(n, 1, 3);

  return 0;
}
