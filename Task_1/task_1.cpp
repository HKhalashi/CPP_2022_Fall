#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isPalindrome(int x)
{
	if (x < 0) return false;
	vector<int> x_digits;
	while (x >= 1)
	{
		x_digits.push_back(x % 10);
		x = x / 10;
	}

	vector<int> x_digits_original = x_digits;
	reverse(x_digits.begin(), x_digits.end());
	if (x_digits_original == x_digits) return true;
	else return false;

}

int romanToInt(string s)
{
	unordered_map<char, int> roman_nums_collection;
	roman_nums_collection['I'] = 1;
	roman_nums_collection['V'] = 5;
	roman_nums_collection['X'] = 10;
	roman_nums_collection['L'] = 50;
	roman_nums_collection['C'] = 100;
	roman_nums_collection['D'] = 500;
	roman_nums_collection['M'] = 1000;
	unordered_map<string, int> unusual_cases;
	unusual_cases["IV"] = 4;
	unusual_cases["IX"] = 9;
	unusual_cases["XL"] = 40;
	unusual_cases["XC"] = 90;
	unusual_cases["CD"] = 400;
	unusual_cases["CM"] = 900;
	int equivalent_int = 0;
	unsigned n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			if (roman_nums_collection[s[i]] >= roman_nums_collection[s[i + 1]])
			{
				equivalent_int += roman_nums_collection[s[i]];
			}
			else
			{
				equivalent_int += unusual_cases[s.substr(i, 2)];
				i++;
			}
		}
		else if (i == n - 1)
		{
			equivalent_int += roman_nums_collection[s[i]];
		}
	}

	return equivalent_int;
}

string longestCommonPrefix(vector<string> strs)
{
	unsigned len = strs.size();
	string common_prefix;
	bool red_flag = false;
	unsigned j = 0;
	while (!red_flag)
	{
		for (unsigned i = 1; i < len; i++)
		{
			if (strs[0][j] != strs[i][j])
			{
				red_flag = true;
			}
		}

		if (!red_flag) common_prefix += strs[0][j];
		j++;
	}

	return common_prefix;

}

bool isValid(string s)
{
	unordered_map<char, char> brackets;
	brackets['('] = ')';
	brackets['['] = ']';
	brackets['{'] = '}';
	unsigned len = s.length();
	bool red_flag = false;
	for (unsigned i = 0; i < len; i += 2)
	{
		if (brackets[s[i]] != s[i + 1])
		{
			red_flag = true;
			break;
		}
	}

	return !red_flag;
}

void test_isPalindrome(int x)
{
	cout << "your result is : " << isPalindrome(x) << endl;
}

void test_romanToInt(string s)
{
	cout << "your result is : " << romanToInt(s) << endl;

}

void test_longestCommonPrefix(vector<string> strs)
{
	cout << "your result is : " << longestCommonPrefix(strs) << endl;
}

void test_isValid(string s)
{
	cout << "your result is : " << isValid(s) << endl;
}

int main()
{
	cout << "task_1" << endl;
	test_isPalindrome(121);
	test_isPalindrome(-121);
	test_isPalindrome(9000);
	cout << "task_2" << endl;
	test_romanToInt("III");
	test_romanToInt("LVIII");
	test_romanToInt("MCMXCIV");
	cout << "task_3" << endl;
	test_longestCommonPrefix({ "flower", "flow", "flight" });
	test_longestCommonPrefix({ "dog", "racecar", "car" });
	cout << "task_4" << endl;
	test_isValid("()");
	test_isValid("()[]{}");
	test_isValid("(]");

	return 0;
}
