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
	int removeDuplicates(vector<int>& nums) {
		map<int, Item> m;
		size_t j = 0;
		for (size_t i = 0, n = nums.size(); i < n; i++)
		{
			auto &t = m[nums[i]];
			if (t.n>=2)
			{
				continue;
			}
			else
			{
				nums[j] = nums[i];
				t.n++;
				j++;
			}
		}
		return j;
	}
};

void test80()
{
	Solution s;
	vector<int> vs{ 1, 1, 1, 2, 2, 3 };
	assert(5 == s.removeDuplicates(vs));
}