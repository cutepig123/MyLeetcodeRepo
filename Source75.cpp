#include "stdafx.h"

class Solution {
	
public:
	void sortColors(vector<int>& nums) {
		int co[3] = { 0 };
		for (auto i: nums)
		{
			assert(i >= 0 && i < 3);
			co[i]++;
		}
		int k = 0;
		for (int i = 0; i < 3; i++)
		{
			std::fill(nums.begin() + k, nums.begin() + k + co[i], i);
			k += co[i];
		}
	}
};

void test75()
{
	Solution s;
	vector<int> vs{ 0};
	s.sortColors(vs);
	assert(vs[0] == 0);
}