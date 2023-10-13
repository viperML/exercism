module Pangram (isPangram) where

import Control.Monad.State
import Data.Char (isLetter, toLower, isAscii)

sentenceToLower :: String -> String
sentenceToLower = map toLower

letterCount :: Char -> State [Char] Bool
letterCount c = do
  s <- get
  if isAscii c && c `notElem` s && isLetter c
    then do
      put (c : s)
      return True
    else return False

allLetters :: [Char]
allLetters = ['a' .. 'z']

nLetters :: Int
nLetters = length allLetters

isPangram :: String -> Bool
isPangram text =
  let textLower = sentenceToLower text
      (_, unique) = runState (mapM letterCount textLower) []
   in length unique == nLetters
