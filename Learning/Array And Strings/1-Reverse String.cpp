class Solution {
public:
    void reverseString(vector<char>& s) {

        int leftPointer  = 0 ; 
        int rightPointer = s.size() - 1 ; 

        while(leftPointer < rightPointer)
        {
            int temp = s[rightPointer] ;
            s[rightPointer] = s[leftPointer];
            s[leftPointer] = temp;

            leftPointer++ ;
            rightPointer--;

        }
       
    }
};
