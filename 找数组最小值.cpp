/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int length = rotateArray.size();
		int first = 0;
		int last = length - 1;
		while(first < last){
			int mid = first + (last - first) / 2;
			if(rotateArray[mid] > rotateArray[last]){
				first = mid + 1;
			}else if(rotateArray[mid] < rotateArray[last]){
				last = mid;
			}else{
				last = last - 1;
			}
		}
		return rotateArray[first];
	}
};
int main()
{
	Solution s;
	vector<int> a = {9,15,17,7,8};
	cout <<s.minNumberInRotateArray(a);
	return 0;
}