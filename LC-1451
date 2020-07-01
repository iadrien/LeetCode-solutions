class Solution {
public:
    string arrangeWords(string text) {
        /*
        
        LC-1451: rearrange-words-in-a-sentence
        LC link: https://leetcode.com/problems/rearrange-words-in-a-sentence/
        Difficulty: medium
        
        Read each word and save it to map by the word length, reserving original
        relative order for words of same length. 
        
        space: O(n) 
        complexity: O(n)
        */
        map<int, string> segments;
        
        text[0]+=32;
        stringstream ss(text); 
        
        string word;
        
        while(ss>>word){
            segments[word.size()]+= " "+word;
        }
        
        for(auto itr=segments.begin();itr!=segments.end();itr++){
            if(itr==segments.begin()){
                text = (itr->second).substr(1);
                
                text[0]-=32;
                
            }else{
                text += itr->second;
            }
        }
        
        return text;
    }
};
