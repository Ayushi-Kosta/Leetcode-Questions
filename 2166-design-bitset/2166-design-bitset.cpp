class Bitset {
public:
    vector<int> v;
    int cnt = 0; //stores the number of 1 in vector
    bool fl = 0;
    Bitset(int size) {
        v.resize(size);
        cnt=0;
        fl=0;
    }
    
    void fix(int idx) {
        if(fl==false){ // 0 is stored as 0 and 1 as 1
            if(v[idx]==0){
                v[idx]=1;
                cnt++;
            }
        }
        else{ // 0 is stored as 1 and 1 as 0 as we didnt flipped the elements
            if(v[idx]==1){
                //it is actually 0, so we'll make it 0 so that it will be treated as 1 as fl                 is true
                v[idx]=0;
                cnt++;
            }
        }
    }
    
    void unfix(int idx) {
        if(fl==false){ // 0 is stored as 0 and 1 as 1
            if(v[idx]==1){
                v[idx]=0;
                cnt--;
            }
        }
        else{ // 0 is stored as 1 and 1 as 0 as we didnt flipped the elements
            if(v[idx]==0){
                //it is actually 1, so we'll make it 1 so that it will be treated as 0                    as fl is true
                v[idx]=1;
                cnt--;
            }
        }
    }
    
    void flip() {
        fl=!fl;
        cnt=v.size()-cnt;
    }
    
    bool all() {
        if(cnt==v.size()){
            return 1;
        }
        return 0;
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string ans="";
        if(fl==0){
            for(int i=0; i<v.size(); i++){
                if(v[i]==0){
                    ans+='0';
                }
                else{
                    ans+='1';
                }
            }
        }
        else{
            for(int i=0; i<v.size(); i++){
                if(v[i]==0){
                    ans+='1';
                }
                else{
                    ans+='0';
                }
            }
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */