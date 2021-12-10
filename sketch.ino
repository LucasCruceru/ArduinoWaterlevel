#define Power1 6
#define Pin1 A0
#define Power2 7
#define Pin2 A1
#define Power3 8
#define Pin3 A2
#define Power4 9
#define Pin4 A3

int power[4] = {Power1, Power2, Power3, Power4};
int pin[4] = {Pin1, Pin2, Pin3, Pin4};


int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LEDup = 5;
int lowLED = 10;

void setup() {

  pinMode(Power1, OUTPUT); // Sensor 1
  digitalWrite(Power1, LOW);
  pinMode(Power2, OUTPUT); // Sensor 2
  digitalWrite(Power2, LOW);
  pinMode(Power3, OUTPUT); // Sensor 3
  digitalWrite(Power3, LOW);
  pinMode(Power4, OUTPUT); // Sensor 4
  digitalWrite(Power4, LOW);

  pinMode(lowLED, OUTPUT); // LED-ul 1
  digitalWrite(lowLED, LOW);
  pinMode(LED1, OUTPUT); // LED-ul 2
  digitalWrite(LED1, LOW);
  pinMode(LED2, OUTPUT); // LED-ul 3
  digitalWrite(LED2, LOW);
  pinMode(LED3, OUTPUT); // LED-ul 4
  digitalWrite(LED3, LOW);
   pinMode(LEDup, OUTPUT); // LED-ul 5
  digitalWrite(LEDup, LOW);

  Serial.begin(9600);
}

void loop() {

int waterLevel = 0;

    for (int i = 0; i < 4; i++) {
        int level = readSensor(power[i], pin[i]);
        if (level > 150){
            waterLevel = waterLevel + 1;
        }
    }
	
    switch (waterLevel) {
        case 0:
        Serial.println("Nivel apa: Empty");
        digitalWrite(lowLED, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LEDup, LOW);
        break;
        
        case 1:
        Serial.println("Nivel apa: 1");
        digitalWrite(lowLED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LEDup, LOW);
        break;
        
        case 2:
        Serial.println("Nivel apa: 2");
        digitalWrite(lowLED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LEDup, LOW);
        break;
        
        case 3:
        Serial.println("Nivel apa: 3");
        digitalWrite(lowLED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LEDup, LOW);
        break;
        
        case 4:
        Serial.println("Nivel apa: 4");
        digitalWrite(lowLED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LEDup, HIGH);
        break;
    }

  delay(1000);
}


int readSensor(int power, int pin){
  int val = 0;
  digitalWrite(power, HIGH);
  delay(10);
  val = analogRead(pin);
  digitalWrite(power, LOW);
  return val;
}
