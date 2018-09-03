class Solution {
public:
    bool isValidSerialization(string preorder) {
        int index = -1;
        int node = 0;
        vector<pair<int,int>> nodes;
        node = getNextValue(preorder, index);
        if(node==-1)
            return true;
        if(node==-2  ){
            if(getNextValue(preorder, index)==-1)
                return true;
            else
                return false;
        }
        nodes.push_back(make_pair(node,0));
        // while(true){
        //     node = getNextValue(preorder, index);
        //     if(node==-1){
        //         break;
        //     }
        //     if(nodes.back().second<=1){
        //         nodes.back().second+=1;
        //         if(node != -2)
        //             nodes.push_back(make_pair(node,0));
        //     }
        //     while(nodes.back().second==2){
        //         nodes.pop_back();
        //     }
        // }
        while(!nodes.empty()){
            if(nodes.back().second<=1){
                node = getNextValue(preorder, index);
                if(node==-1)
                    return false;
                nodes.back().second+=1;
                if(node != -2)
                    nodes.push_back(make_pair(node,0));
            }
            else{
                nodes.pop_back();
            }
        }
        if (getNextValue(preorder, index) != -1)
            return false;
        return true;
        
    };
    int getNextValue(string &preorder, int &index){
        int indexNextComma = -1;
        int i=index+1;
        for(; i<preorder.size(); i++){
            if(preorder[i]==','){
                indexNextComma = i;
                break;
            }
        }
        if(indexNextComma==-1 && i>index+1) //走到了最后，找不到下一个逗号，但应该还有一个“#”
            indexNextComma = i;
        //cout << "###" << indexNextComma << "###" << endl;
        int length = indexNextComma - index - 1;
        index = indexNextComma;
        if(indexNextComma == -1) //后面没有节点了
            return -1; 
        if(preorder[indexNextComma-length]=='#'){
            index = indexNextComma;
            return -2;
        }
        return atoi(preorder.substr(indexNextComma-length, length).c_str());
    }
};