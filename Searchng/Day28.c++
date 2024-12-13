//problem:- Number of Occurence 
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class solution{
    public:
      int numberOccurence(vector<int> & arr, int target){
        unordered_map<int,int>hash;

        for(auto i : arr){
            hash[i]++;
        }
        return hash[target];

      }

};

int main(){
    vector<int>arr = {2,23,1,3,3,1,3,4,23,34,123};
    int target = 23;

    solution obj;
    cout<<"  "<<obj.numberOccurence(arr,target)<<endl;

}