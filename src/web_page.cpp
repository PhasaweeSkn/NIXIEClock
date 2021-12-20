// REFERRENCE: 
// https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
// https://randomnerdtutorials.com/esp32-web-server-spiffs-spi-flash-file-system/


/// Web INPUT ///
///////////////////////////////////////////////////////////////////////////
///////     SSID Name : Dropdown List  //////////////////////
///////     Pass : Text box Password   //////////////////////
///////////////////////////////////////////////////////////////////////////


#include "web_page.hpp"
/* Login page */
void webserver_init(){
String loginIndex;
String serverIndex;
String serverIndex_1;
String serverIndex_2;
String serverSubmit;

loginIndex =
  "<form name='loginForm'>"
  "<table width='20%' bgcolor='A09F9F' align='center'>"
  "<tr>"
  "<td colspan=2>"
  "<center><font size=4><b>ESP32 Login Page</b></font></center>"
  "<br>"
  "</td>"
  "<br>"
  "<br>"
  "</tr>"
  "<tr>"
  "<td>Username:</td>"
  "<td><input type='text' size=25 name='userid'><br></td>"
  "</tr>"
  "<br>"
  "<br>"
  "<tr>"
  "<td>Password:</td>"
  "<td><input type='Password' size=25 name='pwd'><br></td>"
  "<br>"
  "<br>"
  "</tr>"
  "<tr>"
  "<td><input type='submit' onclick='check(this.form)' value='Login'></td>"
  "</tr>"
  "</table>"
  "</form>"
  "<script>"
  "function check(form)"
  "{"
  "if(form.userid.value=='admin' && form.pwd.value=='admin')"
  "{"
  "window.open('/serverIndex')"
  "}"
  "else"
  "{"
  " alert('Error Password or Username')/*displays error message*/"
  "}"
  "}"
  "</script>";

/* Server Index Page */
serverIndex_1 =
  "<form method='POST' action='submit' enctype='multipart/form-data' id='SSID_form'>"
  "<table width=100% border='0' cellspacing='0' cellpadding='0'>"
  "<tr>"
  "<td align='center'>Selece SSID and Input Passphrase</td>"
  "</tr>"
  "</table>"
  "<table width=100% border='0' cellspacing='0' cellpadding='0'>"
  "<tr>"
  "<td>"
  "<label for='SSID_Name'>SSID Name : </label>"
  "<select id='SSID_Name' name='SSID_Name'>"
  ;
serverIndex_2 =
  "</select>"
  "</tr>"
  "<tr>"
  "<td>"
  "<label for='SSID_Passphrase'>Passphrase : </label>"
  "<input id='SSID_Passphrase' type='password' size='40' name='SSID_Passphrase'/></td>"
  "</tr>"
  "</table>"
  "<table width=100% border='0' cellspacing='0' cellpadding='0'>"
  "<tr>"
  "<td width=50% align='center'><input type='submit' value='Update'></td>"
  "<td width=50% align='center'><input type='reset' value='Clear'></td>"
  "</tr>"
  "</table>"
  "</form>"
  ;

  int n = WiFi.scanNetworks();
  String serverIndex_SSID_List = "<option value=''>Select SSID</option>";
  if (n == 0) {
    serverIndex_SSID_List = "<option value=''>SSID not found</option>";
  } else {
    //serverIndex_SSID_List = "<option value=''>Select SSID</option>";
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      serverIndex_SSID_List = serverIndex_SSID_List + "<option value='"+ WiFi.SSID(i) +"'>" + WiFi.SSID(i) + ((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?"":" *") + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[" + WiFi.RSSI(i) + "]</option>";
    }
  }
  
  serverIndex = serverIndex_1 + serverIndex_SSID_List + serverIndex_2;

/* Server Submit Result Page */

serverSubmit =
  "It Worked!!!!"
  ;

    server.on("/", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", loginIndex);
  });
  server.on("/serverIndex", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", serverIndex);
  });
  /*handling uploading firmware file */
  server.on("/submit", HTTP_POST, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", serverSubmit);
  });
  server.begin();

}
