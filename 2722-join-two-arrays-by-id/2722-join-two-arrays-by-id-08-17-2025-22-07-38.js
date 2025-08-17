/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {  //arr of obj
    let arr3 = {}
    for(let i=0;i<arr1.length;i++){
        arr3[arr1[i].id] = arr1[i]
    }

    for(let i=0;i<arr2.length;i++){
        if(arr3[arr2[i].id]){  //already exists
            for(const key in arr2[i]){
                arr3[arr2[i].id][key] = arr2[i][key]  //override krke arr2 dalo
            }
        }
        else {
            arr3[arr2[i].id] = arr2[i]
            }
    }

    return Object.values(arr3);
    

};