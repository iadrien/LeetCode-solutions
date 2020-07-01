class Solution {
public:
    vector<string> simplifiedFractions(int n) {
    
    /*
        LC 1447: simplified-fractions
        LC link: https://leetcode.com/problems/simplified-fractions
        LC difficulty: Medium
        
        Starting from the smallest, if there greatest common divisor is more than 1
        Then they can be simplified and hence have appeared, otherwise add to output
        
        Space: O(n^2) for the output
        Runtime: O(n^2) n loop of n loop
        */
        
        vector<string> output;
        
        for(int i =1; i<n+1; i++){
            simplifiedFraction(i, output);
        }
        
        return output;
    }
    
    void simplifiedFraction(int n, vector<string>& output){
        for(int i = 1; i<n; i++){
            if(gcd(i,n)==1){
                output.push_back(to_string(i)+"/"+to_string(n));
            }
        }
    }
};
