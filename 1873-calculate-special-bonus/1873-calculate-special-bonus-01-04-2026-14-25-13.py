import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:


    employees['bonus'] = employees.apply(lambda x : x['salary'] if (x['employee_id'] %2 !=0) & ~(x['name'][0] =='M') else 0 ,axis=1) 
    # axis = 1 applies the function to each row.
    return employees[['employee_id','bonus']].sort_values(by='employee_id')

    


