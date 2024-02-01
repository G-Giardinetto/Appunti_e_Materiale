import pandas as pd
from sklearn.metrics import accuracy_score, classification_report, log_loss
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
import time

# https://www.kaggle.com/datasets/fedesoriano/stellar-classification-dataset-sdss17
df = pd.read_csv('star_classification.csv')


# ---------------------------------------------------- FEATURE ENGINEERING
df = df.rename(columns={
        'u': 'ultraviolet filter',
        'g': 'green filter',
        'r': 'red filter',
        'i': 'near infrared filter',
        'z': 'infrared filter'
})

df.drop(columns=['obj_ID', 'run_ID', 'rerun_ID', 'cam_col', 'field_ID', 'spec_obj_ID', 'plate', 'MJD', 'fiber_ID'],
        inplace=True)

X = df.drop('class', axis=1)  # feature
y = df['class']               # target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=30)


# ---------------------------------------------------- KNN
start_time_knn = time.time()

model_knn = KNeighborsClassifier(n_neighbors=3)
model_knn.fit(X_train, y_train)
y_pred_knn = model_knn.predict(X_test)
y_pred_probs_knn = model_knn.predict_proba(X_test)

end_time_knn = time.time()

classification_rep_knn = classification_report(y_test, y_pred_knn)
print('KNN - Classification Report:\n', classification_rep_knn)
print('KNN - Cross Entropy:', log_loss(y_test, y_pred_probs_knn))
print('KNN - Training Time:', end_time_knn - start_time_knn, 'seconds\n')
print('-' * 50)


# ---------------------------------------------------- Decision Tree
start_time_dt = time.time()

model_dt = DecisionTreeClassifier()
model_dt.fit(X_train, y_train)
y_pred_dt = model_dt.predict(X_test)
y_pred_probs_dt = model_dt.predict_proba(X_test)

end_time_dt = time.time()

classification_rep_dt = classification_report(y_test, y_pred_dt)
print('Decision Tree - Classification Report:\n', classification_rep_dt)
print('Decision Tree - Cross Entropy:', log_loss(y_test, y_pred_probs_dt))
print('Decision Tree - Training Time:', end_time_dt - start_time_dt, 'seconds\n')
print('-' * 50)


# ---------------------------------------------------- Random Forest
start_time_rf = time.time()

model_rf = RandomForestClassifier(n_estimators=29, random_state=30)
model_rf.fit(X_train, y_train)
y_pred_rf = model_rf.predict(X_test)
y_pred_probs_rf = model_rf.predict_proba(X_test)

end_time_rf = time.time()

classification_rep_rf = classification_report(y_test, y_pred_rf)
print('Random Forest - Classification Report:\n', classification_rep_rf)
print('Random Forest - Cross Entropy:', log_loss(y_test, y_pred_probs_rf))
print('Random Forest - Training Time:', end_time_rf - start_time_rf, 'seconds\n')
print('-' * 50)


# ---------------------------------------------------- Prediction
new_data = pd.DataFrame({
        'alpha': [342],
        'delta': [20],
        'ultraviolet filter': [20],
        'green filter': [20],
        'red filter': [20],
        'near infrared filter': [20],
        'infrared filter': [20],
        'redshift': [1.30]
})  # Simile ad un QSO

print("Predizione su nuovi dati:")
print("KNN:", model_knn.predict(new_data)[0])
print("DECISION TREE:", model_dt.predict(new_data)[0])
print("RANDOM FOREST:", model_rf.predict(new_data)[0])

