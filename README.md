# FibonacciAnalysis
Skimming through various implementations of fibonacci and creating a general analysis.

Problem Statement Equation = F(n) = (F(n-1)+F(n-2)) mod m

--Recursive--
Time Complexity = O(2^n)
Space Complexity = O(n)
Constraints = Time becomes a valuable commodity even for smaller values of n.
Can't work in desired appropriate time for (n>40).

--Dynamic--
Time Complexity = O(n)
Space Complexity = O(n)
Constraints = works only for arrays whose size is less than system configuration.
Can't decalre array greater than size (10^6). 

--Iterative--
Time Complexity = O(n)
Space Complexity = O(1)
Constraints = Doesn't work for very large value of n.
eg, calculating F(10^1000) won't work.

--Iterative for very large values of n--
Time Complexity = O(log n)
Only looping through the number of digits in the number rather than the number itself. 
Space Complexity = O(m^2) but usually doesn't go that far. 
It in most cases is not greater than 6m hence O(m).
Works well for very large values of n even for (n = 10^1000)
Constraints = Complexities should be in context of the input size n not in terms of m.
