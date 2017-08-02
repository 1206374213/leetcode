/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool comp(const Interval & t1,const Interval & t2)
    {
        return t1.start<t2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int length=intervals.size();
        if(length<=0)
            return res;
        sort(intervals.begin(),intervals.end(),[](Interval t1,Interval t2){return t1.start<t2.start;});
        res.push_back(intervals[0]);
        for (int i=1;i<length;i++)
        {
            if(intervals[i].start<=res.back().end)
                res.back().end=res.back().end>intervals[i].end?res.back().end:intervals[i].end;
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};