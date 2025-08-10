class Solution {
    private int makeSignature(int n) {
        if (n == 0) return 0;
        
        int leading = n / 10;
        int remaining = n % 10;
        
        return (int) (makeSignature(leading) + Math.pow(10, remaining));
    }
    
    public boolean reorderedPowerOf2(int n) {
        int signature = makeSignature(n);
        
        for (int i = 0; i < 32; i++) {
            if (makeSignature(1 << i) == signature) return true;
        }
        
        return false;
    }
}