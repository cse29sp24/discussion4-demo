**IMPORTANT: ONLY DO THIS DEMO ON Ieng6! IT MAY NOT WORK LOCALLY.**

## Getting Started

In `bug.c`, we have the same program as what we saw in Week 2, albiet
slightly modified. The idea is the same -- two arrays, a function to increment
some elements, and print out the results. This time, however, we are using
a while loop in `increment()`, and we are incrementing every *other* element.

### Uninitialized variables

Compile using `make` (no -Wall flags needed, we don't want it to warn us about 
the uninitialized variable).

Run the program to observe that array 2 doesn't seem to have changed? How so?

Ask for theories.

Time to use valgrind! Compile using an additional `-g` flag.

Run valgrind: `valgrind --leak-check=full --track-origins=yes ./bug` to see
that there are warnings for using uninitialized values.

Print out what the uninitialized value is -- GARBAGE! Ha!

Fix the issue.

### Convert to dynamic memory allocation: Forgetting to free?

Rewrite the program using dynamic memory allocation. See `final.c`. Only
change the array declarations. Nothing else needs to be added.

Do *not* write `free()` statements yet.

Run valgrind again!

At the very end, valgrind warns us about memory leaks -- fix and free.

### After `free`ing: I wish it was that simple

Recompile, run again. BAM! big crash! What the f--- is that? Somehow by adding
free calls, we have made the bug even worse? Despite that, we are actually
one step closer to the real solution.

Run valgrind -- invalid writes! Sheesh.

Briefly explain invaild writes, and how in this case it messes up the heap
internal structure.

### Finally, fix the invalid writes

Same bug fix as week 2.

### Lastly: double free?

Make a double free and see what happens. 

