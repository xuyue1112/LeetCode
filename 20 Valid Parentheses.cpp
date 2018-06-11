#include "vector"
#include "iostream"

using namespace std;

bool isValid(string s) {
    vector<char>  stack;
    char c;
    for(int i=0; i<s.length(); i++){
        c = s.at(i);
        if(c=='(' or c=='[' or c=='{')
            stack.push_back(c);
        else if(c==')'){
            if(stack.size() != 0 and stack.back() == '(')
                stack.pop_back();
            else
                return false;
        }
        else if(c==']'){
            
            if(stack.size() != 0 and stack.back() == '[')
                stack.pop_back();
            else
                return false;
        }
        else if(c=='}'){
            if(stack.size() != 0 and stack.back() == '{')
                stack.pop_back();
            else
                return false;
        }
        else
            return false;   
    }    
    if(stack.size()==0)
        return true;
    else
        return false;   
}
int main(){
    cout << isValid("}") << endl;
    getchar();
    return 0;
}