// 214_shortestPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void sss(string s)
{
	int len = s.size();
	vector<int> f(len, 0);
	for (int i = 1; i < len; i++) {
		int t = f[i - 1];
		while (t > 0 && s[i] != s[t])
			t = f[t - 1];
		if (s[i] == s[t])
			++t;
		f[i] = t;
	}
	for each (auto var in f)
	{
		cout << var << " ";
	}
	int i = 1;
	int t = 0;
	vector<int> next(len, 0);
	while (i < len)
	{
		if (s[i] == s[t])
		{
			next[i++] = ++t;
		}
		else if (t == 0)
		{
			i++;
		}
		else
		{
			t = next[t - 1];
		}
	}
	cout << endl;
	for each (auto var in next)
	{
		cout << var << " ";
	}
}


string shortestPalindrome(string s) {
	int len = s.size();
	if (len == 0)return s;
	string rev(s);
	reverse(rev.begin(), rev.end());
	string new_s = s + "#" + rev;
	int new_len = new_s.size();
	vector<int> next = vector<int>(new_len, 0);
	int t = 0;
	int i = 1;
	while(i<new_len)
	{
		if (new_s[i]==new_s[t])
		{
			next[i++] = ++t;
		}
		else if (t==0)
		{
			i++;
		}
		else
		{
			t = next[t - 1];
		}
	}
	return rev.substr(0, len - next[new_len - 1]) + s;
}
int main()
{
	 sss("ababbbabbaba");
    return 0;
}

