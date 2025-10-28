from flask import Flask, render_template, jsonify
import serial
import time
import random

# Tente conectar ao Arduino
try:
    arduino = serial.Serial('COM4', 9600, timeout=1)
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com Arduino: {e}")
    arduino = None

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/get_data')
def get_data():
    try:
        if arduino:
            arduino.write(b'L')  # comando opcional
            time.sleep(0.5)
            linha = arduino.readline().decode().strip()

            if not linha:
                return jsonify({"error": "Sem dados do Arduino"})

            if "Erro" in linha:
                return jsonify({"error": "Falha na leitura do sensor"})

            try:
                temp, umid = linha.split(',')
                temperatura = float(temp)
                umidade = float(umid)
            except ValueError:
                return jsonify({"error": "Dados inválidos"})
        else:
            # Simula se não houver Arduino
            temperatura = random.uniform(20, 40)
            umidade = random.uniform(40, 70)

        return jsonify({
            "temperatura": round(temperatura, 1),
            "umidade": round(umidade, 1)
        })

    except Exception as e:
        return jsonify({"error": str(e)})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)
