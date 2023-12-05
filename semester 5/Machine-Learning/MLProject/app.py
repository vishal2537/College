import pandas as pd
from flask import Flask, render_template, request, jsonify
import numpy as np
import joblib
# import os
app = Flask(__name__)

# model_path = os.path.abspath('./model/premium_prediction_model.pkl')
# model_load = joblib.load(model_path)
model_load = joblib.load('./model/premium_prediction_model.pkl')
# model_load = joblib.load("C:\\Users\\Lenovo\\Desktop\\college1\\Labs\\semester 5\\Machine Learning\\mp\\model\\premium_prediction_model.pkl")

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    if request.method == 'POST':
        age = int(request.form['age'])
        bmi = float(request.form['bmi'])
        children = int(request.form['children'])
        gender = int(request.form['gender'])
        smoker = int(request.form['smoker'])
        region = request.form['region']
        r1=0
        r2=0
        r3=0
        r4=0
        if region == 'northeast':
            r1 =1
        if region == 'northwest':
            r2 =1
        if region == 'southeast':
            r3 =1
        if region == 'southwest':
            r4 =1
        
        print(f"Age: {age}, BMI: {bmi}, Children: {children}, Gender: {gender}, Smoker: {smoker}, Region: {region}")
        input_val = [age,
                     gender,    
                     bmi,
                     children,
                     smoker,
                     r1,
                     r2,
                     r3,r4]
        final_features = [np.array(input_val)]
        df = pd.DataFrame(final_features)

        output = model_load.predict(df)        
        return render_template('index.html', prediction_text=f'Predicted Health Insurance Premium is  {abs(output)} ')
    else:
        return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True,port=3000)