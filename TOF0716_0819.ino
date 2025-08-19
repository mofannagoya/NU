#include "arduino_secrets.h"

#include <Arduino.h>


//ââDeep Sleepã®æéââ

unsigned long interval_day = 1200;  // unit:sec 280=5å

unsigned long interval_night = 1200;  // unit:sec 3600=1æé

// Deep Sleep å¤éã¯ã¤ã³ã¿ã¼ãã«ãé·ããã¦ç¯é»

int morning = 5;

int evening = 19;




//ââãµã¤ãå ã§ è¨é²ãã¡ã¤ã«åãè¨­å®ãä»¥ä¸ã®çªå·ï¼æ¥ä» ï¼2_2-718.csv)ã«ãªãââ

String site = "NU_oneday";

String plot = "new";  //ãµã¤ãçªå·ããã¡ã¤ã«åãªã©ã«åæ 

String no = "2";  //ãµã¤ãä¸­ã®å ´æçªå·ããã¡ã¤ã«åãªã©ã«åæ 


String site_code = site + "_" + String(plot) + "_" + String(no);  //ä¿å­ãã¡ã¤ã«åãã¤ãµã¤ãã³ã¼ããå¥ããç®±

String file_name = "/" + site + "_" + String(plot) + String(no) + ".csv";  //esp32ã ã¨ãã¡ã¤ã«ååã«"/"ãå¿è¦




unsigned long WIFI_TIMEOUT_MS = 30000;  // Wi-Fiæ¥ç¶ã¿ã¤ã ã¢ã¦ãæé (30ç§)




//â ã»ã³ãµã¼ã¸ã®é»æºä¾çµ¦9â 

int sensorVdd = 21;  //C3 21 C6 16 S3 43


//â LCD & RTCâ 

#include <Wire.h>


//â WIFIâ 

#include <WiFi.h>

#include <WiFiMulti.h>

WiFiMulti wifiMulti;

#include <WiFiClientSecure.h>

WiFiClientSecure client;  //ã¤ã³ã¹ã¿ã³ã¹çæ

WiFiServer server(80);




//ã©ãWIFIã®SSID & password

char* SSID;

char* Password;

String SSID_used;


char* SSID1 = "aterm-a02637";
char* Password1 = "4f0df062cd6d0";
char* SSID2 = "Buffalo-G-D100";
char* Password2 = "fs8v8xr787kkc";
char* SSID3 = "Buffalo-A-D100";
char* Password3 = "fs8v8xr787kkc";
const char* SSID4 = "Buffalo-G-CB80";
const char* Password4 = "absxfsxf6r53h";
const char* SSID5 = "Buffalo-G-C22E";
const char* Password5 = "5dbev3efsfnxv";


//char* SSID3 = "HUAWEI_Joetsu";

//char* Password3 = "joetsu2023";




//const char* SSID = "Buffalo-G-C22E";

//const char* Password = "5dbev3efsfnxv";


int counter;  //æ¥ç¶ã®è©¦è¡åæ°

int counter_max = 10;  //æ¥ç¶ã®æå¤§è©¦è¡åæ°

int wifi2 = 0;


//Server

const char* Server = "script.google.com";

//è¨¼ææ¸

const char* Certificate = "";


//DeployID

//ãã³ãã­ã¡ã¼ã¿ã¼

const String URL_app = "https://script.google.com/macros/s/AKfycbyfleyJVT-Mmydqkjf72JtxVrhzhMd1TJCyNZA7spRX6w4n9f5yBns-KPFWul0iIJvG/exec";

//ãã¼ã¿ãå«ããURLãå¥ããç®±

String URL_Data;

//éå§æéãå¥ããç®±

unsigned long Timer_Start;

//ç¾å¨æéãå¥ããç®±

unsigned long Timer_Now;


//â â â SDã«ã¼ãæ¸ãè¾¼ã¿ã®æºåâ â â ã©ã¤ãã©ãªä½¿ç¨ã®ããã®å®£è¨

//#include <FS.h>

#include <SPI.h>  //ãããããã©ã«ãã§å¥ã£ã¦ãããã

