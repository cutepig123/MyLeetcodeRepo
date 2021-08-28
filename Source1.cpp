#include "stdafx.h"


class Solution {
	int findDuplicate(vector<int>& nums, int n1, int n2) {
		if (n1 + 1 == n2)
		{
			return n1;
		}

		int total=0;

		int n = (n1 + n2) / 2;
		assert(n != n1);

		for (auto i:nums)
		{
			if (i >= n1 && i < n)total++;
		}
		
		if (total == n - n1)
		{
			return findDuplicate(nums, n, n2);
		}
		else
		{
			return findDuplicate(nums, n1, n);
		}
	}
public:
	int findDuplicate(vector<int>& nums) {
		return findDuplicate(nums, 1, nums.size());
	}
};
void test1()
{
	Solution s;
	assert(s.findDuplicate(vector<int>({ 1, 1 })) == 1);
	assert(s.findDuplicate(vector<int>({ 1, 2, 1 })) == 1);
	assert(s.findDuplicate(vector<int>({ 1, 2,2,3,4 })) == 2);
	assert(s.findDuplicate(vector<int>({ 1, 2, 2, 2, 2 })) == 2);
	assert(s.findDuplicate(vector<int>({ 2, 2, 2, 2, 2 })) == 2);
}