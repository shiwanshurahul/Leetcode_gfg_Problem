import pandas as pd
import numpy as np

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    #find those id jo Customers me hai but Orders me ni
    
    customer_id_did_not_order = np.setdiff1d(customers['id'], orders['customerId'])   #list deta

    df_ans = pd.DataFrame([])  #ans df me Customers col name chahiy
    df_ans['Customers'] = customers[ customers['id'].isin(customer_id_did_not_order) ][['name']]
    # return df_ans

    #m2: without creating a new df
    return customers[ customers['id'].isin(customer_id_did_not_order) ][['name']].rename(columns={'name':'Customers'})
