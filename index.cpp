/*

Mustafa "pxsty" kök tarafından eklendi --> github.com/pxsty0

Bu örnekte, Deneyap Kart istenilen pine bağlı olan USB to TTL adaptörü veya başka bir geliştirme kartıyla haberleşerek veri okuyup veri göndermektedir.
Bu örneği geliştirerek UART ile çalışan GPS modülleri, GSM modülleri gibi kartları da kullanabilirsiniz.

*/
#define EXTUART Serial1

#define EXT_BAUD 9600
#define EXT_TX D0 
#define EXT_RX D1

void setup() {
  Serial.begin(9600);
  EXTUART.begin(EXT_BAUD, SERIAL_8N1, EXT_RX, EXT_TX);
}

void loop() {
  
  if (EXTUART.available()) {
    Serial.write(EXTUART.read());
  }
  if (Serial.available()) {
    EXTUART.write(Serial.read());
  }

}
