/*小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力*/
#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int sum(int s){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += s;
		s = (s+1) / 2;
	}
	return sum;
}
int fun(){
	if (n == 1) return m;
	int low = 1;
	int high = m;
	while(low < high){
		int mid = low + (high-low+1) / 2 ;
		if(sum(mid) == m) return mid;
		else if(sum(mid) < m) {
			low = mid;
		}else{
			high = mid-1;
		}
	}
	return high;
}
int main(){
	scanf("%d%d",&n,&m);
	int res = fun();
	printf("%d",res);
	return 0;
}