/**
 * @param {number} millis
 */
async function sleep(millis) {
      return new Promise((resolve, reject) => {
    let error = false;
    setTimeout(() => {
      if (!error) {
        resolve();
      } else {
        reject(new Error('sleep interrupted'));
      }
    }, millis);
  });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */