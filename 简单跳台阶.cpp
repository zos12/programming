/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
f(0) = 0
f(1) = 1
f(2) = f(2-1) + f(2-2) = 2
f(3) = f(3-1) + f(3-2) = 2 + 1 = 3
...
f(n) = f(n-1) + f(n-2)  
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1){
            return 1;
        }else if(number == 2){
            return 2;
        }else{
            return jumpFloor(number-1) + jumpFloor(number - 2);
        }
    }
};

/*一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
f(0) = 0
f(1) = 1
f(2) = f(2-1) + f(2-2) = 2
f(3) = f(3-1) + f(3-2) +f(3-3)= 2 + 1 + 1 = 4
...
f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-n) = 2*f(n-1)
*/ 
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0){
            return 0;
        }else if(number == 1){
            return 1;
        }else{
            return 2*jumpFloorII(number - 1);
        }
    }
};