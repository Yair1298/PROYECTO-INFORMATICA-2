import os
import google.generativeai as genai
from flask import Flask, request, jsonify

app = Flask(__name__)

# Configura Gemini con la variable de entorno que pondremos en Render
genai.configure(api_key=os.environ.get("GEMINI_API_KEY"))
model = genai.GenerativeModel('gemini-1.5-flash')

@app.route('/recomendaciones', methods=['POST'])
def recibir_datos():
    data = request.json
    temp = data.get('temperatura')
    ph = data.get('ph')
    
    prompt = f"Mi pez betta tiene agua a {temp}°C y pH {ph}. Dame 3 consejos breves y técnicos para un acuario."
    
    try:
        response = model.generate_content(prompt)
        return jsonify({"gemini": response.text}), 200
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=10000) # Puerto estándar de Render