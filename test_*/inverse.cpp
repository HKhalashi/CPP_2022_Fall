#include <iostream>

void inverse(int count, ...) {
  int * p = & count;
  if (count == 1) {
    std::cout << * (p + sizeof(short)) << std::endl;
    return;
  }
  for (int i = count; 0 < i; i -= 2) {
    std::cout << * (p + i * sizeof(short)) << std::endl;
    inverse(1, *(p + (i - 1) * sizeof(short)));
  }

}

int main() {
  inverse(4, 4, 5, 6, 7);
  return 0;
}
