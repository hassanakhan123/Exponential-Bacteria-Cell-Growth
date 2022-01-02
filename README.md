# Exponential-Bacteria-Cell-Growth

### Overview & Objectives

In this project, a series of functions are implemented that:
- simulate an exponential growth equation to model and log bacterial growth.
- allow to model the growth of multiple bacteria (different populations), store results in a 2D array and display the growth of populations in a formatted table.

Specifically, 4 functions are implemented:
1. `initialize` - it initializes the bacterial sample (prompt the user for k and N0).
2. `calculate` - it calculates and store the bacterial population (over time t=0 to 10 hours) in an array.
3. `display` - it outputs the growth summary of the single bacterial population from the 1D array, on console.
4. `twoDdisplay` - it outputs the growth summary of multiple bacterial populations from the 2D array, on console.

### Part 1: Simulate Exponential Bacterial Cell Growth
This part allows the user to enter parameters k and N0 that initialize a simple population of bacterial cells N(t), which grows according to the exponential growth equation:
######
N(t) = N0*e^(kt); where t=time (hours), N0 = initial population (cells); k = growth factor
######
*Examples of possible outputs:*

![image](https://user-images.githubusercontent.com/80440201/147865193-a162420a-cead-4bf9-aadb-9655dd22ffdc.png)

### Part 2: Pass the values of k and N0 to the program as command-line arguments
- In the example below, k = 0.24 and N0 = 38 is used as command-line arguments. 
- When k and N0 are specified at command-line, the user is not prompted to specify k and N0.
######
*Example of possible output:*

![image](https://user-images.githubusercontent.com/80440201/147865261-6d2653dd-a9df-4faa-9ee3-560cba4f402b.png)
### Part 3: Pass the number of bacterial populations as a command-line argument
-  The following example command-line implies that 3 separate bacterial populations are to be tracked and logged when the program is run at the command prompt (>): `lab2proj.exe 3`
######
*Example of possible output:*

![image](https://user-images.githubusercontent.com/80440201/147865396-cdad52fa-9aed-4d75-bbc8-b9dd6de79c2f.png)
