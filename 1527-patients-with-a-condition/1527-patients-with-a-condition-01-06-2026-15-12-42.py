import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
 
    # patients['has_diabetes'] = patients.apply(lambda x: "Yes" if("DIAB1" in x['conditions']) else "No", axis=1)
    #doesn't pass for "SDIAB1" -> false chaiye but ye correc dega

    patients =  patients[patients['conditions'].str.contains(r'(^| )DIAB1') ]
    

    # patients['has_diabetes'] == 'Yes' #boolean series
    return patients[['patient_id','patient_name','conditions']]
 
    