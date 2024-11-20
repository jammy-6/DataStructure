#include <bits/stdc++.h>
using namespace std;
/*
 * 快速排序
 * 思路：选择中轴元素，比它小的放左，比它大的放右（代码过程很像
 * 小丑在扔三个小球） 特点：时间：O(nlogn)、空间：O(logn)、非稳定
 * 适用：广泛（最快）
 */
int Partition(vector<int>& A,int low,int high);
void QuickSort(vector<int>& A,int low,int high){
    if(low<high){
        int pivotpos=Partition(A,low,high);//划分
        QuickSort(A,low,pivotpos-1);//依次对两个子表进行递归排序
        QuickSort(A,pivotpos+1,high);
    }
}

int Partition(vector<int>& A,int low,int high){ //一趟划分
    int pivot=A[low];//将当前表中第一个元素设为枢轴，对表进行划分
    while(low<high){ //循环跳出条件
        while(low<high&&A[high]>=pivot)--high;
        A[low]=A[high];//将比枢轴小的元素移动到左端
        while(low<high&&A[low]<=pivot)++low;
        A[high]=A[low];//将比枢轴大的元素移动到右端
    }
    A[low]=pivot; //枢轴元素存放到最终位置
    return low; //返回存放枢轴的最终位置
}

int
main()
{
  vector<int> nums = {9, 7, 5, 3,3,1, 1, 0, 8, 4, 6, 2, -2};
  QuickSort(nums, 0, nums.size() - 1);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}