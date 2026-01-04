import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    # tweets['content'].str.len() > 15 -> boolean series
    return tweets[tweets['content'].str.len() > 15][['tweet_id']]