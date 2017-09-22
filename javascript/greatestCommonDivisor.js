/**
 * Find greatest common divisor of two numbers.
 * @param {number} - a number to check
 * @param {number} - a number to check the first number with
 * @returns {number} - greatest common divisor
 */
function greatestCommonDivisor(a, b){
  if(b == 0)
    return a;
  else 
    return greatestCommonDivisor(b, a%b);
}

