import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    # (products['low_fats'] == 'Y') & (products['recyclable'] == 'Y' )   #boolean series

     df_ans = products[ (products['low_fats'] == 'Y') & (products['recyclable'] == 'Y' ) ]  #only true wale values
     return df_ans[['product_id']]



     #df_ans['product_id'] is a series
     #but df_ans[['product_id']] is a df