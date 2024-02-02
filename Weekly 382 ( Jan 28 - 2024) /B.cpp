/*
This is typically a C level question. We need to return the maximum length of a subset from a given array nums which forms an odd palindrome (given pattern)
with each element's power is an even power of 2.
Here according to the constraints the max value of nums[i] is 1e9 so the length of such possible subset has an uppr limit.
For x==1 of cnt[x]%2==1 then return cnt[x] else return cnt[x] -1
for x>=2&&x*x<=1e9 we need to check for each such value of x three cases if cnt[x] ==0 break and ans-- else if cnt==1 ans+=1 break else ans+=2 and num = num*num
for x*x>1e9 we need to return 1
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int,int>mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        if(mp[1]%2==1){
            ans = mp[1];
        }else{
            ans = mp[1]-1;
        }
        for(int i =2;i*i<=1e9;i++){
            long long num = i;
            int cnt =0;
            while(num<=1e9){
                if(mp.find(num)==mp.end()){
                    cnt--;
                    break;
                }
                if(mp[num]>=2){
                    cnt+=2;
                    num *=num;
                }else{
                    cnt++;
                    break;
                }
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};
