var SummaryRanges = function() {
    this.numsSet = new Set();
};

/** 
 * @param {number} value
 * @return {void}
 */
SummaryRanges.prototype.addNum = function(value) {
    this.numsSet.add(value);
};

/**
 * @return {number[][]}
 */
SummaryRanges.prototype.getIntervals = function() {
    if (this.numsSet.size === 0) return [];
    const sortedNums = Array.from(this.numsSet).sort((a, b) => a - b);
    const intervals = [];
    let start = sortedNums[0];
    let end = sortedNums[0];
    for(let i = 1; i < sortedNums.length; i++) {
        let current = sortedNums[i];
        if(current === end + 1) {
            end = current;
        } 
        else {
            intervals.push([start, end]);
            start = current;
            end = current;
        }
    }
    intervals.push([start, end]);
    return intervals;
};