#include <SD.h>  //https://www.arduinolibraries.info/libraries/sd

// Arduino UNOã§ã¯10ãArduino MEGAã§ã¯53, ESPXIAOã§ã¯"4"

const int cs = 4;


//âââTimeré¢é£âââ

struct tm timeInfo;  //æå»ãæ ¼ç´ãããªãã¸ã§ã¯ã

char sss[20];  //æå­æ ¼ç´ç¨


long YEAR = timeInfo.tm_year + 1900;  //ç¾å¨æå»ã®åãåå¾ããããã«å¹´ææ¥æéåãä½¿ã

long MONTH = timeInfo.tm_mon + 1;

long DAY = timeInfo.tm_mday;

long HOUR = timeInfo.tm_hour;

long MIN = timeInfo.tm_min;

long SEC = timeInfo.tm_sec;








#include "Wire.h"




const int numValues = 13;

float values[numValues];




int k;


//â â â TCA9548Aâ â â 

#define TCAADDR 0x70


#include <VL53L0X.h>

//#include "DFRobot_VL53L0X.h"

VL53L0X sensor_0 = VL53L0X();

VL53L0X sensor_1 = VL53L0X();

VL53L0X sensor_2 = VL53L0X();

VL53L0X sensor_3 = VL53L0X();

VL53L0X sensor_4 = VL53L0X();

VL53L0X sensor_5 = VL53L0X();

VL53L0X sensor_6 = VL53L0X();

VL53L0X sensor_7 = VL53L0X();


float instant_0 = 0;

float instant_1 = 0;

float instant_2 = 0;

float instant_3 = 0;

float instant_4 = 0;

float instant_5 = 0;

float instant_6 = 0;

float instant_7 = 0;


int validCount = 0;


//â â Helper function for changing TCA output channel

void tcaselect(uint8_t channel) {

  if (channel > 7) return;

  Wire.beginTransmission(TCAADDR);

  Wire.write(1 << channel);

  Wire.endTransmission();
}




void setup() {


  //initialize serial communication at 9600 bits per second:

  Serial.begin(115200);

  //join i2c bus (address optional for master)

  Wire.begin();

  //â åºåãã³ã®è¨­å®â 

  //pinMode(sensorVdd, OUTPUT);

  /*

  //Set I2C sub-device address

  sensor.begin(0x50);


  //Set to Back-to-back mode and high precision mode   eContinuous or eSingle

  sensor.setMode(sensor.eContinuous, sensor.eHigh);

  

  //Laser rangefinder begins to work

  sensor.start();

  */


  //eSingleã¯ãã®ã¾ã¾ãåçºæ¸¬å®ãeContinuousã¯ãStop()ãããã¾ã§ãæ¸¬å®ãç¶ãã¦ãã¾ã


  //â æè¨ã®æºåâ 

  configTime(3600 * 9, 0, "ntp.nict.jp", "time.google.com", "ntp.jst.mfeed.ad.jp");


  //â åºåãã³ã®è¨­å®â 

  pinMode(sensorVdd, OUTPUT);


  Connect_WiFi0();



  Timer_Now = millis();  //ç¾å¨æå»æ´æ°


  //â â â WIFIããã®æéåå¾â â â 

  getLocalTime(&timeInfo);  //tmãªãã¸ã§ã¯ãã®timeInfoã«ç¾å¨æå»ãå¥ãè¾¼ã

  sprintf(sss, "%04d/%02d/%02d %02d:%02d:%02d",

          timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday,

          timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);  //äººéãèª­ããå½¢å¼ã«å¤æ

  delay(1000);

  Serial.println(sss);  //æéãã·ãªã¢ã«ã¢ãã¿ã¸åºå


  YEAR = timeInfo.tm_year + 1900;  //ç¾å¨æå»ã®åãåå¾ããããã«å¹´ææ¥æéåãä½¿ã

  MONTH = timeInfo.tm_mon + 1;

  HOUR = timeInfo.tm_hour;

  DAY = timeInfo.tm_mday;

  MIN = timeInfo.tm_min;

  SEC = timeInfo.tm_sec;








  //â â â ãã¼ã¿åå¾â â â 

  //â²â²â²é»æºONâ²â²â²

  digitalWrite(sensorVdd, HIGH);

  delay(500);

  ToF_measurement();

  //â²â²â²é»æºOFFâ²â²â²

  digitalWrite(sensorVdd, LOW);


  //â â â ãã¼ã¿éä¿¡ã¨SD_CARDè¨é²â â â 

  Spreadsheet();

  // WiFi Disconnect

  WiFi.disconnect(true);

  Serial.printf("WiFi disconnected\n");


  // Deep Sleep å¤éã¯ã¤ã³ã¿ã¼ãã«ãé·ããã¦ç¯é»

  if ((HOUR >= 0 && HOUR < morning) || (HOUR >= evening && HOUR < 24)) {

    esp_sleep_enable_timer_wakeup(interval_night * 1000 * 1000);  //ãÎ¼Secãªã®ã§ã1000*1000æãã


  } else {

    esp_sleep_enable_timer_wakeup(interval_day * 1000 * 1000);  //ãÎ¼Secãªã®ã§ã1000*1000æãã
  }

  esp_deep_sleep_start();
}


