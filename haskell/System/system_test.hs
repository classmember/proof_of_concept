{-
 - System module example
 -}

import System.Info
import Data.Version


main = do 
    let version = showVersion compilerVersion
    let file = "\
    \This is Haskell compiled from\
    \ " ++ compilerName ++ "\
    \ " ++ version ++ " running on\
    \ " ++ os ++ " for the\
    \ " ++ arch ++ " archecture."
    putStrLn file
