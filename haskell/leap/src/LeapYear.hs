module LeapYear (isLeapYear) where



divisibleBy :: Integer -> Integer -> Bool
divisibleBy num den = num `mod` den == 0

isLeapYear :: Integer -> Bool
isLeapYear year = let d = divisibleBy year
                  in (d 4 && not (d 100)) || d 400