void loop() {
}








void ToF_measurement() {

  validCount = 0;

  tcaselect(0);

  sensor_0.setTimeout(500);

  sensor_0.init();

  sensor_0.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_0.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_0 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_0 = instant_0 / validCount;

  delay(50);


  validCount = 0;

  tcaselect(1);

  sensor_1.setTimeout(500);

  sensor_1.init();

  sensor_1.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_1.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_1 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_1 = instant_1 / validCount;

  delay(50);




  validCount = 0;

  tcaselect(2);

  sensor_2.setTimeout(500);

  sensor_2.init();

  sensor_2.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_2.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_2 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_2 = instant_2 / validCount;

  delay(50);


  validCount = 0;

  tcaselect(3);

  sensor_3.setTimeout(500);

  sensor_3.init();

  sensor_3.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_3.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_3 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_3 = instant_3 / validCount;

  delay(50);


  validCount = 0;

  tcaselect(4);

  sensor_4.setTimeout(500);

  sensor_4.init();

  sensor_4.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_4.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_4 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_4 = instant_4 / validCount;

  delay(50);


  validCount = 0;

  tcaselect(5);

  sensor_5.setTimeout(500);

  sensor_5.init();

  sensor_5.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_5.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_5 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_5 = instant_5 / validCount;

  delay(50);


  validCount = 0;

  tcaselect(6);

  sensor_6.setTimeout(500);

  sensor_6.init();

  sensor_6.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_6.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_6 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_6 = instant_6 / validCount;

  delay(50);




  validCount = 0;

  tcaselect(7);

  sensor_7.setTimeout(500);

  sensor_7.init();

  sensor_7.setMeasurementTimingBudget(200000);

  delay(100);


  for (int i = 0; i < numValues; ++i) {

    // è·é¢ãæ¸¬å®ããä¸æçãªå¤æ°ã«æ ¼ç´

    float measuredDistance = sensor_7.readRangeSingleMillimeters();


    // æ¸¬å®å¤ã20ããå¤§ããããã§ãã¯

    if (measuredDistance > 20) {

      // 20ããå¤§ããå ´åã®ã¿åè¨ã«å ç®

      instant_7 += measuredDistance;

      // æå¹ãªæ¸¬å®åæ°ãã«ã¦ã³ãã¢ãã

      validCount++;
    }

    // æ¬¡ã®æ¸¬å®ã¾ã§ã®å¾æ©æé

    delay(50);
  };

  instant_7 = instant_7 / validCount;

  delay(50);




  // çµæãåºå

  Serial.print("Instant: ");

  Serial.print(instant_0);

  Serial.print("\t");

  Serial.print(instant_1);

  Serial.print("\t");

  Serial.print(instant_2);

  Serial.print("\t");

  Serial.print(instant_3);

  Serial.print("\t");

  Serial.print(instant_4);

  Serial.print("\t");

  Serial.print(instant_5);

  Serial.print("\t");

  Serial.print(instant_6);

  Serial.print("\t");

  Serial.println(instant_7);
}


