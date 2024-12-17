

// 给定一个乱序整形数组,找出其中数字连续的最长序列,如果出现长度相同的情况,返回第一个即可。（编程题）

// 示例1: 输入:[0,15,7,13,16,17,2,4,5]输出:[15,16,17]
// 示例2: 输入︰[0,15,1,7,13,16,17,2,4,5]输出:[0,1,2]
//  示例3: 输入:[0,15,8,11,13,19,17,2,21,5] 输出:[0]
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> longestConsecutiveSequence(const std::vector<int> &nums) {
    if (nums.empty())
        return {};

    std::unordered_set<int> numSet(nums.begin(), nums.end());
    std::vector<int> longestSeq;
    int maxLength = 0;

    for (int num : nums) {
        if (numSet.find(num - 1) == numSet.end()) { // 找到一个序列的起点
            std::vector<int> currentSeq;
            int currentNum = num;

            while (numSet.find(currentNum) != numSet.end()) {
                currentSeq.push_back(currentNum);
                currentNum++;
            }

            if (currentSeq.size() > maxLength) {
                maxLength = currentSeq.size();
                longestSeq = currentSeq;
            }
        }
    }

    return longestSeq;
}

int main() {
    std::vector<int> nums1 = {0, 15, 7, 13, 16, 17, 2, 4, 5};
    std::vector<int> nums2 = {0, 15, 1, 7, 13, 16, 17, 2, 4, 5};
    std::vector<int> nums3 = {0, 15, 8, 11, 13, 19, 17, 2, 21, 5};

    std::vector<int> result1 = longestConsecutiveSequence(nums1);
    std::vector<int> result2 = longestConsecutiveSequence(nums2);
    std::vector<int> result3 = longestConsecutiveSequence(nums3);

    std::cout << "示例1: ";
    for (int num : result1)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "示例2: ";
    for (int num : result2)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "示例3: ";
    for (int num : result3)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}