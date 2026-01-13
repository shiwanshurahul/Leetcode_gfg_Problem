import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df_ans = courses.groupby('class')['student'].count().reset_index()
    return df_ans[df_ans['student'] >=5 ][['class']]
    