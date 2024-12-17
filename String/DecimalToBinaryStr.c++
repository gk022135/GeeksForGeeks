// given real number (0 to 1) you have to convert into binary string 

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    string DecToBinary(double num){
        string str = "0.";
        int cnt = 0;

        while(num != 0.0){
            num = num * 2;
            cnt++;
            if(cnt > 32) return "ERROR";
            
            if (num >= 1)
            {
               str = str + '1';
               num = num - 1;

            }
            else if (num < 1){
                str = str + '0';

            }
            
        }
        return str;
    }
};

int main(){
    Solution obj;
    double num;
    cout<<"enter the number which you want in binary: ";
    cin>> num;
    cout<< obj.DecToBinary(num)<<endl;

   return 0;

}