import pandas as pd
import numpy as np

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    

    unique_salaries = employee['salary'].sort_values(ascending=False).drop_duplicates()
    #sirf salary col utha rhe usi pe dono kr rhe = efficien

    if N<=0 or N > (len(unique_salaries)): #drop duplicates 
        return pd.DataFrame({f'getNthHighestSalary({N})' : [None]})
    
    nth_salary =  unique_salaries.iloc[N-1]
    return pd.DataFrame({f'getNthHighestSalary({N})' : [nth_salary]})



    #   🔹 Case 2
# employee.sort_values(by='salary', ascending=False)

# Operates on entire DataFrame
# Object type: DataFrame
# Rows are reordered based on salary
# All columns move together

# Example output:

#    name   dept   salary
# 2  C      IT     90000
# 0  A      HR     80000
# 1  B      IT     70000

# 👉 Sorting a column ≠ sorting a table

# Think like this:
# employee['salary'].sort_values()
# → “Give me salaries in order”

# employee.sort_values(by='salary')
# → “Reorder employees by salary”

# Same criteria, different data structure → different result.


