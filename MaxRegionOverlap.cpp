#include "stdafx.h"

//http://blog.csdn.net/julianxiong/article/details/7338323
//1. ��һά����������n������Σ����غ����������������Ρ���������Դ��v_JULY_v�Ĳ��ͣ�http://blog.csdn.net/v_july_v/article/details/6803368��
//
//��һ���֣�˼·
//
//1. ��N��������������Ĺ���Ϊ���Ȱ�����Ŀ�ʼ���С�����ţ�����ʼ����ͬ�����ٰ���������
//
//���磺��������[1, 3], [2, 3], [1, 4]�����Ľ���ǣ�[1, 3], [1, 4], [2, 3]
//
//2. ���÷ֶ���֮�Ĳ��ԣ���N�������Ϊ2��N / 2�������⣬��N��������غ��������2������Σ���������3���е�һ����
//
//1����ǰN / 2���������غ��������
//
//2���Ǻ�N / 2���������غ��������
//
//3����ǰN / 2�������н������������䣬���N / 2���������غ��������
//
//����еݹ�ʽ��T(n) = 2 * T(n / 2) + O(n)

struct Segment
{
	int start, end;
};

int overlap(vector<Segment> const &sets)
{
	if (sets.empty())
		return 0;

	assert(sets.size() == 2);
	return min(sets[0].end, sets[1].end) - max(sets[0].start, sets[1].start);
}

//vector<Segment> maxOverlap(vector<Segment> const &sets)
//{
//	if (sets.size()<2)
//		return 0;
//
//	vector<Segment> set(sets);
//	sort(set.begin(), set.end(), [](Segment const &l, Segment const &r){
//		if (l.start < r.start)
//			return true;
//
//		if (l.start > r.start)
//			return false;
//
//		return l.end < r.end;
//	});
//
//	if (set.size() == 2)
//		return move(set);
//
//	vector<Segment> sl(set.begin(), set.begin() + set.size() / 2);
//	vector<Segment> sr(set.begin() + set.size() / 2, set.end());
//	vector<Segment> overL = maxOverlap(sl);
//	vector<Segment> overR = maxOverlap(sr);
//	int over
//}