import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
       #groupby often results in a DataFrame with the grouping columns as the index (a MultiIndex if grouping by multiple columns). reset_index() turns these index levels back into regular data columns
       df_ans = orders.groupby('customer_number')['order_number'].count().reset_index()
       return df_ans.sort_values(by='order_number', ascending=False)[['customer_number']].head(1)

    