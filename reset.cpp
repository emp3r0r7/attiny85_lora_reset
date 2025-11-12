#define OPTO_PIN 0  // pin collegato all'anodo del PC817
#define LED_PIN 1

void setup() {
  pinMode(OPTO_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(OPTO_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Simulazione di pressione pulsante
  digitalWrite(OPTO_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(300); // durata pressione in millisecondi

  // Release pulsante
  digitalWrite(OPTO_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // Attesa tra un reset ed un altro
  delay(43200000); // 12 ore , modifica come vuoi!
}
