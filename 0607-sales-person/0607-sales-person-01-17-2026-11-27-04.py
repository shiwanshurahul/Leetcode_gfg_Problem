import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:

    #merge krdo 3no ko
    #company me name col ko rename to com_name bcz sales_person table me v name hai
    company.rename(columns={'name':'company_name'},inplace=True)

    df = pd.merge(sales_person,orders,on='sales_id',how='left')
    df_merge = pd.merge(df,company,on='com_id',how='left')
    #un sales_id ko hatao

    red_sales_id = df_merge[df_merge['company_name']=='RED']['sales_id'].unique()
    return sales_person[~sales_person['sales_id'].isin(red_sales_id)][['name']]