/**
 * Check if a number is prime. A while loop that divides by 2
 * and increases the number until the divisor reaches 0.
 * @param {number} - Number to check
 * @returns {boolean} - True if number is prime
 * @see https://www.thatjsdude.com/interview/js1.html
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
