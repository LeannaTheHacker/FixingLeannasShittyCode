const int intervalDelay = 500;
int intervalCounter = 0;

const int pedestrianButton = 2;
bool isPedestrianButtonClicked = false;

void setup() {
    pinMode(pedestrianButton, INPUT);
}

void loop() {
    if(digitalRead(pedestrianButton) == HIGH) {
        isPedestrianButtonClicked = true;
    }

    // If intervalCounter is within (inclusive) 0 to 2:
    // -> Turn off LED5 (Yellow Light)
    // -> Turn on all red lights.
    if(0 <= intervalCounter && intervalCounter <= 2) {
        digitalWrite(LED5, LOW);
        digitalWrite(LED4, HIGH);

        digitalWrite(LED1, HIGH);
        digitalWrite(LED7, HIGH);
    }

    // If intervalCounter is within (inclusive) 3 to 6:
    // -> Turn off LED1, LED7
    // -> Turn on LED3, LED9
    // -> If pedestrian light was clicked:
    // -> -> Turn on LED10
    // -> -> Turn off LED11
    // -> Else:
    // -> -> Turn on LED11
    // -> -> Turn off LED10
    if(3 <= intervalCounter && intervalCounter <= 6) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED7, LOW);

        digitalWrite(LED3, HIGH);
        digitalWrite(LED9, HIGH);

        if(isPedestrianButtonClicked) { 
            digitalWrite(LED10, HIGH);
            digitalWrite(LED11, LOW);
        }
        else { 
            digitalWrite(LED10, LOW);
            digitalWrite(LED11, HIGH); 
        }
    }

    // If intervalCounter is within (inclusive) 7 to 8
    // -> Turn off LED3, LED9 (Green Lights)
    // -> Turn on LED2, LED8 (Yellow Ligths)
    if(7 <= intervalCounter && intervalCounter <= 8) {
        isPedestrianButtonClicked = false;
        digitalWrite(LED3, LOW);
        digitalWrite(LED9, LOW);
        digitalWrite(LED10, LOW);
        
        digitalWrite(LED2, HIGH);
        digitalWrite(LED8, HIGH);
        digitalWrite(LED11, HIGH); 
    }

    // If intervalCounter is within (inclusive) 9 to 15 
    // -> Turn off LED2, LED8 (Yellow Lights)
    // -> Turn on LED1, LED7 (Red Lights)
    if(9 <= intervalCounter && intervalCounter <= 15) {
        digitalWrite(LED2, LOW);
        digitalWrite(LED8, LOW);

        digitalWrite(LED1, HIGH);
        digitalWrite(LED7, HIGH);
    }

    // If intervalCounter is within (inclusive) 16 to 19
    // -> Turn off LED4 (Red Light)
    // -> Turn on LED6 (Green Light)
    if(16 <= intervalCounter && intervalCounter <= 19) {
        digitalWrite(LED4, LOW);
        digitalWrite(LED6, HIGH);
    }

    // If intervalCounter is within (inclusive) 19 to 21
    // -> Turn off LED6 (Green Light)
    // -> Turn on LED5 (Yellow Light)
    if(19 <= intervalCounter && intervalCounter <= 21) {
        digitalWrite(LED6, LOW);
        digitalWrite(LED5, HIGH);
    }

    // Reset Loop
    if(intervalCounter > 21) {
        intervalCounter = 0;
    }
    
    // Interval counter
    intervalCounter = intervalCounter + 1;
    delay(intervalDelay);
}
