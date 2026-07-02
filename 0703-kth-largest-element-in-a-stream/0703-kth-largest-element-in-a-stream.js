/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function(k, nums) {
    this.k = k;
    this.pq = new MinPriorityQueue();
    for(let x of nums) {
        this.pq.enqueue(x);
        if(this.pq.size() > k) {
            this.pq.dequeue();
        }
    }
};
/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function(val) {
    this.pq.enqueue(val);
    if(this.pq.size() > this.k) {
        this.pq.dequeue();
    }
    let top = this.pq.front();
    return top.element !== undefined ? top.element : top;
};