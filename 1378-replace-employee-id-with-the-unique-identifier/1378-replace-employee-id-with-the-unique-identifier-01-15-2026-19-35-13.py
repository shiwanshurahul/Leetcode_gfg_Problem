import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:

    #join kro
    df_ans = pd.merge(employees,employee_uni,on='id',how='left')
    #inner join kroge toh jo ni hai employee_uni me wo remove hoenge - id: 1,7
    return df_ans[['unique_id','name']]
    