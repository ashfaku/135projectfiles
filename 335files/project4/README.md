[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9312387&assignment_repo_type=AssignmentRepo)
# Assignment-4-Code


For part 1, the main issue I had was figuring out how to use a function as a parameter - it didn't make any sense to me, considering
we've been using objects/primitives as paramters in the past (although I guess JavaScript has something like this too, with lambdas).
VerifyOrder was a simple matter after that, and the vector generators were simple enough with a normal for loop. 

Heap and Merge sorting were simple enough to alter to use a comparator, I just had to figure out wherever two items were being compared (be it inside the sort function or inside any helpers), and replace that with the comparator. Regular QuickSort was easy enough also, I just had to follow along the textbook's explanation of it and use the comparator where needed.

QuickSorts 2 and 3 were the hardest ones, I at first didn't know what the difference was between "middle pivot" vs "middle as pivot". After a bit of review, I realized middle pivot meant using the middle of the subarray - so left + (right - left)/2 as the pivot, and middle as pivot meant (left+right)/2 as the pivot, but not used as a median of 3 like the first quicksort was. It was similar enough code to the original quick sort, thankfully. 

For Q2, I just made a few example cases for the first one and eventually generalized it into a formula - not much else to say. 
For the other 3, I just picked the choices that made the most sense.

