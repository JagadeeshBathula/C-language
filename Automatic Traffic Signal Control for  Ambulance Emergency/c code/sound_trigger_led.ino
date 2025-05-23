
// --- Pin Definitions ---
const int SOUND_SENSOR_PIN = A0;  // Analog input from sound sensor (AO pin)
const int LED_PIN = 13;           // Digital output to LED

// --- Threshold for triggering sound (tune this) ---
const int SOUND_THRESHOLD = 600;  // You may need to adjust this

// --- Timing ---
const unsigned long DURATION_MS = 5UL * 60UL * 1000UL;  // 5 minutes in milliseconds
unsigned long ledOnStart = 0;
bool ledIsOn = false;

void setup() {
  pinMode(SOUND_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);     // Ensure LED is off initially
  Serial.begin(9600);             // Start serial monitor for debugging
}

void loop() {
  int soundLevel = analogRead(SOUND_SENSOR_PIN);
  Serial.println(soundLevel); // Optional: monitor sound level

  // If loud enough sound is detected and LED is off
  if (soundLevel > SOUND_THRESHOLD && !ledIsOn) {
    digitalWrite(LED_PIN, HIGH);
    ledOnStart = millis();   // Record the time LED turned on
    ledIsOn = true;
    Serial.println("LED ON");
  }

  // If LED is on, check if 5 minutes have passed
  if (ledIsOn && millis() - ledOnStart >= DURATION_MS) {
    digitalWrite(LED_PIN, LOW);
    ledIsOn = false;
    Serial.println("LED OFF (Timeout)");
  }

  delay(100); // Short delay to stabilize readings
}
