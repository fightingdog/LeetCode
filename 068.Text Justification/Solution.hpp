//
//  Solution.hpp
//  Text Justification
//
//  Created by liuzhao on 2019/11/13.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        bool change = true; // 是否换行的标志位
        size_t curLen = 0;
        int curLineCount = 0;
        for (int i = 0; i < words.size(); i++) {
            size_t size = words[i].size();
            if (change) {
                curLen = size;
                curLineCount++;
                change = false;
            } else {
                curLen += size;
                curLineCount++;
            }
            if (curLen > maxWidth) {
                // 拼接字符串
                curLineCount--;
                curLen = curLen - size - 1;
                size_t gap = maxWidth - curLen;
                
                if (curLineCount > 1) {
                    // 空格要尽量平均到前面几个单词之间，并不是全部加在第一个和第二个之间
                    int firstExtraSpace = gap % (curLineCount - 1);
                    int extraSpace = (int)gap / (curLineCount - 1);
                    
                    string s;
                    int extraSpaceIndex = 0;
                    for (int j = 0; j < curLineCount - 1; j++) {
                        s += words[i- curLineCount + j];
                        int spaceCount = extraSpaceIndex < firstExtraSpace ? (1 + extraSpace + 1) : (1 + extraSpace);
                        extraSpaceIndex++;
                        s.append(spaceCount, ' ');
                    }
                    s += words[i - 1];
                    result.push_back(s);
                } else {
                    // 考虑某行只有一个单词的情况
                    string s = words[i - 1];
                    s.append(gap, ' ');
                    result.push_back(s);
                }
                
                // 重置状态
                i--;
                change = true;
                curLineCount = 0;
                curLen = 0;
            } else {
                // 添加空格
                curLen++;
            }
        }
        // 拼接最后一行，也要补齐到maxWidth
        string s;
        for (int j = 0; j < curLineCount; j++) {
            s += words[words.size() - curLineCount + j];
            if (j != curLineCount - 1) {
                s += " ";
            }
        }
        int gap = maxWidth - (int)s.length();
        s.append(gap, ' ');
        result.push_back(s);
        return result;
    }
};

#endif /* Solution_hpp */
