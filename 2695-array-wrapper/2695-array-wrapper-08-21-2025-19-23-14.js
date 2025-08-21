/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.nums = nums
};

/**
 * @return {number}
 */  
// const sum = arr.reduce((acc, curr_val) => acc + curr_val, 0);
ArrayWrapper.prototype.valueOf = function() {
    //add kro 
    return this.nums.reduce((accu, curr_val) => accu + curr_val,0)
}

/**
 * @return {string}
 */
 //JSON.parse() -> converts/parses json string to object in js
// e.g. const json = '{"result":true, "count":42}';
//const obj = JSON.parse(json); 

//JSON.stringify() is a static method in JavaScript that converts a JavaScript value 
// (typically an object or array) into a JSON formatted string.
ArrayWrapper.prototype.toString = function() {
    return JSON.stringify(this.nums)
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */