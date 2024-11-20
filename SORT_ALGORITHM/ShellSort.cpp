/*
 * 希尔排序
 * 思路：间隔分组+自定义排序（这里给出的是冒泡）
 * 特点：时间：O(nlogn)、非稳定排序
 * 适用：数据量大
 */

#include <bits/stdc++.h>
using namespace std;

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    // 从 n/2 开始的间隔序列
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个间隔进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int pos = i-gap;
            while(pos>=0&&arr[pos]>temp){
              arr[pos+gap] = arr[pos];
              pos-=gap;
            }
            arr[pos+gap] = temp;
        }
    }
}

int main() {
    std::vector<int> data = {9, 8, 3, 7,888, 5, 6, 4, 1,1010,88,-32,0,};
    shellSort(data);
    for(auto num : data) {
        std::cout << num << " ";
    }
    return 0;
}