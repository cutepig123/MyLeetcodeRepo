#include "stdafx.h"

class Solution {
	double myPow2(double x, int n)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return x;

		double r = myPow2(x, n / 2);
		if (n % 2)
			r = r*r*x;
		else
			r = r*r;
		return r;
	}
public:
	double myPow(double x, int n) {
		if (n == 0)
		{
			return 1;
		}

		int sign = 1;
		if (n < 0) { sign = -1; n = -n; }

		double r = myPow2(x, n);

		
		if (sign > 0)
			return r;
		else
			return 1.0 / r;

	}

	int superPow(int a, int b)
	{
		if (b == 0)
			return 1;
		if (b==1)
		{
			return a % 1337;
		}
		int r = superPow(a, b / 2);

		if (b % 2)
			return (r*r*a) % 1337;
		else
			return (r*r) % 1337;
	}

	int superPow(int a, vector<int>& b) {
		if (b.empty())
		{
			return 1;
		}
		if (b.size()==1)
		{
			return superPow(a, b[0]);
		}

		int blast = b.back();
		b.pop_back();
		return (superPow(superPow(a, b), 10)*superPow(a, blast)) % 1337;
	}

	

	/*int integerBreak(int n) {
		if (n==2)
		{
			return 1;
		}

		if (n == 3)
		{
			return 2;
		}
		if (n == 4)
		{
			return 4;
		}
		if(x%3==1)
			return pow(3, x/3, 
	}
*/
	int maxArea(vector<int>& height) {
		int ma = 0;

		int s = 0;
		int e = height.size() - 1;
		while (s<e)
		{
			ma = max(ma, min(height[e], height[s])*(e - s));
			if (height[s]<height[e])
			{
				s++;
			}
			else
			{
				e--;
			}
		}
		return ma;
	}

	int *find_first_larger_than_or_max(int *s, int *e)
	{
		int *pmax = s+1;
		for (int *t = s+1; t < e; t++)
		{
			if (*t >= *s)
				return t;
			if (*pmax <= *t)
				pmax = t;
		}
		return pmax;
	}

	int area_special(int *s, int *e, int v)
	{
		int a = 0;
		for (int *t = s; t < e; t++)
		{
			
				
				a += min(v,*t);
			
		}
		return a;
	}
	int trap(vector<int>& height) {

		if (height.size() <= 1)
			return 0;

		int a = 0;
		int *s = &height[0];
		int *e = s + height.size();
		for (; s+1 < e;)
		{
			if (*s==0)
			{
				s++;
				continue;
			}
			int *it = find_first_larger_than_or_max(s, e);
			int total = (it  - s)*min((*s), *it);
			int emp = area_special(s, it, min((*s), *it));
			a += total - emp;
			s = it;
		}
		return a;
	}

	int romanToInt(string s) {
		int r = 0;
		for (int i = 0, n = s.length(); i < n; )
		{
			switch (s[i])
			{
			case 'I':
				if (i + 1 < n && s[i + 1] == 'V')
				{
					r += 4;
					i += 2;
				}
				else if (i + 1 < n && s[i + 1] == 'X')
				{
					r += 9;
					i += 2;
				}
				else
				{
					r++;
					i++;
				}
				break;
			case 'V':
				r += 5;
				i++;
				break;
			case 'X':
				if (i + 1 < n && s[i + 1] == 'L')
				{
					r += 40;
					i += 2;
				}
				else if (i + 1 < n && s[i + 1] == 'C')
				{
					r += 90;
					i += 2;
				}
				else
				{
					r+=10;
					i++;
				}
				break;
			case 'L':
				r += 50;
				i++;
				break;
			case 'C':
				if (i + 1 < n && s[i + 1] == 'D')
				{
					r += 400;
					i += 2;
				}
				else if (i + 1 < n && s[i + 1] == 'M')
				{
					r += 900;
					i += 2;
				}
				else
				{
					r += 100;
					i++;
				}
				break;
			case 'D':
				r += 500;
				i++;
				break;
			case 'M':
				r += 1000;
				i++;
				break;
			}
		}
		return r;
	}
};

void test50()
{
	Solution s;
#define TEST(a,b)	{double v=pow(a,b); printf("%f\n",v); assert(fabs(v - s.myPow(a, b)) < 0.001);}
	TEST(2, -1);
	TEST(0.00001, 2147483647);
	{
		vector<int> v{ 3 };
		assert(s.superPow(2, v) == 8);
	}

	{
		vector<int> v{ 1,0 };
		assert(s.superPow(2, v) == 1024);
	}
	{
		vector<int> v{ 2,0, 0 };
		assert(s.superPow(2147483647, v) == 1198);
	}

	assert(s.trap(vector<int>{1, 2}) == 0);
	assert(s.trap(vector<int>{1, 0, 2}) == 1);
	assert(s.trap(vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);

	assert(s.romanToInt("XLV") == 45);
	assert(s.romanToInt("XCIX") == 99);
	assert(s.romanToInt("VIII") == 8);
	assert(s.romanToInt("MCMXCVI") == 1996);
	
}