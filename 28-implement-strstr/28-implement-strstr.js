/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let n1=haystack.length, n2=needle.length, i=0, j=0; 
    if(n2==0){
        return 0;
    }
    while(i<n1){
        let tempi=i, tempj=j;
        while(tempi<n1 && tempj<n2 && haystack[tempi]==needle[tempj]){
            tempi++;
            tempj++;
        }
        if(tempj==n2){
            return i;
        }
        i++;
    }
    return -1;
};