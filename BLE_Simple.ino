#include <BluetoothSerial.h>

BluetoothSerial BT;

void setup() {
  // put your setup code here, to run once:
  pinMode(14, OUTPUT);
  Serial.begin(115200);
  BT.begin("SussyTeeth"); //設定裝置名稱
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if (BTdata == "LED ON") digitalWrite(14, HIGH); 
    else if (BTdata == "LED OFF") digitalWrite(14, LOW); 
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
