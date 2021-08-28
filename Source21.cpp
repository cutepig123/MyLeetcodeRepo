#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *build(vector<int> const &v)
{
	ListNode *h = 0;
	ListNode *t = 0;

	for (auto i:v)
	{
		if (!h) h = t = new ListNode(i);
		else
		{
			t->next = new ListNode(i);
			t = t->next;
		}
	}
	return h;
}

vector<int> toVec(ListNode*p)
{
	vector<int> v;
	for (; p;p=p->next)
	{
		v.push_back(p->val);
	}
	return move(v);
}

bool operator == (vector<int> const &l, vector<int> const &r)
{
	if (l.size()!=r.size())
	{
		return false;
	}
	for (size_t i = 0, n = l.size(); i < n; i++)
	{
		if (l[i] != r[i])
			return false;
	}
	return true;
}
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		if (!l1)return l2;
		if (!l2)return l1;

		ListNode *head = 0;
		ListNode *tail = 0;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
				swap(l1, l2);

			if (!head)head= tail = l1;
			else
			{
				tail->next = l1;
				tail = l1;
			}
			l1 = l1->next;
		}

		if (l2)
			swap(l1, l2);

		if (!head)head = tail = l1;
		else
		{
			tail->next = l1;
			tail = l1;
		}

		//tail->next = 0;
		return head;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* h = 0;
		for (size_t i = 0, n = lists.size(); i < n; i++)
		{
			h = mergeTwoLists(h, lists[i]);
		}
		return h;
	}

	bool isUgly(int num) {
		vector<int> v = { 2, 3, 5 };
		for (auto i:v)
		{
			while (num%i==0)
			{
				num /= i;
			}
		}
		return num == 1;
	}

	bool isHappy(int n) {
		while(n > 9 )
		{
			int sum = 0;
			
			for (int k = n; k; k = k / 10)
			{
				sum += (k % 10)*(k % 10);
			}
			n = sum;
		}
		return n==1;
	}

	int addDigits(int num) {
		int n = num;
		while (n > 9)
		{
			int sum = 0;

			for (int k = n; k; k = k / 10)
			{
				sum += (k % 10);
			}
			n = sum;
		}
		return n;
	}
};

void test21()
{
	Solution s;
	{
		ListNode* l1 = build(vector<int>{1, 2});
		ListNode* l2 = build(vector<int>{3, 4});
		assert(toVec(s.mergeTwoLists(l1, l2)) == (vector<int>{1, 2, 3, 4}));
	}

	{
		ListNode* l1 = build(vector<int>{1, 3});
		ListNode* l2 = build(vector<int>{2, 4});
		assert(toVec(s.mergeTwoLists(l1, l2)) == (vector<int>{1, 2, 3, 4}));
	}

	assert(s.isHappy(19));
	assert(!s.isHappy(2));
}