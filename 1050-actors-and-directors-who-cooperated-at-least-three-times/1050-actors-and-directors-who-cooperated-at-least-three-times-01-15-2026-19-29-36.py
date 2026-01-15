import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    df_ans = actor_director.groupby(['actor_id','director_id'])['timestamp'].nunique().reset_index()
    return df_ans[df_ans['timestamp'] >=3][['actor_id','director_id']]