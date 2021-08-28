#include "stdafx.h"

struct List
{
	int v;
	List *next;
};

//方法4:   递归
List *reverse(List *h)
{
	if (!h || !h->next)
		return h;

	List *p1 = h->next;
	List *p = reverse(p1);
	p1->next = h;
	h->next = 0;

	return p;
}

//方法2：使用3个指针遍历单链表，逐个链接点进行反转。
List *reverse2(List *h)
{
	if (!h || !h->next)
		return h;

	List *a = h, *b = h->next, *c = b->next;
	a->next = 0;

	while (c)
	{
		b->next = a;
		a = b;
		b = c;
		c = c->next;
	}

	b->next = a;

	return b;
}

//方法3：从第2个节点到第N个节点，依次逐节点插入到第1个节点(head节点)之后，最后将第一个节点挪到新表的表尾。
List *reverse3(List *h)
{
	if (!h || !h->next)
		return h;

	List *b = h->next;
	if (!b->next)
	{
		b->next = h;
		h->next = 0;
		return b;
	}
	List *tail = 0;
	while (b && b->next)
	{
		if (!tail)
			tail = b;

		List *c = b->next;
		List *d = c->next;
		h->next = c;
		c->next = b;
		b->next = d;
	}

	tail->next = h;
	List *newh = h->next;
	h->next = 0;
	return newh;
}

vector<int> toVec(List *h)
{
	vector<int> v;
	while (h)
	{
		v.push_back(h->v);
		h = h->next;
	}
	return move(v);
}

List* toList(vector<int> const &v)
{
	List *h = 0, *t = 0;;
	for (auto i : v)
	{
		if (!h)
		{
			h = t = new List{ i, 0 };
		}
		else
		{
			List *p = (new List{ i, 0 });
			t->next = p;
			t = p;
		}
	}
	return h;
}
void testRevList(vector<int> const &v1)
{
	List *h = toList(v1);
	List *p = reverse3(h);
	vector<int> v2 = toVec(p);
	std::reverse(v2.begin(), v2.end());
	assert(v2.size() == v1.size());
	for (int i = 0; i < v2.size(); i++)
	{
		assert(v1[i] == v2[i]);
	}
}

static void test()
{
	testRevList(vector<int>{1, 0, 2});
	testRevList(vector<int>{1});
	testRevList(vector<int>{1, 0});
}