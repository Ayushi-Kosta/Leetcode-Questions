// class MyHashSet {
// public:
//     MyHashSet() {
        
//     }
    
//     void add(int key) {
        
//     }
    
//     void remove(int key) {
        
//     }
    
//     bool contains(int key) {
        
//     }
// };

class MyHashSet {
public:
    vector<int> f;
    MyHashSet() {
        f = vector<int>(1e6+1);
    }
    
    void add(int key) {
        f[key]++;
    }
    
    void remove(int key) {
        if(f[key]) f[key]=0;
    }
    
    bool contains(int key) {
        return f[key] != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */