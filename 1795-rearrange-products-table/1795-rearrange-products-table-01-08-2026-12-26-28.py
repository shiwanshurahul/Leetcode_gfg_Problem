import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    #wide to long: pd.melt(df, id_vars=None, value_vars=None, var_name=None, value_name='value')

    return pd.melt(products,id_vars='product_id', var_name='store', value_name='price').dropna()
    #id_vars -> columns you want to keep as identifier variable in converted df
    #dropna() -> dropna() (Default): Removes any row with at least one missing value (NaN)
    