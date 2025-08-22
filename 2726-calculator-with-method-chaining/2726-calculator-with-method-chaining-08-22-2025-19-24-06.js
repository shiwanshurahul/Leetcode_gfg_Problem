class Calculator {
    
    /** 
     * @param {number} value
     */
    constructor(value) {
     this.val = value   
     
    }

    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.val = this.val + value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.val = this.val - value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.val = this.val * value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if(value === 0)
            throw new Error("Division by zero is not allowed")   

        this.val = this.val / value

        return this    
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        // let val = this.val
        // let pow = 1   //tle de rha
        // while(value--){
        //    pow *= val
        // }

        this.val = this.val ** value

        return this 
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.val
    }
}