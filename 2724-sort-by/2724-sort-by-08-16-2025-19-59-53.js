/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    // (a,b) => a-b in ascending order
    return arr.sort((a,b) => fn(a) -fn(b))
};