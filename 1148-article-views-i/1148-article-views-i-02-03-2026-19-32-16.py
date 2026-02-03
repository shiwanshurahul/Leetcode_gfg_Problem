import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df_ans =  views[views['author_id'] == views['viewer_id']].sort_values(by='author_id')

    # df_ans = df_ans.rename(columns={'author_id' : 'id'}) 
    # return df_ans[['id']].drop_duplicates()

    #m2:
    return df_ans[['author_id']].rename(columns={'author_id' : 'id' }).drop_duplicates()
    