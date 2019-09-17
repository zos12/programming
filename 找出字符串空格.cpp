/*请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/

/*考虑结束符'\0'*/
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
void replaceSpace(char *str, int length){
	int i = length - 1;
	for(i; i >=0; i--){
		if(str[i] == ' '){
			for(int j = length ; j >= i; j--){  //j = length即从'\0'结束符向右移动两个字符
				str[j + 2] = str[j];
			}
			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
			length += 2;
		}
	}
}
int main(){
	char str[N];
	gets(str);
	int length = strlen(str);
	replaceSpace(str,length);
	puts(str);
    return 0;
}