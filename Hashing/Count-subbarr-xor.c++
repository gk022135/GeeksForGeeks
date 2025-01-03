//Count Subarrays with given XOR

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:
       long subarrayXor(vector<int> &arr, int k) {
          int cnt = 0;
          int cumilativeXor = 0;
          unordered_map<int, int>preXors;

          for(int i =0; i<arr.size(); i++){
             cumilativeXor = cumilativeXor ^ arr[i];

             if(cumilativeXor == k) cnt++;

             int preXorrr = cumilativeXor ^ k;

             if(preXors.find(preXorrr) != preXors.end()){
                cnt = cnt + preXors[preXorrr];
             }

             preXors[cumilativeXor]++;
          }
          return cnt;
       }
};

int main(){
    Solution obj;

    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 5;

    cout<<"SubArrays whose xor is equal to "<<k<<" is "<<obj.subarrayXor(arr,k)<<endl;

    return 0;
}