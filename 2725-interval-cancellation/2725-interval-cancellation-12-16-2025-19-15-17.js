/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
//Unlike setTimeout(), which executes a function only once after a delay, 
//setInterval() continuously calls the function until it is explicitly stopped
//To stop the repetitive execution, the clearInterval() method is used
//const interval = setInterval(function(){      har sec 'hi' print krega, clearInterval lagate hi kuch print ni hoga 
//                       console.log('hi')  
 //                     }, 1000)
 //       clearInterval(interval) 

var cancellable = function(fn, args, t) {
    fn(...args)  //given in quest
    let timer = setInterval(()=>{
                    fn(...args)
                } , t);
    let cancelFn = function(){
        clearInterval(timer)
    }
    
    return cancelFn
    
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 2;
 *  const args = [4], t = 35, cancelTimeMs = 190;
 *
 *  const start = performance.now();
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr)});
 *  }
 *       
 *  const cancel = cancellable(log, args, t);
 *
 *  setTimeout(cancel, cancelTimeMs);
 *   
 *  setTimeout(() => {
 *      console.log(result); // [
 *                           //     {"time":0,"returned":8},
 *                           //     {"time":35,"returned":8},
 *                           //     {"time":70,"returned":8},
 *                           //     {"time":105,"returned":8},
 *                           //     {"time":140,"returned":8},
 *                           //     {"time":175,"returned":8}
 *                           // ]
 *  }, cancelTimeMs + t + 15)    
 */