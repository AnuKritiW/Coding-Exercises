class Solution {
public:
    
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        std::map<int, vector<int>> students;
        vector<vector<int>> result;
        
        for(auto &item:items) {
            int student_id = item[0];
            int student_score = item[1];
            
            //if student already exists in map
            if (students.find(student_id) != students.end()) {
                students[student_id].push_back(student_score);
            } else {
                students[student_id] = vector<int>(1, student_score);
            }
        }
        
        for (auto it = students.begin(); it != students.end(); it++) {
            int student_id = it->first;
            vector<int> student_scores = it->second;
            
            sort(student_scores.begin(), student_scores.end(), greater<int>());
            
            int sum = 0;
            
            for (int i = 0; i < 5; i++) {
               sum += student_scores[i];
            }
                        
            vector<int> stdt{student_id, sum/5};
            
            result.push_back(stdt);
            
        }
        
        return result;
    }
};