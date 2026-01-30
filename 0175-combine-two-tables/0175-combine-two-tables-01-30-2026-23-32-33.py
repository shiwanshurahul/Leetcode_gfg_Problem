import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    df_ans = pd.merge(person, address, how='left', on='personId')
    return df_ans[['firstName','lastName','city','state']]
    