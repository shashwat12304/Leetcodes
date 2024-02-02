// Ignore the case and just check if the s[i] and s[i-1] are different alphabets, if yes then increment ans...finally return ans.
class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length();
        int ans=0;
        for(int i =1;i<n;i++){
            if(s[i]==s[i-1]||s[i]==s[i-1]-32||s[i]==s[i-1]+32){
                continue;
            }else{
                ans++;
            }
        }
        return ans;
    }
};
