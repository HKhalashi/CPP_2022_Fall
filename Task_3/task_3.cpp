#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int gcd(int, int);
int max(vector<int>);
int min(vector<int>);
void merge(int[], int, int, int);
void merge_sort(vector<int>, int, int);
vector<int> remove_repetitions(int[], int);

void task_1(int k) {
  int n[k];
  int m[k];
  int long long d;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> n[i] >> m[i];
    d = 19 * m[i] + (n[i] + 239) * (n[i] + 366) / 2;
    cout << d << endl;
  }
}

int task_2() {
  vector<int> a;
  string inp = "";
  getline(cin, inp);
  stringstream ss(inp);
  string sep_inp;
  while (!ss.eof()) {
    getline(ss, sep_inp, ' ');

    a.push_back(stoi(sep_inp));
  }

  int min_of_even = a[0];
  int max_of_odd = a[1];
  int size_of_a = a.size();
  for (unsigned i = 0; i < size_of_a; i += 2) {
    if (a[i] < min_of_even) min_of_even = a[i];
    if (i + 1 == size_of_a) break;
    if (a[i + 1] > max_of_odd) max_of_odd = a[i + 1];
  }
  return min_of_even + max_of_odd;
}

int task_3(int a, int b) { return a * b / gcd(a, b); }

vector<int> task_4(int k) {
  vector<int> a;
  string inp = "";
  cin.ignore(INT_MAX, '\n');
  getline(cin, inp);
  stringstream ss(inp);
  string sep_inp;
  while (!ss.eof()) {
    getline(ss, sep_inp, ' ');

    a.push_back(stoi(sep_inp));
  }
  int min_el = min(a);
  int max_el = max(a);

  for (unsigned i = 0; i < k; i++) {
    if (a[i] == max_el) a[i] = min_el;
  }
  return a;
}

void test_task_1(int k) { task_1(k); }

vector<int> task_5(int m, int n) {
  int a_1[m];
  int a_2[n];
  cin.ignore(INT_MAX, '\n');
  for (unsigned i = 0; i < m; i++) {
    cin >> a_1[i];
  }
  for (unsigned i = 0; i < n; i++) {
    cin >> a_2[i];
  }

  vector<int> new_a_1 = remove_repetitions(a_1, m);
  vector<int> new_a_2 = remove_repetitions(a_2, n);
  vector<int> result;
  for (unsigned i = 0; i < new_a_1.size(); i++) {
    for (unsigned j = 0; j < new_a_2.size(); j++) {
      if (new_a_1[i] == new_a_2[j]) result.push_back(new_a_1[i]);
    }
  }

  merge_sort(result, 0, result.size() - 1);
  return result;
}

void test_task_2() { cout << task_2() << endl; }

void test_task_3(int a, int b) { cout << task_3(a, b) << endl; }

void test_task_4() {
  int k;
  cin >> k;
  vector<int> a = task_4(k);
  for (unsigned i = 0; i < k; i++) {
    cout << a[i] << " ";
  }
}
void test_task_5() {
  int m;
  int n;
  cin >> m;
  cin >> n;
  vector<int> a = task_5(m, n);
  for (unsigned i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}

int gcd(int a, int b) {
  if (a * b == 0) return a + b;
  if (a < b)
    return gcd(a, b % a);
  else
    return gcd(a % b, b);
}

int max(vector<int> a) {
  int len = a.size();
  int max_el = a[0];
  for (unsigned i = 0; i < len; i++) {
    if (a[i] > max_el) max_el = a[i];
  }
  return max_el;
}

int min(vector<int> a) {
  int len = a.size();
  int min_el = a[0];
  for (unsigned i = 0; i < len; i++) {
    if (a[i] < min_el) min_el = a[i];
  }
  return min_el;
}

void merge(vector<int> a, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) L[i] = a[l + i];
  for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(vector<int> a, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = (l + r - 1) / 2;
  merge_sort(a, l, m);
  merge_sort(a, m + 1, r);
  merge(a, l, m, r);
}

vector<int> remove_repetitions(int a[], int n) {
  set<int> s;
  for (unsigned i = 0; i < n; i++) {
    s.insert(a[i]);
  }
  set<int>::iterator it;
  vector<int> result;
  for (it = s.begin(); it != s.end(); ++it) {
    result.push_back(*it);
  }
  return result;
}

int main() {
  test_task_1(4);
  test_task_2();
  test_task_3(39, 65);
  test_task_4();
  test_task_5();
}
