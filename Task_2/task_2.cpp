#include <iostream>
#include <string>
using namespace std;

int ex_1(int v, int t)
{
	return (((v *t) % 109) + 109) % 109;
}

string ex_2(int n)
{
	n %= 86400;
	int hour = n / 3600;
	n %= 3600;
	int min = n / 60;
	n %= 60;
	int sec = n;
	return to_string(hour) + ":" + to_string(min / 10) + to_string(min % 10) + ":" + to_string(sec / 10) + to_string(sec % 10);
}

unsigned ex_3(unsigned h, unsigned a, unsigned b)
{
	int without_last_day = h - a;
	int remainder_of_whole_days = without_last_day % (a - b);
	int divisor_of_whole_days = without_last_day / (a - b);
	unsigned result = divisor_of_whole_days + ((h - divisor_of_whole_days *(a - b) + remainder_of_whole_days) / a) + (((h - divisor_of_whole_days *(a - b) + remainder_of_whole_days) % a) != 0);
	return result;
}

int ex_4(int a)
{
	int d_1 = a % 10;
	a /= 10;
	int d_2 = a % 10;
	a /= 10;
	int d_3 = a % 10;
	a /= 10;
	int d_4 = a % 10;
	return (d_1 == d_4) && (d_2 == d_3);
}

int ex_5(unsigned n, unsigned m)
{
	return !(n % m) || !(m % n);
}

int ex_6(int a, int b)
{
	return a ^ ((a ^ b) &-(a < b));
}

string ex_7(unsigned s_1, unsigned s_2, unsigned s_3)
{
	unsigned a = 0;
	unsigned b = 0;
	unsigned c = ex_6(ex_6(s_1, s_2), s_3);
	if (s_1 == c)
	{
		a = s_2;
		b = s_3;
	}
	else if (s_2 == c)
	{
		a = s_1;
		b = s_3;
	}
	else
	{
		a = s_1;
		b = s_2;
	}

	if ((a + b) > c)
	{
		if ((c *c) == ((a *a) + (b *b)))
		{
			return "right";
		}
		else if ((c *c) < ((a *a) + (b *b)))
		{
			return "acute";
		}
		else return "obtuse";
	}
	else
	{
		return "impossible";
	}
}

string ex_8(int a, int b, int c)
{
	if (((a % 2 == 0) || (b % 2 == 0) || (c % 2 == 0)) && ((a % 2 == 1) || (b % 2 == 1) || (c % 2 == 1))) return "YES";
	return "NO";
}

string ex_9(int n)
{
	string result = "";
	if (n == 100)
		result = "C";
	else
	{
		switch (n / 10)
		{
			case 1:
				result = "X";
				break;
			case 2:
				result = "XX";
				break;
			case 3:
				result = "XXX";
				break;
			case 4:
				result = "XL";
				break;
			case 5:
				result = "L";
				break;
			case 6:
				result = "LX";
				break;
			case 7:
				result = "LXX";
				break;
			case 8:
				result = "LXXX";
				break;
			case 9:
				result = "XC";
				break;
		}

		switch (n % 10)
		{
			case 1:
				result += "I";
				break;
			case 2:
				result += "II";
				break;
			case 3:
				result += "III";
				break;
			case 4:
				result += "IV";
				break;
			case 5:
				result += "V";
				break;
			case 6:
				result += "VI";
				break;
			case 7:
				result += "VII";
				break;
			case 8:
				result += "VIII";
				break;
			case 9:
				result += "IX";
				break;
		}
	}

	return result;
}

string ex_10(int n_1, int n_2, int n_3)
{
	int a = 0;
	int b = 0;
	int c = 0;
	if (n_1 <= n_2)
	{
		if (n_2 <= n_3)
		{
			a = n_1;
			b = n_2;
			c = n_3;
		}
		else
		{
			if (n_3 >= n_1)
			{
				a = n_1;
				b = n_3;
				c = n_2;
			}
			else
			{
				a = n_3;
				b = n_1;
				c = n_2;
			}
		}
	}
	else if (n_2 < n_1)
	{
		if (n_1 <= n_3)
		{
			a = n_2;
			b = n_1;
			c = n_3;
		}
		else
		{
			if (n_3 >= n_2)
			{
				a = n_2;
				b = n_3;
				c = n_1;
			}
			else
			{
				a = n_3;
				b = n_2;
				c = n_1;
			}
		}
	}

	return to_string(a) + " " + to_string(b) + " " + to_string(c);
}

void test_ex_1(int v, int t)
{
	cout << ex_1(v, t) << endl;
}

void test_ex_2(int n)
{
	cout << ex_2(n) << endl;
}

void test_ex_3(unsigned h, unsigned a, unsigned b)
{
	cout << ex_3(h, a, b) << endl;
}

void test_ex_4(int a)
{
	cout << ex_4(a) << endl;
}

void test_ex_5(unsigned n, unsigned m)
{
	cout << ex_5(n, m) << endl;
}

void test_ex_6(int a, int b)
{
	cout << ex_6(a, b) << endl;
}

void test_ex_7(unsigned s_1, unsigned s_2, unsigned s_3)
{
	cout << ex_7(s_1, s_2, s_3) << endl;
}

void test_ex_8(int a, int b, int c)
{
	cout << ex_8(a, b, c) << endl;
}

void test_ex_9(int n)
{
	cout << ex_9(n) << endl;
}

void test_ex_10(int n_1, int n_2, int n_3)
{
	cout << ex_10(n_1, n_2, n_3) << endl;
}

int main()
{
	test_ex_1(60, 2);
	test_ex_1(-1, 1);
	test_ex_2(3602);
	test_ex_2(129700);
	test_ex_3(10, 3, 2);
	test_ex_3(20, 7, 3);
	test_ex_4(2002);
	test_ex_4(2008);
	test_ex_4(111);
	test_ex_4(11);
	test_ex_4(0);
	test_ex_5(8, 2);
	test_ex_5(2, 8);
	test_ex_6(8, 5);
	test_ex_6(5, 8);
	test_ex_6(5, 5);
	test_ex_7(3, 4, 5);
	test_ex_7(4, 5, 10);
	test_ex_7(7, 8, 15);
	test_ex_7(8, 20, 4);
	test_ex_7(4, 5, 8);
	test_ex_7(7, 8, 10);
	test_ex_8(3, 4, 5);
	test_ex_8(7, 7, 7);
	test_ex_8(2, 2, 2);
	test_ex_8(7, 7, 4);
	test_ex_9(4);
	test_ex_9(19);
	test_ex_9(46);
	test_ex_10(1, 2, 2);
	test_ex_10(3, 7, 2);
	test_ex_10(1, 0, -5);
	test_ex_10(1, 1, 1);
	test_ex_10(9, 4, 2);
	test_ex_10(1, 2, 1);
	return 0;

}
