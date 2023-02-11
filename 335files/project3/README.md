# Assignment-3-Code

Part 1 wasn't too hard, I just had to go over lecture slides and textbook to know the difference between quadratic and linear
probing. it was then just a matter of implementing the testwrapper function and having the exact outputs, but the counting
collisions for each individual probe took a while to figure out how to do - in the end I thought of storing that data in a separate array, but i just passed in an int variable by reference and returned that afterwards. 

Part 2 also wasn't too hard, I just was confused on how to mod a string instead of an int like the textbook does. Eventually I 
realized I could just hf(x) like the InternalHash function does, and despite my outputs being different from expected_output.txt, Gradescope accepted it. I tested with r values of 7, 19, and 29, and they didn't vary all too much.

Part 3 was the hardest part by far, I didn't really know where to even start with it at first. I figured I would make a public
function that accepts a string, with the precondition that it was an invalid word (and I made sure of that with .contains() in the spell_check.cc file). 

I first tried using the hash table to my advantage and checked adjacent positions, but that didn't give me much of anything useful, unfortunately. Maybe if the table was made to be more organized, that method could've gone somewhere...

Regardless, from there, given an invalid word, I first had to figure out how to insert a letter in every possible position to make new words. I decided to simply brute force it with a string of the alphabet, both lowercase and uppercase, and made substrings based on an index -> so given "rght" it could become "r" and "ght", as an exmaple. Then I just added left + [a-z] character + right and checked if that new string existed, if it did I would print the correction.

For case b, it was a similar methodology but I was just deleting a letter, so I again made two left and right strings from a base string based on an index, but the right string started 1 more to the right to hide a letter. "right" became "r" and "ght", hiding the i, as an example. I then added the new left and right together to check if that existed, and printed the correction if it did.

Case c was even simpler, I just had to swap two adjacent characters, check if the altered string existed (if it did, print correction), and then reset string to original. I forgot to go to .length - 1 at first, which gave me some pretty odd results (because it was going into invalid memory).