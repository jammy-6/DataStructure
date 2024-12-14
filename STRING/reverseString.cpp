#include <bits/stdc++.h>
using namespace std;

///"  hello world  "-> "world hello"
class Solution {
  public:
    void reverse(string &s, int start, int end) {
        while (end > start) {
            swap(s[end], s[start]);
            start++;
            end--;
        }
    }

    // 去除多余字符串（前后、中间）
    void removeExtraSpace(string &s) {
        int slow = 0, fast = 0;
        for (; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0)
                    s[slow++] = ' ';
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        return s.resize(slow);
    }
    // 翻转字符串
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);

        int slow = 0, fast = 0;
        while (fast <= s.size()) {
            if (fast == s.size() || s[fast] == ' ') {
                reverse(s, slow, fast - 1);
                slow = fast + 1;
            }
            fast++;
        }
        return s;
    }
};