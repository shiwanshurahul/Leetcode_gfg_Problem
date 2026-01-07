import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # scores['score'] = scores['score'].sort_values(ascending=False)
    
    scores['rank'] = scores['score'].rank(ascending=False,method='dense')

    return scores[['score','rank']].sort_values(by='score',ascending=False)