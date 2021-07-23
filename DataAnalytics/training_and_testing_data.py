import numpy as np 
import pandas as pd 
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from math import sqrt
from sklearn.metrics import r2_score
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report,confusion_matrix



data = pd.read_csv("preprocessed_data.csv")

data.drop("gender", axis = 1, inplace = True)

data["age"] = (data["age"] - data["age"].mean()) / data["age"].std()
data["bmi"] = (data["bmi"] - data["bmi"].mean()) / data["bmi"].std()


feature_df = data[['age', 'male','female', 'bmi', 'bpc', 'cholesterol', 'gluc','smoke', 'alco', 'active']]
X = np.asarray(feature_df)

data['cardio'] = data['cardio'].astype('int')
y = np.asarray(data['cardio'])

X_trainset, X_testset, Y_trainset, Y_testset = train_test_split(X, y, test_size=0.2)





