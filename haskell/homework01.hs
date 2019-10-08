-- homework 01 for haskell
-- @author: Kolby Heacock
-- @date: Oct 6, 2019
-- @link: https://www.cis.upenn.edu/~cis194/spring13/hw/01-intro.pdf
-- @output:
-- $ runhaskell homework01
--   validate [1, 3, 8, 6]
--   Invalid
--   validate [2, 1, 2, 1]
--   Valid

-- Double first of every pair
rule01 :: [Integer] -> [Integer]
rule01 []         = []
rule01 (x:[])     = [x]
rule01 (x:(y:zs)) = x*2 : y : rule01 zs

-- sum list of integers
rule02 :: [Integer] -> [Integer]
rule02 []         = []
rule02 (x:[])     = [x]
rule02 (x)        = [sum x]

-- check if it's divided by 10
rule03 :: [Integer] -> [Integer]
rule03 []         = []
rule03 (x)        = [mod (head x) 10]

-- Apply rule set to array
rules :: [Integer] -> [Integer]
rules []         = []
rules (x:[])     = [x]
rules (x:(y:zs)) = (rule03 (rule02 (rule01 (x:y:zs))))

validate :: [Integer] -> String
validate []         = "Invalid"
validate (x:[])     = "Invalid"
validate (x:y:zs)
    | (head (rule03 (rule02 (rule01 (x:y:zs))))) == 0 = "Valid"
    | otherwise = "Invalid"

main :: IO ()
main = do putStrLn "validate [1, 3, 8, 6]"
          putStrLn (validate [1, 3, 8, 6])
          putStrLn "validate [2, 1, 2, 1]"
          putStrLn (validate [2, 1, 2, 1])
