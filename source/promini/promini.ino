#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C	lcd(0x20,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

#define RST_PIN		9		
#define SS_PIN		10		
#define SERVER_IP       "192.168.43.53  "
#define SERVER_PORT     "50002"
MFRC522 mfrc522(SS_PIN, RST_PIN);

int uid_size;
int uid_data;
int frs_pin = 9;
int button_pin = 8;
int frs_state;
int button_state;
int out_state;

void setup() {
  
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  
  Serial.begin(115200);	
  while (!Serial);		
  SPI.begin();			
  mfrc522.PCD_Init();	
  lcd.setCursor (0,0);
  lcd.print(" Selamat Datang");
  lcd.setCursor (0,1);  
  lcd.print("Tap kartu disini");  
  pinMode(8,INPUT);
  pinMode(9,INPUT);
}

void loop() {
        frs_state = digitalRead(frs_pin);
	if (mfrc522.PICC_IsNewCardPresent() && !frs_state) {
        	if (mfrc522.PICC_ReadCardSerial() && !frs_state) {
                        
                        String uid_string;
                        uid_size = mfrc522.PICC_DumpUIDSize(&(mfrc522.uid));
                	for (byte i = 0; i < uid_size; i++) {
                                
                                uid_data = mfrc522.PICC_DumpUID(&(mfrc522.uid),i);
                		if(uid_data < 0x10)
                			uid_string+="0";
                
                       		uid_string+= String(uid_data, HEX);
                	} 
                         
                        lcd.clear();
                        lcd.print(" Selamat Datang");
                        lcd.setCursor (0,1);  
                        lcd.print("    ");
                        lcd.print(uid_string);

                        uidSend(uid_string,"login");    
                 
                        while (1) {
                          	    
                            frs_state = digitalRead(frs_pin);
                            button_state = digitalRead(button_pin);
                            
                            if (!button_state && out_state == 0){
                               lcd.clear();
                               lcd.print("  User Meminta");
                               lcd.setCursor (0,1);  
                               lcd.print("  Izin  Keluar");
                               uidSend(uid_string,"tempout");
                               out_state = 1;
                            }
                                                        
                            if (mfrc522.PICC_IsNewCardPresent() && !frs_state) {
                               if (mfrc522.PICC_ReadCardSerial() && !frs_state) {
                                
                                String temp_uid_string; 
                                uid_size = mfrc522.PICC_DumpUIDSize(&(mfrc522.uid));
                	        for (byte i = 0; i < uid_size; i++) {
                                
                                  uid_data = mfrc522.PICC_DumpUID(&(mfrc522.uid),i);
                  		      if(uid_data < 0x10)
                  			temp_uid_string += "0";
                  
                         		temp_uid_string += String(uid_data, HEX);
                	        } 
                                 
                              
                                 
                                 if(out_state == 1 && uid_string == temp_uid_string){
                                    
                                    lcd.clear();
                                    lcd.print("   Izin Masuk");
                                    lcd.setCursor (0,1);  
                                    lcd.print("    Diterima  ");
                                    uidSend(uid_string,"tempin");
                                    out_state = 0;
                                    delay(2000);
                                    lcd.clear();
                                    lcd.print(" Selamat Datang");
                                    lcd.setCursor (0,1);  
                                    lcd.print("    ");
                                    lcd.print(uid_string);

                                 }
                                 
                                 else if(out_state == 0 && uid_string == temp_uid_string){
                                    lcd.clear();
                                    lcd.print("  Terima Kasih");
                                    lcd.setCursor (0,1);  
                                    lcd.print("  Tidak Tipsen");
                                    uidSend(uid_string,"logout");
                                    delay(2000);
                                    break;                          
                                 }
                                 
                                 else {
                                    lcd.clear();
                                    lcd.print("      Error     ");
                                    lcd.setCursor (0,1);  
                                    lcd.print(" ID Tidak Sesuai");
                                    delay(2000);                                    
                                 }
                                                                          
                               }
                            }
                        }
                        
                        delay(3000);      
                        lcd.setCursor (0,0);
                        lcd.print(" Selamat Datang");
                        lcd.setCursor (0,1);  
                        lcd.print("Tap kartu disini");  
        	}
        }
}


void connectTCP(const char *host, const char * port) {
  
  String command;
  command = "AT+CIPSTART=\"TCP\",\"";
  command += host;
  command += "\",";
  command += port;
  Serial.println(command);
}

void sendData(String command) {
  
  Serial.print("AT+CIPSEND=");
  Serial.println(command.length());
  if(Serial.find(">")){
  //  Serial.print("\n> ");
  //  Serial.println(command);
  }
  
  else{
    //Serial.println("connect timeout");
    return;
  }
  Serial.print(command);
}

void closeTCP(void) {
  Serial.println("AT+CIPCLOSE");  
}

void uidSend(String uid_string_input,String state_input){
  String uid_header;
  uid_header = "state=";
  uid_header += state_input;
  uid_header += "&uid=";
  uid_header += uid_string_input; 
  connectTCP(SERVER_IP,SERVER_PORT);
  delay(1000); 
  sendData(uid_header);
  delay(1000);
  closeTCP(); 
  
}
