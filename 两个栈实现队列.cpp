#include<stack>
#include<iostream>
using namespace std;
class Solution
{
public:
   void push(int node){
    stack1.push(node);
   }
   int pop(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int result = stack2.top();
        stack2.pop();
        return result;
   }
private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(){
    Solution s;
    for(int i = 0; i < 10;i++)
    {
        s.push(i);
    }
    for(int i = 0; i < 10; i++){
    cout << s.pop() ;
    if(i != 9){
        cout<< ' ';
    }
}
    return 0;
}