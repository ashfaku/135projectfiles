[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8629777&assignment_repo_type=AssignmentRepo)
# Assignment 2

You will use this exact `Makefile` for your Homework 2. Failure to do so will result in *deduction* of points. Replace this file with a `README.md` for your own project. You can move these instructions to the bottom of the file if you wish.

To compile on terminal, type:

```bash
make
```

You can compile one program individually by just typing `make <Program Name>`, for example:

```bash
make query_tree
```

To delete executables and object files, type:

```bash
make clean
```

To start off, part 1 wasn't too bad - aside from realizing Gradescope wanted the << overload, and finding out how to overload the < and > operators.

For part 2, initially parsing the rebase210.txt file was confusing because of how it was formatted; I initially thought each line would have one unique recognition sequence and multiple acronyms, but it was the reverse; where one line may contain one enzyme acronym (not necessarily unique), and multiple recognition sequences (not necessarily unique) to pair with it. Debugging the parser took a while, especially since I kept getting an extra node (566 instead of 565) - I eventually figured out that it was because of the // at the end of each line (it was adding a node with a recognition sequence of length 0, which must've been the extra node), so I just added a check for that.

After creating the parser, I had to make the find() method (or whatever you want to call it) for 2a, and I initially was troubled on how to print the node's acronyms, as the vector is a private instance variable. I thought of two ways; either doing ```cout << t->element```, or creating a accessor function for the vector and printing that. I decided to go with the former, and then I was troubled on how/when I'd print "Not Found". I didn't want to do it in the t -- nullptr if, in case that would print it when I don't want it to. I figured I'd make the find() method a bool return, where it returns true after printing the vector (if it finds the element), and false when t == nullptr. I used that true/false value in an if statement in the query_tree.cc code, negated it, and printed "Not Found" when the negation was true; i.e when find() returned false. 

Moving on 2b, I iniitially wanted to create a recursive function to find the number of nodes (n) every time I called getNodeCount() (or whatever you'd call it). But after creating it, I remembered something I've done in the past. I added a private int variable to avl_tree.h and incrememented that variable every time a new node was inserted (not when Merge is called, though), and made the getNodeCount() just be an accessor function for that variable. Not only was that easier to implement and understand than the recursive count, it saves me some run time when I need to call it. 

Then, for the internal path length, I was initially confused on what that even meant; but after reading the textbook I figured out it was the sum of each distance of nodes to the root (with root to root being 0, and naturally a nullptr is 0), so I tried passing in an int value starting at 0 (not by reference) to keep track of the level each recursive call is on, and returned the sum of each subtree's recursive calls + the depth of the current recursive call. 

For the next part, I decided to make a copy of my find() method, but instead of returning a bool, I had it return an int. Firstly in the public version, I checked if the element even existed with contains(); if it didn't, I returned 0. Else, whenever a recursive call of my helper private function was about to be returned, I tacked on a 1 to it to count it in the final return value, and I returned 0 when t == nullptr.

For the removals, I initially tried doing a similar method for the previous part to count recursive calls, but I kept getting too low or too high decimals. I played around with the if elses for a bit, but realized there must've been a bigger issue. When a peer told me Ms. Raja said on Blackboard to count findMin calls, I noticed I wasn't doing that; so like for my node count, I added another private variable, created a getter for it, and incremented it for each findMin call. For counting removal recursive calls, what I ended up doing was similar, but different. I passed in a local int variable by reference from my public function, and incremented that for each recursive call (my private function was void, now. I thought to do that after comparing it to the given remove), and returned that after all was said and done. After some tinkering, I got 9.1, which was accepted by Gradecscope thankfully. I then just copy pasted my routines from previously to finish off 2b. 

2c I copied over the exact code from test_tree.cc to test_tree_mod.cc and made the avl_tree_p2c.h file as a copy of avl_tree.h, and went to the double rotation methods. I initially didn't know what you meant by "directly" double rotate, but I assumed you meant to just transform it into the result with the three nodes (either root, left, left-right or root, right, right-left) given, with the precondition that all of them were nullptr. I diagramed it for hours, and after getting a lot of segmentation faults / losing subtrees because of mistakenly reassigning too early and what not, I got both left-right and right-left rotations to work "directly." 