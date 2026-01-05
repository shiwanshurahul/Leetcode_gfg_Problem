import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:

    # users['mail'].str.match(r'[a-zA-Z][A-Za-z0-9_\.\-]*leetcode.com$')   -> boolean series

    valid_email_df = users[users['mail'].str.match(r'[a-zA-Z][A-Za-z0-9_\.\-]*@leetcode\.com$')]  

    return valid_email_df
     #idhr specify kr diya ki name pe lgana hai toh axis =1 ki no jarurat