void Spreadsheet() {

  //âââURLã«éä¿¡ãã¼ã¿ãæ·»ä»âââ

  URL_Data = URL_app + "?";

  URL_Data += "&1_cell=";

  URL_Data += site_code;

  URL_Data += "&2_cell=";

  URL_Data += instant_0;

  URL_Data += "&3_cell=";

  URL_Data += instant_1;

  URL_Data += "&4_cell=";

  URL_Data += instant_2;

  URL_Data += "&5_cell=";

  URL_Data += instant_3;

  URL_Data += "&6_cell=";

  URL_Data += instant_4;

  URL_Data += "&7_cell=";

  URL_Data += instant_5;

  URL_Data += "&8_cell=";

  URL_Data += instant_6;

  URL_Data += "&9_cell=";

  URL_Data += instant_7;

  /*

  URL_Data += "&10_cell=";

  URL_Data += XXX;

  URL_Data += "&11_cell=";

  URL_Data += XXX;

  URL_Data += "&12_cell=";

  URL_Data += XXX;

  URL_Data += "&13_cell=";

  URL_Data += XXX;

  URL_Data += "&14_cell=";

  URL_Data += XXX;

  URL_Data += "&15_cell=";

  URL_Data += XXX;

  URL_Data += "&16_cell=";

  URL_Data += XXX;

  */

  //âââãµã¼ãã¼ã«æ¥ç¶ï½ãã¼ã¿éä¿¡âââ

  client.setInsecure();  //è¨¼ææ¸åé¿

  if (!client.connect(Server, 443))  //ãµã¼ãã¼ã«æ¥ç¶ã§ããªãã£ãæ

  {

    Serial.print("Could not connect: ");


    /*åæ¥ç¶-----------------------------------------*/

    Serial.print("Reconnect?: ");

    //WiFi.mode(WIFI_OFF);    //WiFiåæ­ã¯ãã®å¾ã®Connect_WIFIä¸­ã«ããã®ã§ã«ãã

    WiFi.disconnect(true);  //<--- this is important! ããããããªãã¨åæ¥ç¶ã§ããªãå¯è½æ§é«ãï¼


    //â WiFiåæ¥ç¶â 





    Connect_WiFi0();



    WiFi.disconnect(true);  //<--- this is important! ããããããªãã¨åæ¥ç¶ã§ããªãå¯è½æ§é«ãï¼

    ESP.restart();  //ããã§ããã¡ãªãRestart? ãããDeepSleepããªãã¨å»¶ãã¨é»åæ¶è²»??


  } else {

    client.println("GET " + URL_Data);  //è¦ç¢ºèª

    delay(1000);  //å¾ã¡æéãå¥ããªãã¨ãã¼ã¿ãéããªããã¨ããã

    client.stop();


    Serial.print("Data sent!: ");

    Serial.println("");  //æ¹è¡
  }
}






//âââæ®éã®WIFIæ¥ç¶KAI ã WiFi Multiã«âââ

void Connect_WiFi0() {

  WiFi.mode(WIFI_STA);


  wifiMulti.addAP(SSID1, Password1);

  wifiMulti.addAP(SSID2, Password2);

  wifiMulti.addAP(SSID3, Password3);

  wifiMulti.addAP(SSID4, Password4);

  wifiMulti.addAP(SSID5, Password5);


  Serial.println("Connecting WifiMulti...");

  if (wifiMulti.run(WIFI_TIMEOUT_MS) == WL_CONNECTED) {

    if (wifiMulti.run() == WL_CONNECTED) {

      Serial.println("");

      Serial.println("WiFi connected");

      Serial.println("IP address: ");

      Serial.println(WiFi.localIP());

      Serial.println(WiFi.SSID());


      SSID_used = WiFi.SSID();
    }

    Serial.print("WiFi connected:");

    Serial.print("IP:");

    Serial.println(WiFi.localIP());  //IPã¢ãã¬ã¹è¡¨ç¤º

  } else {

    Serial.println("Wi-Fi connection failed!");
  }
}
