# Puzzle
A puzzle based on the (N-1) Puzzle and using linked Lists.

This is a puzzle that randomly lists puzzles something like this

```
=================
1   2   3
4   5   6
7   8   
=================
```

This puzzle is in the solved state. Puzzles will always come randomly generated.

#Controls

```
? - Display the Help Menu

w - Move blank space up
s - Move blank space down
a - Move blank space left
d - Move blank space right

m - Input a specific puzzle with keyboard input
r - Randomly generate a puzzle
f - Let the computer solve the puzzle
t - Not available
```

#Note about solve algorithm
This algorithm uses Linked List, which is an algorithm that will solve this O(n) in a worst case scenario.
Also 2x2, 3x3 have unsolvable puzzles which this program does not check for.
2x2 will quickly solve or determine that the puzzle is unsolvable
3x3 will usually solve if its solveable or go for eternity if its unsolvable (due to the number of combinations is so large)
4x4's or higher is usually not possible.

Can I fix this problem? I can replace Linked Lists with a Binary Search Tree Algorithm which will reduce it with O(log(n)) on a worse case scenario
I haven't taken the time to implement this.
