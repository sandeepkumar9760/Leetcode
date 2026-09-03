class Solution {
public:
    int res(int n){
        int sum = 0;
        int num = n;
        while(num>0){
            int dig = num%10;
            sum += dig * dig;
            num /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast!=1){
            slow = res(slow);
            fast = res(fast);
            fast = res(fast);
            if(fast==slow && fast!=1 ) return false;
        }
        return true;
    }
};