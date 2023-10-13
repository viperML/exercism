{-# LANGUAGE OverloadedStrings #-}

module Bob (responseFor) where

import Data.Char (isLetter, isNumber, isSpace)
import Data.Text
import Prelude hiding (last)

responseFor :: Text -> Text
responseFor t
  | isQuestion t && isYell t = "Calm down, I know what I'm doing!"
  | isQuestion t = "Sure."
  | isYell t = "Whoa, chill out!"
  | Data.Text.filter (not . isSpace) t == empty = "Fine. Be that way!"
  | otherwise = "Whatever."

isQuestion :: Text -> Bool
isQuestion t = case unsnoc . strip $ t of
  Just (_, '?') -> True
  _ -> False

isYell :: Text -> Bool
isYell t = t' == toUpper t' && t' /= empty
  where
    t' = Data.Text.filter isLetter t
