/*
you have given arr of string you have to give all anagram string that are present in arr
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution{
    public:
    vector<vector<string>> allAnagrams(vector<string> &arr){

        vector<vector<string>> result;
        unordered_map<string, vector<string>>hash;

        for(string i : arr){
            string str = i;
            sort(str.begin(), str.end());

            hash[str].push_back(i);
        }

        for(auto i : hash){
            result.push_back(i.second);
        }
        return result;
    }
};

int main(){
    Solution obj;

    vector<string> arr = {"act","dog","god","cat","tac"};
    vector<vector<string>>res;

    res = obj.allAnagrams(arr);

    for(int i =0; i<res.size(); i++){
         for(int j =0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
         }
         cout<<endl;
    }
    return 0;
}