import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    #world me hai mentioned fields
    # (world['area'] >= 3000000) | (world['population'] >= 25000000)
    # -> boolean series
    df_big= world[(world['area'] >= 3000000) | (world['population'] >= 25000000) ]
    return df_big[['name','population','area']]