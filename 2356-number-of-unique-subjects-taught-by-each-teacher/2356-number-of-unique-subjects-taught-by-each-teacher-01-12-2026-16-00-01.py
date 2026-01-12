import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:

     #groupby often results in a DataFrame with the grouping columns as the index (a MultiIndex if grouping by multiple columns). reset_index() turns these index levels back into regular data columns.


    #  To count the number of unique values within each group of a pandas DataFrame, you should use the .nunique() method

    return teacher.groupby('teacher_id')['subject_id'].nunique().reset_index().rename(columns={'subject_id': 'cnt'})
    