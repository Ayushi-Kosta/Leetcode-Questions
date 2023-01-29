class LFUCache {
public:
    unordered_map<int,list<int>> lfuCache; 
    unordered_map<int,pair<int,int>> getParams;       
    unordered_map<int,list<int>:: iterator> getIt;  
    int size;
    int capacity;
    int minFreq;
    LFUCache(int capacity) {
        this->capacity=capacity;
        size=0;
        minFreq=INT_MAX;
    }
    int get(int key) {
        if(capacity!=0 && getParams.find(key)!=getParams.end()){
            int value=getParams[key].first;
            int f=getParams[key].second;
            auto it=getIt[key];
            lfuCache[f].erase(it);    
            if(lfuCache[f].size()==0 && minFreq==f){
                minFreq=f+1;         
            }
            
            getParams[key].second=f+1;
            lfuCache[f+1].push_front(key);
            it=lfuCache[f+1].begin();
            getIt[key]=it;
            return value;
        }else
            return -1;
    }
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(getParams.find(key)==getParams.end()){
            if(size==capacity){
                auto it=lfuCache[minFreq].end();
                it--;                             
                
                int element=*(it);
                getParams.erase(element);
                getIt.erase(element);               
                lfuCache[minFreq].pop_back();
                if(lfuCache[minFreq].size()==0){
                    minFreq=1;                       
                }
                size--;
            }
            lfuCache[1].push_front(key);
            getParams[key]={value,1};
            getIt[key]=lfuCache[1].begin();
            minFreq=min(minFreq,1);
            size++;
        }else{
            int f=getParams[key].second;
            auto it=getIt[key];
            lfuCache[f].erase(it);
            if(lfuCache[f].size()==0 && minFreq==f){
                minFreq=f+1;
            }
            getParams[key]={value,f+1};
            lfuCache[f+1].push_front(key);
            it=lfuCache[f+1].begin();
            getIt[key]=it;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */