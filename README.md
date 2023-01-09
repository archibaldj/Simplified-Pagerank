# Simplified-Pagerank
A simplified version of Google's pagerank algorithm

Pagerank is an algorithm that determines the importance of a website based on the number of links and the importance of the links to a website

A simple explanation of this algorithm can be found here: 
https://www.youtube.com/watch?v=P8Kt6Abq_rM&ab_channel=GlobalSoftwareSupport

--------------------------------------------------------

To use this program follow these steps:
 - First line will be 2 integers, the first will be how many lines will follow (n), and the second integer will be the amount of power iterations (p)
 - On each of the next lines type two website names or any strings separated by a space
 
 Example:
 
** Input **
 
 6 2
 
 google.com facebook.com
 
 google.com instagram.com
 
 reddit.com ufl.edu
 
 ufl.edu google.com
 
 ufl.edu facebook.com
 
 instagram.com reddit.com
 
 
 
** Output **
 
 facebook.com 0.20
 
 google.com 0.10
 
 instagram.com 0.10
 
 reddit.com 0.20
 
 ufl.edu 0.20

 
