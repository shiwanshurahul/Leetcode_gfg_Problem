/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    return this.reduce((accu, item)=> {
        const key = fn(item)
        if(!accu[key])
            accu[key] = []

        accu[key].push(item)    
        return accu
    }, {} )
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */