/*
Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
       vector<vector<int>>mergeIntervals(vector<vector<int>>&intervals){
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        merged.push_back(intervals[0]);

        for(int i = 1;i<n;i++){
            if(merged.back()[1] >= intervals[i][0])
            {
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }

        }
        return merged;

       }

       vector<vector<int>>InsertIntoIntervals(vector<vector<int>>&intervals, vector<int>&inter){
        intervals.push_back(inter);
        return mergeIntervals(intervals);
       }

};

int main(){
    vector<vector<int>>intervals = {
        {1,2},{2,3},{4,7},{5,8},{9,12}
    };
    vector<int>inter = {4,7};
    
    Solution obj;
    obj.InsertIntoIntervals(intervals,inter);


    return 0;

}