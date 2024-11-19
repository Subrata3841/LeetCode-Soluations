class Solution {
    private:
    int countSteps(int num, int step){
        if(num == 0){
            return step;
        }
        if(num%2 == 0){
            return countSteps(num/2, step+1);
        }
        return countSteps(num-1, step+1);
    }
public:
    int numberOfSteps(int num) {
        return countSteps(num, 0);
    }
};