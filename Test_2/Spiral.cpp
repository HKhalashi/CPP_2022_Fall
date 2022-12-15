#include <iostream>

void print_spiral(int m_size, int start_int_1, int start_int_2, int * arr[], int val, bool flag) {

  if (m_size == 1) {
    arr[start_int_1][start_int_2] = val;
    return;
  }
  if (flag == 1) {
    for (int i = 0; i < m_size; i++) {

      arr[start_int_1][start_int_2 + i] = val;
      val++;
    }
    val--;
    for (int j = 0; j < m_size; j++) {
      arr[start_int_1 + j][start_int_2 + m_size - 1] = val;
      val++;
    }
    print_spiral(m_size - 1, start_int_1 + m_size - 1, start_int_2 + m_size - 2, arr, val, 0);
  }
  if (flag == 0) {

    for (int i = 0; i < m_size; i++) {
      arr[start_int_1][start_int_2 - i] = val;
      val++;
    }
    val--;
    for (int j = 0; j < m_size; j++) {
      arr[start_int_1 - j][start_int_2 - m_size + 1] = val;
      val++;
    }
    print_spiral(m_size - 1, start_int_1 - m_size + 1, start_int_2 - m_size + 2, arr, val, 1);
  }

}

int main() {
  int n = 0;
  std::cin >> n;

  int * arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = new int[n];
  print_spiral(n, 0, 0, arr, 1, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
