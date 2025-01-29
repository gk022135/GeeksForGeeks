// finding power of number whithout using power function
// let's implement it 
/*
<---------------------------------------------------------------------->
<---- intution ------>
as we find power of  given numer by mutlitply number by itself up to the power size
but here is  we use recursion
and property of power like a^x = a^m * a^n = a^(m+n) 
so if power(x) is even then x = (m + m) = a^(x/2) * a ^(x/2)
in case of odd power(x) x = (m + m) + 1, i.e a ^ (x) = a*a^(x/2)*a(x/2) = a ^ (1+x/2 + x/2)
so by this  our iteration became half
<------------------->
<------ Approach --->
1.handle base case if(pow became 1) then return 1;
2.handle if power became -ve then make 1/a^(-e) then make power +ve when it go to denumerator
3.find number to power upto half of power by recursion
4.make codnition for power is even then return half*half
5 make condition if power is odd then return num * half * half
<------------------->


<---------------------------------------------------------------------->
*/
#include<iostream>
#include<vector>

using namespace std;

class Pow_to_num{
    public: 
       double Power_TO_Number(double b, int e){
        if(e == 0){
            return 1;
        }
        if(e < 0) return 1/Power_TO_Number(b,-e);

        double half = Power_TO_Number(b, e/2); // recursion

        if(e%2 == 0){
            return half*half;
        }
        else return b*half*half;

       }
       double PowOfNum(double b, int e){
        return Power_TO_Number(b,e);
       }
};

int main(){
    double num = 4.00000;
    int e = -1; // e = 10001

    Pow_to_num obj;
    cout<<"Your answer is:- "<<obj.PowOfNum(num,e);

    return 0;
}