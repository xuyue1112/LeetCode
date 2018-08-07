class Solution {
public:
    unordered_map<int, string> teleKey = {{2,"abc"},
                                          {3,"def"},
                                          {4,"ghi"},
                                          {5,"jkl"},
                                          {6,"mno"},
                                          {7,"pqrs"},
                                          {8,"tuv"},
                                          {9,"wxyz"}
                                         };
    vector<string> letterCombinations(string digits) {
        vector<string> tmpResult;
        if(digits.size() == 0)
            return tmpResult;
        
        for(int i=0; i<digits.size(); i++){
            tmpResult = Recursion(digits[i] - '0', tmpResult);
        }
        return tmpResult;
    };
    vector<string> Recursion(int figure, vector<string> tmpResult){
        vector<string> tmpResult2;
        if(tmpResult.size() ==0){
            for(int j=0; j<teleKey[figure].size(); j++){
                stringstream tmp_strstream;
                tmp_strstream << teleKey[figure][j];
                string tmp_str;
                tmp_strstream >> tmp_str;
                tmpResult2.push_back(tmp_str);
            }
        }
        for(int i=0; i<tmpResult.size(); i++){
            for(int j=0; j<teleKey[figure].size(); j++){
                tmpResult2.push_back(tmpResult[i]+teleKey[figure][j]);
            }
        }
        return tmpResult2;
    };
};