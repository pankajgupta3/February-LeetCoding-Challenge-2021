/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int n = s.length();
        unordered_map<char, int> counts;
        for(int i = 0; i < n; i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto count : counts){
            if(count.second){
                return false;
            } 
        }
        return true;
    }
};