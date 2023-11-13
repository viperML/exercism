{-# LANGUAGE BangPatterns #-}

module Triplet (tripletsWithSum) where

import Control.Parallel.Strategies (Eval)
import Data.Function ((&))
import Debug.Trace (trace, traceId, traceShow, traceShowId)
import Prelude hiding (sum)

tripletsWithSum :: Int -> [(Int, Int, Int)]
tripletsWithSum sum = do
    !c <- candidates sum

    []

candidates :: Int -> [(Int, Int, Int)]
candidates sum = do
    a <- [1 .. sum]
    b <- [1 .. sum - a]
    let c = traceShowId $ sum - a - b

    if c < a
        then return (c, b, a)
        else
            if c < b
                then return (a, c, b)
                else return (a, b, c)

-- if c > 0
--     then return (a, b, c)
--     else []
