Flatten a Multi-Level Linked List


You are given a linked list structure, where each node has two pointers:

next: points to an identical node towards the right.
down: points to an identical node towards the bottom.
Only the top most node can have a non-NULL next pointer.

This gives us a set of vertical linked lists and a horizontal linked list with the head nodes of the vertical lists.

Also, all vertical lists are sorted.

Your task is to flatten the lists into a single linked list, which should also be sorted.

Input:  1 -> 5 -> 8 -> 13
        |    |    |     |
        V    V    V     V
        3    8    14    15
        |         |     |
        V         V     V
        8         26    22
                        |
                        V
                        25

Output: 1 -> 3 -> 5 -> 8 -> 8 -> 8 -> 13 -> 14 -> 15 -> 22 -> 25 -> 26

Flatten a Multi-Level Linked List
Testing
Input Format
The first line contains ‘T’ denoting no of test cases.

For each test case,

The first line contains an integer ‘n’ denoting the number of connected vertical linked lists.
The second line contains n space-separated integers Li denoting the length of each vertical linked list.
Next n lines contain Li space-separated integers denoting elements of the respective linked list.
Output Format
For each test case, a line containing space-separated integers denoting the elements of flattened linked list.

Sample Input
1
4
3 2 3 4
1 3 8
5 8
8 14 26
13 15 22 25
Expected Output
1 3 5 8 8 8 13 14 15 22 25 26
Take a look at the diagram above to understand this better.