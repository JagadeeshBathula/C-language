### 🚑 Project Title:

# Automatic Traffic Signal Control for Ambulance Emergency Using Sound Detection

### 🎯 Objective:

To automatically detect an ambulance siren and change the traffic signal to green to provide a clear path, reducing delay and ensuring faster emergency response.

### 🔧 Concept Overview:

This project uses a sound sensor module connected to an Arduino Uno to detect the presence of an ambulance siren. Once the siren is detected (based on sound level or frequency), the Arduino:

Activates a green traffic light for a set period (e.g., 5 minutes).

Ensures that other lanes remain red, allowing only the ambulance to pass safely.

### 📦 Components Used:

Component	Purpose

Arduino Uno	Central controller for logic and timing

Sound sensor (KY-037 / KY-038)	Detects siren sound from ambulance

LEDs (Red, Yellow, Green)	Simulate traffic lights

220Ω Resistors	Limit current to LEDs

Jumper Wires + Breadboard	Circuit connections

### ⚙️ Working Principle:

The sound sensor continuously monitors the ambient sound level using its analog output (AO).

When a sound exceeding a predefined threshold (set to detect ambulance siren level) is captured, the Arduino:

Turns the green LED ON (simulating green traffic signal).

Turns red LEDs OFF (simulating stop signal for other lanes).

Keeps the green light ON for a fixed duration (5 minutes).

After 5 minutes, the system returns to normal by:

Turning the green LED OFF.

Optionally, resuming normal traffic light cycles (extendable logic).

### ✅ How the Code Implements It:

Code Snippet:

if (soundLevel > SOUND_THRESHOLD && !ledIsOn)
{
    digitalWrite(LED_PIN, HIGH);   // Green light ON
    ledOnStart = millis();         // Start emergency timer
    ledIsOn = true;
}

Code Behavior:

SOUND_SENSOR_PIN: Connected to the microphone module’s analog output.

LED_PIN: Connected to the green light output.

When the ambulance siren is detected:

The LED simulating green traffic light is turned ON.

It remains ON for 5 minutes (adjustable).

After 5 minutes:

The green light is turned OFF, returning to normal.

### 🔬 Real-World Enhancement Ideas:

Use multiple traffic signal LEDs (Red, Yellow, Green) on different directions.

Add frequency detection (via FFT) to confirm it is actually a siren, not just loud noise.

Add RFID or GPS modules to detect ambulances more accurately.

Interface with smart city infrastructure to sync multiple signals.

🧠 Conclusion:

This Arduino-based sound detection system provides a low-cost, efficient solution to:

Detect ambulance sirens.

Automatically change the traffic signal to green.

Improve emergency vehicle mobility and reduce response time.

It’s a great foundation for more advanced intelligent traffic systems using IoT and AI.

## Explanation Video


