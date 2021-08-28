// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
	 int mn;
	 bool misInt;
	 vector<NestedInteger> mList;
   public:
     // Constructor initializes an empty nested list.
	   NestedInteger(){
		   mn  = 0;
		   misInt = false;
	   }

     // Constructor initializes a single integer.
	   NestedInteger(int value)
	   {
		   mn = value;
		   misInt = true;
	   }

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
	   bool isInteger() const
	   {
		   return misInt;
	   }

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
	   int getInteger() const
	   {
		   return mn;
	   }

     // Set this NestedInteger to hold a single integer.
	   void setInteger(int value)
	   {
		   misInt = true;
		   mn = value;
	   }

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
	   void add(const NestedInteger &ni)
	   {
		   misInt = false;
		   mList.push_back(ni);
	   }

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
	   const vector<NestedInteger> &getList() const
	   {
		   return mList;
	   }

	   string toString() const{
		   if (misInt)
		   {
			   char s[100];
			   sprintf(s, "%d", mn);
			   return s;
		   }

		   string s = "[";
		   bool isFirst = true;
		   for (auto i:mList)
		   {
			   string t = i.toString();
			   if (isFirst)
			   {
				   isFirst = false;
			   }
			   else
			   {
				   s += ",";
			   }
			   s += t;
		   }
		   s += "]";
		   return s;
	   }
 };

class Solution {
public:
	bool parseInt(const char *&ps, int *n)
	{
		bool isNeg = false;
		int val = 0;
		if (!(*ps == '-' || (*ps >= '0' && *ps <= '9')))
			return false;
		if (*ps == '-')
		{
			isNeg = true;
			ps++;
		}
		while (*ps>='0' && *ps<='9')
		{
			val = val * 10 + (*ps - '0');
			ps++;
		}

		*n= (isNeg ? -1 : 1)*val;
		return true;
	}

	struct Item
	{
		NestedInteger	n;
		char c;
		enum {
			IsInt,
			IsOp
		}type;

		explicit Item(NestedInteger const &i)
		{
			n = i;
			type = IsInt;
		}

		explicit Item(char const &i)
		{
			c = i;
			type = IsOp;
		}

	};

	NestedInteger deserialize(string s) {
		const char *ps = s.c_str();
		int nLevel=0;
		stack<Item>	stk;
		while (true)
		{
			switch (*ps)
			{
			case 0:
				goto ExitWhile;
				break;
			case '[':
				stk.push(Item(*ps));
				nLevel++;
				ps++;
				break;
			case ',':
				ps++;
				break;
			case ']':
			{
				
				deque<NestedInteger> vni;
				while (!stk.empty() && stk.top().type == Item::IsInt)
				{
					vni.push_front (stk.top().n);
					stk.pop();
				}
				if (!stk.empty())
				{
					assert(stk.top().type == Item::IsOp);
					assert(stk.top().c == '[');
					stk.pop();
				}

				NestedInteger ni;
				for (auto i : vni)
					ni.add(i);

				stk.push(Item(ni));

				ps++;
			}
				break;
			default:
				if (*ps == '-' || (*ps >= '0' && *ps <= '9'))
				{
					int n = 0;
					parseInt(ps, &n);
					NestedInteger ni(n);
					stk.push(Item(ni));
				}
				break;
			}
		
		}
	ExitWhile:
		;
		if (!stk.empty())
		{
			assert(stk.size() == 1);
			assert(stk.top().type == Item::IsInt);
			return stk.top().n;
		}
		else
		{ 
			NestedInteger ni;
			return ni;
		}
	}
};

void test()
{
	Solution s;

	char*p = "[-1,-2]";
	assert(s.deserialize(p).toString() == p);

	p = "[]";
	assert(s.deserialize(p).toString() == p);

	p = "[[]]";
	assert(s.deserialize(p).toString() == p);

	p = "[123,456,[788,799,833],[[]],10,[]]";
	assert(s.deserialize(p).toString() == p);
}

void Test1();
void test1();
void test387();
void test388();
void test80();
void test75();
void test21();
void test50();
void testBigint();

int main(int argc, char* argv[])
{

	test50();
	
	return 0;
}

class Task
{

};

class TaskMgr
{
public:
	TaskMgr();
	~TaskMgr();

	template <class T>
	void addTask(T* t, ...)
	{
		va_list l;
		va_start(l, t);
		while (T* p = va_arg(l, Task*))
		{
			m_tasks[p]->push_back(t);
		}
		va_end(l);
	}

	void run()
	{

	}
private:
	
	std::map<Task*, std::list<Task*> >	m_tasks;	// Task --> Tasks that depends on this task
};



int mainX(int argc, char* argv[])
{
	return 0;
}