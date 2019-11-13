//
//  main.cpp
//  Text Justification
//
//  Created by liuzhao on 2019/11/13.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
//    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
   vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    Solution solution = Solution();
    vector<string> result = solution.fullJustify(words, maxWidth);
    for (auto s : result) {
        cout << s << endl;
    }

    return 0;
}
