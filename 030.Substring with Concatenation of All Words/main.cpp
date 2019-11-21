//
//  main.cpp
//  Substring with Concatenation of All Words
//
//  Created by liuzhao on 2019/11/21.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 1.把words所有单词存入map 2. 计算word长度，遍历s，切分，比较
        vector<int> ret;
        if (words.size() == 0 || s.length() == 0) {
            return ret;
        }
        int wordLen = (int)words[0].length();
        if (s.length() < wordLen * words.size()) {
            return ret;
        }
        map<string, int> sMap;
        for (string str : words) {
            sMap[str]++;
        }
        int maxIndex = (int)(s.size() - words.size() * wordLen) + 1;
        for (int i = 0; i < maxIndex; i++) {
            map<string, int> tempMap = sMap;
            int j = 0;
            for (; j < words.size(); j++) {
                int curIndex = i + j * wordLen;
                string str = s.substr(curIndex, wordLen);
                if (tempMap.find(str) != tempMap.end()) {
                    tempMap[str]--;
                    if (tempMap[str] == 0) {
                        tempMap.erase(str);
                    }
                } else {
                    break;
                }
            }
            if (j >= words.size()) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
//    string s = "barfoothefoobarman";
//    vector<string> words = {"foo","bar"};
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution so = Solution();
    vector<int> ret = so.findSubstring(s, words);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
