class Solution {
public:
    int result(int num){
        int sum = 0;
        int data = num;
        while(data>0){
            int temp = data % 10;
            sum += temp * temp;
            data /=10;
        }
        return sum;
    }
    bool isHappy(int n) {

        int slow = n;
        int fast = n;
        while(fast!=1){
            slow = result(slow);
            fast = result(fast);
            fast = result(fast);
            if(fast==slow and slow!=1){
                return false;
            }
        }
        return true;
    }
};