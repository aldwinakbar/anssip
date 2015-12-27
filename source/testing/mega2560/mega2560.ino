#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN		5		
#define SS_PIN		53		
#define SERVER_IP       "192.168.1.5"
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
  
  Serial.begin(115200);	
  Serial1.begin(115200);
  while (!Serial);		
  SPI.begin();			
  mfrc522.PCD_Init();	
  Serial.print("Selamat Datang\n");  
  Serial.print("Tap kartu di sini\n");  
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
                
                        Serial.print("Selamat Datang\n");  
                        Serial.println(uid_string);
                        Serial.print("Tekan tombol\n");  
                        Serial.println("untuk izin");
                             
                        uidSend(uid_string,"login");    
                        Serial.println("Send Complete");  
                 
                        while (1) {
                          	    
                            frs_state = digitalRead(frs_pin);
                            button_state = digitalRead(button_pin);
                            
                            if (!button_state && out_state == 0){
                               Serial.println("izin keluar");
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
                                    Serial.println("izin masuk");
                                    uidSend(uid_string,"tempin");
                                    out_state = 0;
                                    delay(2000);
                                 
                                 }
                                 
                                 else if(out_state == 0 && uid_string == temp_uid_string){
                                    Serial.println("Logout");
                                    uidSend(uid_string,"logout");
                                    break;                          
                                 }
                                 
                                 else {
                                    Serial.println("ID Card not the same");
                                    delay(2000);
                                 }
                                                                          
                               }
                            }
                        }
                        
                        delay(3000);      
                        Serial.print("Selamat Datang\n");  
                        Serial.print("Tap kartu di sini\n");  
        	}
        }
}

void receiveWifiData(){
  
   if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);   
   }
}

void serialWifiSearch(char* search, int delay_time){
 delay(delay_time);
 if(Serial1.find(search)){
   Serial.print(search);
   Serial.print(" found."); 
 } 
 else {
   Serial.print(search);
   Serial.print(" not found."); 
 }
}

void connectTCP(const char *host, const char * port) {
  
  String command;
  command = "AT+CIPSTART=\"TCP\",\"";
  command += host;
  command += "\",";
  command += port;
  Serial1.println(command);
}

void sendData(String command) {
  
  Serial1.print("AT+CIPSEND=");
  Serial1.println(command.length());
  if(Serial1.find(">")){
  //  Serial.print("\n> ");
  //  Serial.println(command);
  }
  
  else{
    Serial.println("connect timeout");
    return;
  }
  Serial1.print(command);
}

void closeTCP(void) {
  Serial1.println("AT+CIPCLOSE");  
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
