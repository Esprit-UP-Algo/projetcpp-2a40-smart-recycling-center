/*//Viral Science
//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "13 B1 6A A9" || content.substring(1) == "B3 04 74 A5") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
}//Viral Science
//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "13 B1 6A A9" || content.substring(1) == "B3 04 74 A5") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
}  
*/
/*

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Identifiants à stocker sur la carte RFID (exemple)
String login = "raed15";
String password=" ";


void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  // Vérifie si une carte est présente
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Obtient l'identifiant de la carte
    String cardID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardID += String(mfrc522.uid.uidByte[i], HEX);
    }
   
    // Affiche l'identifiant de la carte
    Serial.println("Carte RFID détectée : " + cardID);

    // Écrit les identifiants sur la carte
    MFRC522::MIFARE_Key key;
    for (byte i = 0; i < 6; i++) {
      key.keyByte[i] = 0xFF;
    }

    // Convertit les chaînes en tableau de caractères
    char loginChar[16];
    login.toCharArray(loginChar, 16);
   
    char passwordChar[16];
    password.toCharArray(passwordChar, 16);

    // Écrit les identifiants sur la carte
    mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid));
    mfrc522.MIFARE_Write(1, (byte*)loginChar, 16);
    mfrc522.MIFARE_Write(2, (byte*)passwordChar, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    Serial.println("Identifiants écrits sur la carte.");

    delay(5000); // Attendez 5 secondes avant de lire à nouveau la carte
  }
}*/
/*
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Lecture du contenu de la carte RFID. Approchez une carte...");
}

void loop() {
  // Vérifie si une carte est présente
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Obtient l'identifiant de la carte
    String cardID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardID += String(mfrc522.uid.uidByte[i], HEX);
    }

    Serial.println("Carte RFID détectée : " + cardID);

    // Lit le contenu de la carte
    MFRC522::MIFARE_Key key;
    for (byte i = 0; i < 6; i++) {
      key.keyByte[i] = 0xFF;
    }

    mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid));

    byte buffer[18];
    byte size = sizeof(buffer);

    // Lit les données de la carte
    if (mfrc522.MIFARE_Read(1, buffer, &size) == MFRC522::STATUS_OK) {
      Serial.println("Contenu de la carte : ");
      for (byte i = 0; i < 16; i++) {
        Serial.print((char)buffer[i]);
      }
      Serial.println();
    } else {
      Serial.println("Erreur de lecture des données de la carte.");
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    delay(5000); // Attendez 5 secondes avant de lire à nouveau la carte
  }
}
*/
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 4
#define LED_PIN2 5// Assurez-vous de connecter la LED à la broche 13 ou modifiez le numéro de broche en conséquence

MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);// Configure la broche de la LED comme sortie
  Serial.println("Approximate your card to the reader..");
  Serial.println();
 
 
}

void processCard(String uid)
{
  Serial.println("Card detected. UID: " + uid);
 // digitalWrite(LED_PIN, HIGH); // Allume la LED verte
  /*delay(2000); // Garde la LED allumée pendant 2 secondes (vous pouvez ajuster cette valeur)
  digitalWrite(LED_PIN, LOW); // Éteint la LED
  digitalWrite(LED_PIN2, HIGH); // Allume la LED verte
  delay(2000); // Garde la LED allumée pendant 2 secondes (vous pouvez ajuster cette valeur)
  digitalWrite(LED_PIN2, LOW); // Éteint la LED*/
}

void loop()
{
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.println("");
  Serial.println("UID tag :");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println(content.substring(1));
 if (content.substring(1) == "13 B1 6A A9" || content.substring(1) == "B3 04 74 A5") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_PIN, HIGH);
  //  tone(BUZZER, 500);
   // delay(300);
   // noTone(BUZZER);
   // myServo.write(180);
    delay(1000);
    //myServo.write(0);
    digitalWrite(LED_PIN, LOW);
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_PIN2, HIGH);
   // tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_PIN2, LOW);
   // noTone(BUZZER);
  }
  // Appel de la fonction pour traiter la carte détectée
  processCard(content.substring(1));
 
  delay(500);
}
