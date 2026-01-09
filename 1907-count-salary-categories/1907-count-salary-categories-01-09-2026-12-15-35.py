import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    low_salary = accounts[accounts['income'] < 20000][['income']].shape[0]

    avg_salary = accounts[ (accounts['income'] >= 20000) & (  accounts['income'] <= 50000) ].shape[0] 

    high_salary = accounts[accounts['income'] > 50000][['income']].shape[0]

    return pd.DataFrame({
       'category' : ['High Salary', 'Low Salary', 'Average Salary'],
        'accounts_count': [high_salary, low_salary, avg_salary]
        })



    