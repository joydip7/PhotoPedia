class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string result="";
        string ans="";
        for(string s:word1){
            result+=s;
        }
        for(string s:word2){
            ans+=s;
        }
        if(result==ans) return true;
        else return false;
    }
};