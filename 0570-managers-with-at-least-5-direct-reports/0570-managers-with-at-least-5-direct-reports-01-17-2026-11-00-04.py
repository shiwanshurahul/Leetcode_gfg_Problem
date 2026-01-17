import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    #khud ke table me dekhna hai -> cross join
    df = employee.groupby('managerId')['managerId'].count().rename('cnt_manager').reset_index()
    #df_ans has count of manager

    li = list( df[ df['cnt_manager']>=5]['managerId'] )

    return employee[employee['id'].isin(li)][['name']]
    