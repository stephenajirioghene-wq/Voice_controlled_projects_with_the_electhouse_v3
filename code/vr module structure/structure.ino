#include <SoftwareSerial.h>

#include <VoiceRecognitionV3.h>

VR myVR(5,3);  // RX, TX 
#define pin 2    
volatile bool buttonPressed = false;

uint8_t buf[64]; 

class VRTrainer {
  public:
    VRTrainer(VR &vr) : vr(vr), nextPairIndex(0) {}

    void trainNextPair() {
      const uint8_t maxPairs_ = 3;
      if (nextPairIndex >= maxPairs_){
        Serial.println("All pairs trained");
        reset();
        return;
      }


      uint8_t base = nextPairIndex * 2;
      uint8_t slotOn  = base;
      uint8_t slotOff = base + 1;

      Serial.print("Training on in slot "); Serial.println(slotOn);
      delay(500);
      int retOn = vr.train(slotOn, buf);
      handleTrainResult(retOn);

      Serial.print("Training OFF in slot "); Serial.println(slotOff);
      delay(500);
      int retOff = vr.train(slotOff, buf);
      handleTrainResult(retOff);

      uint8_t records[6];
      for (uint8_t i = 0; i <= slotOff; i++){
        records[i] = i;
      }
      if (vr.load(records, slotOff + 1) == 0) {
        Serial.println("Pair loaded successfully");
        Serial.println("Listening...");
      } else {
        Serial.println("Load failed");
      }

      nextPairIndex++;
    }
      bool hasMorePairs() {
      return nextPairIndex < 3;}

     void reset() {
       nextPairIndex = 0;
 
                         }
  private:
    VR &vr;
    uint8_t nextPairIndex;

    void handleTrainResult(int result) {
      if (result >= 0) {
        Serial.println("Training successful.");
      } else if (result == -1) {
        Serial.println("Training failed.");
      } else if (result == -2) {
        Serial.println("Training timeout.");
      }
    }
};

VRTrainer trainer(myVR);
 

void setup() {
  Serial.begin(115200);
  myVR.begin(9600);
  if (myVR.clear() <= 0) {
    Serial.println("VR Module ready");
    myVR.clear();
  } else {
    Serial.println("VR Module not detected");
    while (1);
  }

  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), buttonISR, FALLING);

  Serial.println("Setup complete. Press button to train ON/OFF.");
  Serial.println("Listening");
}

 void loop() {
  if (buttonPressed) {
    buttonPressed = false;
    trainer.trainNextPair(); 
  }
  else{
  output();}
    
}
    
  
void buttonISR() {
  static unsigned long lastPress = 0;
  unsigned long now = millis();
  if (now - lastPress > 250) { 
    buttonPressed = true;
    lastPress = now;
  }
}


void output() {
  int ret = myVR.recognize(buf, 50);

  if (ret > 0) { 
    uint8_t slot = buf[1]; 

    if (slot % 2 == 0) {
      
      Serial.println("Device turned ON");
      // digitalWrite(RELAY_PIN, HIGH);
    } 
    else {
      
      Serial.println("Device turned OFF");
      // digitalWrite(RELAY_PIN, LOW);
    }
  }
}

