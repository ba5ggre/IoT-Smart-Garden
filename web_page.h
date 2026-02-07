const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Smart Garden Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial; text-align: center; background-color: #f4f4f9; padding-top: 30px;}
    .card { background: white; padding: 15px; margin: 10px; border-radius: 12px; display: inline-block; width: 150px; box-shadow: 0 4px 6px rgba(0,0,0,0.1); }
    .slider { width: 80%; max-width: 400px; }
    h1 { color: #2e7d32; }
  </style>
</head>
<body>
  <h1>Smart Garden Dashboard</h1>
  <div class="card"><h3>Temp</h3><p>%TEMP% C</p></div>
  <div class="card"><h3>Humi</h3><p>%HUMI% %</p></div>
  <div class="card"><h3>Light</h3><p>%LIGHT%</p></div>
  <div class="card"><h3>TDS</h3><p>%TDS% ppm</p></div>
  <br><br>
  <h3>Manual Shield Control</h3>
  <input type="range" min="0" max="180" class="slider" value="%SERVO_POS%" oninput="updateServo(this.value)">
  <p>Angle: <span id="servoPos">%SERVO_POS%</span> deg</p>
  <script>
    function updateServo(val) {
      document.getElementById("servoPos").innerHTML = val;
      fetch("/servo?value=" + val);
    }
  </script>
</body>
</html>)rawliteral";