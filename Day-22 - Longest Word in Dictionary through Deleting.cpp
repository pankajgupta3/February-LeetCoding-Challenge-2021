/*
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

Example 2:
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"

Constraints:
1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.
*/

class Solution {
public:
    bool isSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        int j = 0;
        for(int i = 0; i < m && j < n; i++) {
            if(a[j] == b[i]){
                j++;
            }
        }
        return(j == n);
    }
    string findLongestWord(string s, vector<string>& d) {
       string res = "";
        sort(d.begin(), d.end());
        for(int i = 0; i < d.size(); i++){
            if(res.size() < d[i].size() && isSubsequence(d[i], s)){
                res = d[i];
            }
        }
        return res;
    }
};