class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int a=0, n1=version1.size(), n2=version2.size();
            for(int i=0; i<n1; i++){
                if(version1[i]=='.'){
                    //if(a!=0){
                        v1.push_back(a);
                        a=0;
                   // }
                }
                else{
                    a=a*10+(version1[i]-'0');
                }
            }
        //if(a!=0){
            v1.push_back(a);
        //}
        a=0;
            for(int i=0; i<n2; i++){
               
                if(version2[i]=='.'){
                    //if(a!=0){
                        v2.push_back(a);
                        a=0;
                    //}
                }
                else{
                     a=a*10+(version2[i]-'0');     
                }
            }
        //if(a!=0){
            v2.push_back(a);
       // }
        int z = min(v1.size(), v2.size());
//         for(int i=0; i<v1.size(); i++){
//             cout<<v1[i]<<" ";
            
//         }
//         cout<<" ||| ";
//         for(int i=0; i<v2.size(); i++){
//             cout<<v2[i]<<" ";
//         }
//         cout<<"\n";
        for(int i=0; i<z; i++){
            if(v1[i]>v2[i]){
                cout<<1<<"\n";
                return 1;
            }
            else if(v1[i]<v2[i]){
                cout<<2<<"\n";
                return -1;
            }
            else{
                continue;
            }
            
        }
        if(v1.size()>v2.size()){
            bool t =1;
            for(int i=v2.size(); i<v1.size(); i++){
                if(v1[i]!=0){
                    t=0;
                    break;
                }
            }
            cout<<3<<"\n";
            if(!t) return 1;
            else return 0;
        }
        else if(v1.size()<v2.size()){
            bool t =1;
            for(int i=v1.size(); i<v2.size(); i++){
                if(v2[i]!=0){
                    t=0;
                    break;
                }
            }
            cout<<4<<"\n";
            if(!t) return -1;
            else return 0;
        }
        else{
            cout<<5<<"\n";
            return 0;
        }
    }
};