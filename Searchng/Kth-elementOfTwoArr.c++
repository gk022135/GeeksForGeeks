/*
given two sorted array a[] and b[] an element k the task is to find the elemenet , at kth position of the combined sorted array
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{

    public:
    int kthElement(vector<int> &a, vector<int>& b,int k){
        int i =0;
        int j = 0;

        vector<int> res;

        while(i<a.size() || j<b.size()){
            if(a[i]<b[j]){
                res.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j]){
                res.push_back(b[j]);
                j++;
            }
            else{
                res.push_back(a[i]);
                res.push_back(b[j]);
                i++;
                j++;
            }
        }
        for(int i: res) cout<<i<<" ";
        cout<<endl;
        return res[k-1];
    }
   
};
int main(){
    vector<int> a = {1,4,5,7,9};
    vector<int> b = {2,3,6,8,};

    Solution obj;
    cout<<obj.kthElement(a,b,6)<<endl;
}

//method 02;