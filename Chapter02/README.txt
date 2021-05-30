Chapter 2 Exercises

1. Write a program to determine the ranges of char, short, int, and long
   variables, both signed and unsigned, by printing appropriate values
   from standard headers and by direct computation. Harder if you compute
   them: determine the ranges of the various floating-point types.

2. Write a loop equivalent to the for loop above without using && or ||.

3. Write the function htoi(s), which converts a string of hexadecimal
   digits (including an optional 0x or 0X) into its equivalent integer
   value. The allowable digits are 0 through 9, a through f, and A through
   F.

4. Write an alternate version of squeeze(s1,s2) that deletes each character
   in s1 that matches any character in the string s2.

5. Write the function any(s1,s2), which returns the first location in the
   string s1 where any character from string s2 occurs, or -1 if s1 contains
   no characters from s2.

6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin
   at position p set to the rightmost n bits of y, leaving the other bits
   unchanged.

7. Write a function invert(x,p,n) that returns x with the n bits that begin at
   position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
   others unchanged.

8. Write a function rightrot(x,n) that returns the value of the integer x 
   rotated to the right by n bit positions.
