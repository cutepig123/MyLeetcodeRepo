#include "stdafx.h"

class BigInt
{
	vector<int>	m_Num;

	void format()
	{
		for (int j = 0, m = m_Num.size(); j+1<m; j++)
		{
			m_Num[j + 1] += m_Num[ j] / 10;
			m_Num[ j] %= 10;
		}
	}
public:
	BigInt(){}

	explicit BigInt(const char *s)
	{
		for (int i=strlen(s)-1; i>=0; i--)
		{
			m_Num.push_back(s[i]-'0');
		}
	}

	string c_str() const{
		string res;

		int i = m_Num.size() - 1;
		for (; i >= 0 && m_Num[i]==0; i--)
		{
		}

		for (; i >= 0; i--)
		{
			res += m_Num[i] + '0';
		}
		if (res.empty())
			res += '0';
		return move(res);
	}

	

	BigInt mul(BigInt const &rhs) const
	{
		BigInt res;
		res.m_Num.resize(m_Num.size() + rhs.m_Num.size() + 2);

		for (int i = 0, n = m_Num.size(); i < n; i++)
		{
			for (int j = 0, m = m_Num.size(); j < m; j++)
			{
				res.m_Num[i + j] += m_Num[i] * rhs.m_Num[j];
			}
			res.format();
		}
		res.format();
		return move(res);
	}

	BigInt add(BigInt const &rhs) const
	{
		BigInt res;
		res.m_Num.resize(m_Num.size() + rhs.m_Num.size() + 2);

		copy(m_Num.begin(), m_Num.end(), res.m_Num.begin());

		for (int i = 0, n = rhs.m_Num.size(); i < n; i++)
		{
			res.m_Num[i] += rhs.m_Num[i];
		}
		res.format();
		return move(res);
	}
};

void testBigint()
{
	{
		BigInt bi = BigInt("12").mul(BigInt("34"));
		assert(bi.c_str() == "408");
	}

	{
		BigInt bi = BigInt("1234567891011121314151617181920").mul(BigInt("2019181716151413121110987654321"));
		assert(bi.c_str() == "2492816912877266687794240983772975935013386905490061131076320");
	}
}