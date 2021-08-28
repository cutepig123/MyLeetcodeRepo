#include "stdafx.h"


class Solution {
	set<char>	sVowel;

	bool isVowel(char c)
	{
		return sVowel.find(c) != sVowel.end();
	}
	char *findVowel(char *p)
	{
		while (*p && !isVowel(*p))
			p++;
		return p;
	}
	char *findVowelReverse(char *p, const char *begin)
	{
		while (p>=begin && !isVowel(*p))
			p--;
		return p;
	}
public:
	Solution()
		:sVowel({ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' })
	{}

	string reverseVowels(string s) {
		string d(s);
		char *p, *p1 =p = const_cast<char*>(d.c_str());
		char *p2 = p1 + d.length() - 1;
		while (p1<p2)
		{
			p1 = findVowel(p1);
			p2 = findVowelReverse(p2, p);
			if (p1 < p2)
			{
				swap(*p1, *p2);
				p1++;
				p2--;
			}
		}
		return d;
	}
};

void Test1()
{
	Solution s;
	assert(s.reverseVowels("leetcode") == "leotcede");
}