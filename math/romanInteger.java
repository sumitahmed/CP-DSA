// Go from right to left.
// If the current value is smaller than the previous value → subtract it,
// otherwise add it.

class Solution {
    public int romanToInt(String s) {
        int sum=0;
        int prev=0;
        int curr =0;
        for(int i=s.length()-1;i>=0;i--){
            char ch = s.charAt(i);
            if(ch == 'I') curr =1;
            if(ch == 'V') curr =5;
            if(ch == 'X') curr =10;
            if(ch == 'L') curr =50;
            if(ch == 'C') curr =100;
            if(ch == 'D') curr =500;
            if(ch == 'M') curr =1000;

            if(curr<prev)
            {
                sum-=curr;
            }
            else{
                sum+=curr;
            }

            prev = curr;
        }
        return sum;
        
    }
}