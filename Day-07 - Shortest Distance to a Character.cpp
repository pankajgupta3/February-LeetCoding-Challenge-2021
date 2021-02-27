/*
Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]

Constraints:
1 <= s.length <= 104
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.
*/
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size(), pos = -n;
        vector<int> res(n, n);
        for(int i = 0; i < n; ++i){
            if (S[i] == C) pos = i;
            res[i] = i - pos;
        }
        for(int i = pos - 1; i >= 0; --i){
            if (S[i] == C)  pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
};


        
