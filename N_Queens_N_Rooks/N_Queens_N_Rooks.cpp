#include <iostream>


#define N 8

int isSafe_2(char board[][N], int r, int c) {
  for (int i = 0; i < r; i++) {
    if (board[i][c] == 'R') {
      return 0;
    }
  }
  return 1;
}

void nRook(char board[][N], int r, int * count) {
  if (r == N) {
    ( * count) ++;

    return;
  }

  for (int i = 0; i < N; i++)

  {
    if (isSafe_2(board, r, i)) {
      board[r][i] = 'R';
      nRook(board, r + 1, count);
      board[r][i] = '-';
    }
  }
}

int isSafe_1(char board[][N], int r, int c) {
  for (int i = 0; i < r; i++) {
    if (board[i][c] == 'Q') {
      return 0;
    }
  }
  for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q') {
      return 0;
    }
  }
  for (int i = r, j = c; i >= 0 && j < N; i--, j++) {
    if (board[i][j] == 'Q') {
      return 0;
    }
  }

  return 1;
}

void nQueen(char board[][N], int r, int * count) {
  if (r == N) {
    ( * count) ++;
    return;
  }

  for (int i = 0; i < N; i++)

  {
    if (isSafe_1(board, r, i)) {
      board[r][i] = 'Q';
      nQueen(board, r + 1, count);
      board[r][i] = '-';
    }
  }
}
int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  if (k == 0 || k == n) {
    return 1;
  }
  return C(n - 1, k - 1) + C(n - 1, k);
}
int main() {
  char board[N][N];
  int q, r = 0;
  std::cin >> q >> r;
  if (q == 0) {
    int count = 0;
    nRook(board, 0, & count);
    printf("%d", C(N, r) * C(N, r) * count);
  }
  if (r == 0) {
    int count = 0;
    nQueen(board, 0, & count);
    printf("%d", C(N, q) * C(N, q) * count);
  } else {

  }
  return 0;
}
