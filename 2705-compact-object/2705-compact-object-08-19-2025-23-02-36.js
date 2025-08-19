/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
 //0,null,false hatao -> iterate/recursion krke hatalo
 //Array.isArray -> JavaScript method that determines whether a given value is an array. It returns true if the value is an array and false otherwise. 
//  let numbers = [1, 2, 3];
// let text = "Hello";
// console.log(Array.isArray(numbers)); // Output: true
// console.log(Array.isArray(text));    // Output: false

var compactObject = function(obj) {
    if(obj === null || typeof obj !== "object")
        return obj

    if(Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject)    //boolean ke basis pe filter krenge = falsey method remove fir map krenge
    }

    const compacted = {}
    for(const key in obj){
        let value = compactObject(obj[key])
        if(value)
            compacted[key] = value
    }
    return compacted
};