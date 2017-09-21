/**
 * @function isPrime - check if number is prime
 *
 * @param {number} - Number to check
 * @returns {boolean} - True if number is prime
 */
function isPrime(n){
  var divisor = 2;

  while (n > divisor){
    if(n % divisor == 0){
     return false; 
    }
    else
      divisor++;
  }
  return true;
}
