#include "stdafx.h"


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	/* Returns an integer in the range [0, n).
	*
	* Uses rand(), and so is affected-by/affects the same seed.
	*/
	int randint(int n) {
		if ((n - 1) == RAND_MAX) {
			return rand();
		}
		else {
			// Chop off all of the values that would cause skew...
			long end = RAND_MAX / n; // truncate skew
			assert(end > 0L);
			end *= n;

			// ... and ignore results from rand() that fall above that limit.
			// (Worst case the loop condition should succeed 50% of the time,
			// so we can expect to bail out of this loop pretty quickly.)
			int r;
			while ((r = rand()) >= end);

			return r % n;
		}
	}

	std::vector<int> mV;
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		for (; head; head=head->next)
		{
			mV.push_back(head->val);
		}
		//srand(time(NULL));
	}

	/** Returns a random node's value. */
	int getRandom() {
		int x = randint(mV.size());
		assert(x < mV.size());
		return mV.empty() ? 0 : mV[x];
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/
