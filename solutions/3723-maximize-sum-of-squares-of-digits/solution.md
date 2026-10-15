**S**




C++:

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum){
            return "";
        }
        string ans = "";
        for(int i= 0; i< num; i++){
            if(sum >= 9){
                ans += "9";
                sum -=9;
            }else{
                ans += '0' + sum;
                sum = 0;
            }
        }
        return ans;
    }
};




Python:

class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        
        if 9*num < sum:
            return ""
        
        ans = ""
        for i in range(num):
            if sum >= 9:
                ans += "9"
                sum -=9
            else:
                ans += str(sum)
                sum = 0; 
        return ans
        