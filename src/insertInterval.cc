/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool myCompare(Interval one, Interval two){
    return one.end < two.end;    
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<Interval> result;
        
        if(intervals.size() == 0){
            result.push_back(newInterval);
        } else{
            sort(intervals.begin(),intervals.end(),myCompare);
            
            if(newInterval.end < intervals[0].start){
                result.push_back(newInterval);
            }
            
            for(int i = 0; i < intervals.size(); i++){
                if(intervals[i].start <= newInterval.start and intervals[i].end <= newInterval.end and newInterval.start <= intervals[i].end){
                    intervals[i].end = newInterval.end;
                } else if(intervals[i].start >= newInterval.start and intervals[i].end >= newInterval.end and intervals[i].start <= newInterval.end){
                    intervals[i].start = newInterval.start;
                } else if(intervals[i].start >= newInterval.start and intervals[i].end <= newInterval.end){
                    intervals[i].start = newInterval.start; intervals[i].end = newInterval.end;
                }
                
                int s = result.size() - 1;
                
                if(s >= 0 and result[s].end >= intervals[i].start){
                    result[s].end = (result[s].end > intervals[i].end) ? result[s].end : intervals[i].end;
                } else{
                    if(s >= 0 and newInterval.start > result[s].end and newInterval.end < intervals[i].start){
                        result.push_back(newInterval);
                    }
                    
                    result.push_back(intervals[i]);
                }
            }
            
            int s = result.size() - 1;
            
            if(result[s].end < newInterval.start){
                result.push_back(newInterval);
            }
        }
        
        return result;
    }
};
