/*输入一个链表，按链表从尾到头的顺序返回一个ArrayList。*/
/*
链表有数据域和指针域

p -> val 返回结点p的数据
*/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
};
vector<int> v;
vector<int>  printListFromTailToHead(ListNode* head){
	ListNode* p = head;
	while(p != NULL){
		v.push_back(p -> val);
		p = p -> next;
	}
	return vector<int>(v.rbegin(),v.rend()); //反向迭代器 rbegin rend从尾输出到头
}
ListNode* create(int array[])
{
	ListNode* head = new ListNode;
    head -> next = NULL;
    ListNode* pre;
    pre = head;
    for(int i = 0; i < 5; i++){
   	ListNode* p = new ListNode;
   	p -> val = array[i];
   	p -> next = NULL;
   	pre -> next = p;
   	pre = p;
   }
   return head;
}
int main(){ 
   int array[5] = {1,2,3,4,5};
   ListNode* L = create(array);
   L = L -> next;
   printListFromTailToHead(L);
   for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
   	printf("%d ", *it);
   }
   return 0;
}