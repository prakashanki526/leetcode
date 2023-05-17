/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    return new Promise(async function(resolve) {

        if (functions.length == 0) {
            resolve();
        }
        
        var s = 0;
        var f = 0;

        let next = async function() {
            if (s >= functions.length) {
                return;
            }

            s++;
            await functions[s - 1]();
            f++;

            if (f == functions.length) {
                resolve();
            }

            next();
        };

        for (let i = 0; i < Math.min(functions.length, n); i++) {
            next();
        }
    });
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */