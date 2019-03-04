#include <ESP8266WiFi.h>
 
//Nombre de la red
const char* nombre = "Getxo Bela Eskola";
 
//Password
const char* password = "";
 
//Puerto (dejar en 80 por defecto)
WiFiServer server(80);
 
 
 
void setup() {
  Serial.begin(115200);
  delay(50); //Hay que dejar un margen de tiempo
 
  
  // Conectar a la red WiFi
  WiFi.begin(nombre, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(100); //aqui tambien hay que dejar un margen de tiempo
  Serial.println("Conectado a la red WiFi");
  
  // Iniciar el servidor
  server.begin();
  Serial.println("Se ha iniciado el servidor");
  
  // Escribir la direccion IP
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
  
}
  
void loop() {
  // Comprobar si se ha conectado algun cliente
  WiFiClient client = server.available();
   
  if (client) {
    Serial.println("Nueva conexion");
    
    // Escribir las cabeceras HTML
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
   
    //Escribir el contenido que vamos a visualizar
    client.println("<html>");
    client.println("<head>");
      client.println("<meta charset='utf-8'>");
      client.println("<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>");
      client.println("<link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css' integrity='sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T' crossorigin='anonymous'>");
      client.println("<script src='https://code.jquery.com/jquery-3.3.1.slim.min.js' integrity='sha256-3edrmyuQ0w65f8gfBsqowzjJe2iM6n0nKciPUp8y+7E=' crossorigin='anonymous'></script>");
      client.println("<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.7.2/css/all.css' integrity='sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr' crossorigin='anonymous'>");
    client.println("</head>");
    client.println("<body>");
    client.println("<nav class='navbar navbar-expand-lg navbar-light bg-light'>");
    client.println("</nav>");
    client.println("<div class='container-fluid'>");
      client.println("<div class='row'>");
        client.println("<div class='col'>");
        for(int i = 0; i < 7;i++)
        {
          client.println("<div class='row'>");
            client.println("<div class='col-2'>");
              client.println("<h2> WEEKDAY </h2>");
            client.println("</div>");
            client.println("<div class='col-2'>");
              client.println("<button class='btn btn-primary'> Algo de una alarma</button>");
            client.println("</div>");
            client.println("<div class='col-1'>");
              client.println("<a href='#' class='fas fa-plus fa-2x'></a>");
            client.println("</div>");
            client.println("<div class='col-2'>");
              client.println("<div class='input-group mb-3'>");
                client.println("<div class='input-group-prepend'>");
                  client.println("<span class='input-group-text' id='inputGroup-sizing-default'>HORA</span>");
                client.println("</div>");
                client.println("<input type='text' class='form-control' aria-label='Sizing example input' aria-describedby='inputGroup-sizing-default'>");
              client.println("</div>");
            client.println("</div>");
            client.println("<div class='col-2'>");
              client.println("<div class='input-group mb-3'>");
                client.println("<div class='input-group-prepend'>");
                  client.println("<span class='input-group-text' id='inputGroup-sizing-default'>MINUTOS</span>");
                client.println("</div>");
                client.println("<input type='text' class='form-control' aria-label='Sizing example input' aria-describedby='inputGroup-sizing-default'>");
              client.println("</div>");
            client.println("</div>");
          client.println("</div>");
        } 
        client.println("</div>");
      client.println("</div>");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");
     
  }
  
}
