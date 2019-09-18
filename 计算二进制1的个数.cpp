/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
用 & 操作符
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int index = 1;
         int count = 0;
         while(index != 0){
            if((n & index) != 0){
                count++;
            }
             index = index << 1;
         }
         return count;
     }
};