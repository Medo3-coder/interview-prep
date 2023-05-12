#Memoization: is a top-down approach where we cache the results of function calls and return the cached result 
if the function is called again with the same inputs. It is used when we can divide the problem into subproblems and the subproblems have overlapping subproblems.
Memoization is typically implemented using recursion and is well-suited for problems that have a relatively small set of inputs.

#Tabulation: is a bottom-up approach where we store the results of the subproblems in a table and use these results to solve larger
subproblems until we solve the entire problem. It is used when we can define the problem as a sequence of subproblems and the subproblems do not overlap.
Tabulation is typically implemented using iteration and is well-suited for problems that have a large set of inputs.



#Top-down approach
Caches the results of function calls
Recursive implementation
Well-suited for problems with a relatively small set of inputs
Used when the subproblems have overlapping subproblems

#Tabulation:
Bottom-up approach
Stores the results of subproblems in a table
Iterative implementation
Well-suited for problems with a large set of inputs
Used when the subproblems do not overlap
Here’s an example of using memoization and tabulation to solve the same problem – calculating the nth number in the Fibonacci sequenc
