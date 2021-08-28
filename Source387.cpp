#include "stdafx.h"

class Solution {
	struct Item
	{
		int idxfirst;
		int n;

		Item()
		{
			idxfirst = -1;
			n = 0;
		}
	};
public:
	int firstUniqChar(string s) {
		map<char, Item> m;
		for (size_t i = 0, n=s.length(); i < n; i++)
		{
			auto & t = m[s[i]];
			t.n++;
			if (t.idxfirst < 0)
				t.idxfirst = i;
		}

		int idxfirst = -1;
		for (auto t:m)
		{
			if (t.second.n == 1)
			{
				if (idxfirst == -1 || t.second.idxfirst < idxfirst)
					idxfirst = t.second.idxfirst;
			}
		}
		return idxfirst;
	}
};

void test387()
{
	Solution s;
	assert(0 == s.firstUniqChar("leetcode"));
	assert(2 == s.firstUniqChar("loveleetcode"));
}