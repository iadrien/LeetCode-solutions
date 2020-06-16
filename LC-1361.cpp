class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        /*
        Assumptions: 
        
        1. Any node can be the root, but there is only one root node 
        2. Root node is not children of any other node
        3. Root node must have at least one child unless n == 1
        
        Solotion:
        
        1. Iterate through all childrens, if the value is not -1, increment isChildren
        2. Iterate through isChildren
            I. if it is never a child, it can be root
                a. isolated and n!=1, it means connectivity check failed -> false
            II. if it is a child for more than once, it means there are multiple parent -> false 
        3. After the iterations, it checks that all nodes have been at most children node once
        4. If there is more than two root node, connectivity check failed -> false
        5. Otherwise, connectivity check + root node check passed -> true
        
        Space: O(n) for the isChildren vector
        Runtime: O(n) iterating through the vector of size n twice
        */
        vector<int> isChildren(n, 0);
        
        for(int i = 0; i<n; i++){
            if(leftChild[i]!=-1){
                isChildren[leftChild[i]]++;
            }
            
            if(rightChild[i]!=-1){
                isChildren[rightChild[i]]++;
            }
        }
        
        int numRoot = 0;
        
        for(int i =0; i<n; i++){
            if(isChildren[i]==0){
                numRoot++;
                
                if(leftChild[i]==-1 && rightChild[i]==-1 && n!=1){
                    return false;
                }
            }
            
            if(isChildren[i]>1 || numRoot>1){
                return false;
            }
        }
        
        if(numRoot==0){
            return false;
        }
        
        return true;
        
/*
Incomplete initial approach: DFS validate the tree
Problem: assumption that 0 is the root node
*/
//         vector<int> visited(n, 0);
        
//         depthFirstTraversal(0, leftChild, rightChild, visited);
        
//         for(int i = 0; i<visited.size(); i++){
//             if (visited[i] = -1){
//                 return false;
//             }
//         }
        
//         return true;
    }
    
    void depthFirstTraversal(int index, vector<int>& leftChild, vector<int>&rightChild, vector<int>&visited){
        visited[index] = 1;
        
        if(leftChild[index]==-1 && rightChild[index]==-1){
            return;
        }
        
        if(leftChild[index]!=-1){
            if(visited[leftChild[index]]!=0){
                visited[leftChild[index]]=-1;
            }else{
                depthFirstTraversal(leftChild[index], leftChild, rightChild, visited);
            }
        }
        
        if(rightChild[index]!=-1){
            if(visited[rightChild[index]!=0]){
                visited[rightChild[index]]=-1;
            }else{
                depthFirstTraversal(rightChild[index], leftChild, rightChild, visited);
            }
        }
        
        
        return;
        
    }
};
