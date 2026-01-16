import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:

    df = examinations.groupby(['student_id','subject_name']).size().reset_index(name='attended_exams')
    df_merge = pd.merge(students,subjects,how='cross')

    ans_df = pd.merge(df_merge, df, how='left', on=['student_id','subject_name']).sort_values(by=['student_id', 'subject_name'])
    ans_df['attended_exams'] = ans_df['attended_exams'].fillna(0)

    return ans_df[['student_id', 'student_name', 'subject_name', 'attended_exams']]
    