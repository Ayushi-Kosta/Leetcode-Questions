class Solution {
public:
    string addBinary(string a, string b) {
        string carry="0";
        string s;
        int i=a.size()-1, j=b.size()-1;
        while(i>=0 and j>=0){
            if(a[i]=='1' and b[j]=='1'){
                if(carry=="1"){
                    s+="1";
                    carry="1";
                }
                else{
                    s+="0";
                    carry="1";
                    
                }
            }
            else if((a[i]=='1' and b[j]=='0') or (a[i]=='0' and b[j]=='1')){
                if(carry=="0"){
                    s+="1";
                    carry="0";
                }
                else{
                    s+="0";
                    carry="1";
                }
                
            }
            else{
                if(carry=="0"){
                    s+="0";
                }
                else{
                    s+="1";
                }
                carry="0";
            }
            i--; j--;
        }
        while(i>=0){
            if(a[i]=='1'){
                if(carry=="1"){
                    s+="0";
                    carry="1";
                }
                else
                    s+="1";   
            }
            else{
                if(carry=="1"){
                    s+="1";
                    carry="0";
                }
                else
                    s+="0";                   
            }
            i--;
        }
        while(j>=0){
            if(b[j]=='1'){
                if(carry=="1"){
                    s+="0";
                    carry="1";
                }
                else
                    s+="1";   
            }
            else{
                if(carry=="1"){
                    s+="1";
                    carry="0";
                }
                else
                    s+="0";                   
            }
            j--;
        }
        if(carry=="1"){
            s+="1";
        }
        // else{
        //     s+="0";
        // }
        reverse(s.begin(), s.end());
        return s;
    }
};