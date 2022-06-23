/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(a, b) {
    if(a.length > b.length) return findMedianSortedArrays(b, a);
    
    const x = a.length, y = b.length;
    let low = 0, high = x;
    
    while(low <= high) {
        let partitionX = (low + high) / 2 | 0,
            partitionY = (x + y + 1) / 2 - partitionX | 0;
        
        let maxLeftX = partitionX === 0 ? -Infinity : a[partitionX - 1];
        let minRightX = partitionX === x ? Infinity : a[partitionX];
        
        let maxLeftY = partitionY === 0 ? -Infinity : b[partitionY - 1];
        let minRightY = partitionY === y ? Infinity : b[partitionY];
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((x + y) & 1) return Math.max(maxLeftX, maxLeftY);
            return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
        } else if(maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
};