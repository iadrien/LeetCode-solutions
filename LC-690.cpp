/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
    /*
    LC 690: Employee Importance
    LC link: https://leetcode.com/problems/employee-importance/
    LC difficulty: easy
    
    Tree with value, find a partful tree sum by deapth first  
    */
        unordered_map<int, Employee*> employeeMap;
        
        for(int i = 0; i< employees.size(); i++){
            employeeMap[employees[i]->id] = employees[i];
        }
        
        return getImportanceHelper(employeeMap, id);
    }
    
    int getImportanceHelper(unordered_map<int, Employee*> & employees, int id){
        int value = employees[id]->importance;
        
        for (int i =0; i<(employees[id]->subordinates).size(); i++){
            value = value + getImportanceHelper(employees, employees[id]->subordinates[i]);
        }
        
        return value;
    }
};
