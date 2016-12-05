#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
    vector<Interval> res;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }

    void addNum(int val)
    {
        if (res.empty()){
            res.push_back(Interval(val, val));
            return;
        }
        //大于等于当前要插入val的第一个区间
        auto cmp = [](Interval a, Interval b){return a.start < b.start; };
        auto it = lower_bound(res.begin(), res.end(), Interval(val, val), cmp);
        //当前插入值val，前面一个区间a，后面一个区间b
        auto a = it == res.begin() ? it : it - 1;
        auto b = it == res.end() ? it - 1 : it;

        if (a->start <= val && val <= a->end)
            return;
        if (b->start <= val && val <= b->end)
            return;

        if (a->end + 1 == val && val + 1 == b->start){
            a->end = b->end;
            res.erase(b);
            return;
        }
        if (a->end + 1 == val){
            a->end = val;
            return;
        }

        if (val + 1 == b->start){
            b->start = val;
            return;
        }

        res.insert(it, Interval(val, val));
    }

    vector<Interval> getIntervals()
    {
        return res;
    }
};

//int main()
//{
//    int val;
//    SummaryRanges obj;
//    while (cin >> val){
//        obj.addNum(val);
//        vector<Interval> param_2 = obj.getIntervals();
//    }
//}