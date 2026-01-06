import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    salaries = employee['salary'].sort_values(ascending=False).drop_duplicates()

    print(salaries)
    if(len(salaries) <2):
        return pd.DataFrame({"SecondHighestSalary": [np.nan] })
    second_highest_salary = salaries.iloc[1]
    return pd.DataFrame({'SecondHighestSalary': [second_highest_salary] })
    