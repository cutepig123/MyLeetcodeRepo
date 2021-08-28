#include "stdafx.h"

//http://blog.csdn.net/julianxiong/article/details/7338323
//1. 在一维坐标轴上有n个区间段，求重合区间最长的两个区间段。【问题来源于v_JULY_v的博客：http://blog.csdn.net/v_july_v/article/details/6803368】
//
//第一部分：思路
//
//1. 对N个区间排序，排序的规则为：先按区间的开始点从小到大排，若开始点相同，则再按结束点排
//
//例如：对于区间[1, 3], [2, 3], [1, 4]排序后的结果是：[1, 3], [1, 4], [2, 3]
//
//2. 采用分而治之的策略，将N个区间分为2个N / 2的子问题，则N个区间的重合区间最长的2个区间段，比是以下3种中的一个：
//
//1）是前N / 2个区间中重合区间最长的
//
//2）是后N / 2个区间中重合区间最长的
//
//3）是前N / 2个区间中结束点最大的区间，与后N / 2个区间中重合最长的区间
//
//因此有递归式：T(n) = 2 * T(n / 2) + O(n)

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