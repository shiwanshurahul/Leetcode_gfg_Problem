import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    department = department.rename(columns={"name" : "Department"})

    df_merge = pd.merge(employee, department,how='inner',left_on='departmentId', right_on='id')


    df_ans = df_merge.groupby('departmentId').apply(lambda x: x[x['salary'] == x['salary'].max()])

    return df_ans[['Department','name','salary']].rename(columns={'name': 'Employee' , 'salary':'Salary'})
   
    # return df_merge.groupby('department_name')['salary'].max()
    

