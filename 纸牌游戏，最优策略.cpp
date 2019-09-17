/*牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。*/

/*最优策略即纸牌从大到小排列，两个人依次抽取，（sort函数是从小到大排列），用布尔类型0 1 确定谁抽纸牌*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long n;
    scanf("%ld",&n);
    long a[n];
    for(int i = 0; i < n; i++){
        scanf("%ld",&a[i]);
    }
    sort(a,a+n); //从小到大
    long rest = 0;
    int flag = 1;
    for(int j = n - 1; j>=0; j--){
        if(flag){
            rest += a[j];
            flag = 0;
        }else{
            rest -= a[j];
            flag = 1;
        }
    }
    printf("%ld",rest);
}