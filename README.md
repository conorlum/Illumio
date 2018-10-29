# Illumio
Illumio Coding Challenge


The Nat Flow and Output Files need to be changed to the locations of the files on the local machine before the program will work correctly.

I tested my code by editted the sample Nat file given to have all of the edge cases that I could think of.  I also editted the flow file to have edge cases, though this was easier as there are not as many.

I picked a map of string to string as going through the keys with a simple regex made finding the correct mapping very easy and intuitive.  This implementation is the most stright forward and easy to explain, but is not the most optimal.  Space and Time complexity savings can be gained through the use of a trie as this would reduce the need to loop through all keys to find the correct matching.  If I had another couple hours I would be able to change my solution to incorporate this data structure instead of simply using a map.

I also glossed over the inputting of file locations as this was not defined well and so defined strings and modular functions that would be easy to use that just need to be editted to use the program.

Thanks for reading this!
