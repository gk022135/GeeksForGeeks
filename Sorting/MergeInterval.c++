// u have given an 2-d vector which contain intervals arr[i] = [start_i,end_i]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class solution{
    public:
       vector<vector<int>>mergeInterval(vector<vector<int>> &interval){
        int n = interval.size();

        sort(interval.begin(),interval.end());

        vector<vector<int>>mergeInter;
        mergeInter.push_back(interval[0]);

        for(int i = 1;i<n;i++){
            if(mergeInter.back()[1] >= interval[i][0]){
                mergeInter.back()[1] = max(interval[i][1] , mergeInter.back()[1]);
            }
            else{
                mergeInter.push_back(interval[i]);

            }

        }
        return mergeInter;
       }


};

void printRes(vector<vector<int>>&res){
    int n = res.size();
    
    for(int i =0;i<n;i++){
        cout<<"{"<<res[i][0]<<","<<res[i][1]<<"}, ";
    }
}
int main(){
    vector<vector<int>>interval = { {1,3},{2,4},{4,8}};
    vector<vector<int>>res;
    solution obj;
    res = obj.mergeInterval(interval);

    printRes(res);
    return 0;



}