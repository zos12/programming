/*
斐波那契数列 1 1 2 3 5 8 13....
*/
#include<iostream>
using namespace std;
class Solution{
public:
	int Fibonacci(int n){
		if(n == 0) return 0;
		if(n == 1 || n == 2){
			return 1;
		}else{
			return Fibonacci(n-1) + Fibonacci(n-2);
		}
	}
};
int main(){
	Solution s;
	cout << s.Fibonacci(3);
	return 0;
}