import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame: 

    users['name'] = users['name'].str.capitalize()

    return users.sort_values(by='user_id')
    #axis = 1  = apply on all rows
    