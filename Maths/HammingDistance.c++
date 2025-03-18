//hamming distance is number of different bits in given two numbers
/*
x= 1 and y = 4,
x = 0001;
y = 0100;
haming distance = 2 because there are bits number who are different to each other
*/

#include<iostream>
#include<math.h>

using namespace std;

class HammingDistance
{
public:
    int hamDistance (int x, int y){
        int temp = x ^ y;
        int cnt = 0;

        while(temp != 0){
            if(temp % 2 != 0){
                cnt++;
            }
            temp = temp >> 1;
        }
        return cnt;

    }
};

int main(){
    HammingDistance obj;
    int x;
    int y;
    cout<<"enter the value of x and y:- ";

    cin>>x>>y;
    cout<<"hamming distance for "<<x<<" and "<<y<<" is "<<obj.hamDistance(x,y);
    return 0;
}