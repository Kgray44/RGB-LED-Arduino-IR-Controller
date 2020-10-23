#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
char command;
boolean understood = false;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)){
    understood = true;
    switch(results.value) {
      case 16738455:
        command = '1';
        break;
      case 16750695:
        command = '2';
        break;
      case 16756815:
        command = '3';
        break;
      case 16724175:
        command = '4';
        break;
      case 16718055:
        command = '5';
        break;
      case 16743045:
        command = '6';
        break;
      case 16716015:
        command = '7';
        break;
      case 16726215:
        command = '8';
        break;
      case 16734885:
        command = '9';
        break;
      case 16730805:
        command = '0';
        break;
      case 16712445:
        command = 'A';
        break;
      case 16736925:
        command = 'B';
        break;
      case 16720605:
        command = 'C';
        break;
      case 16754775:
        command = 'D';
        break;
      case 16761405:
        command = 'E';
        break;
      case 16728765:
        command = 'F';
        break;
      case 16732845:
        command = 'G';
        break;

      case 1090494559:
        command = 'H';
        break;
      case 1090478239:
        command = 'I';
        break;
      case 1090510879:
        command = 'J';
        break;
      case 1090490479:
        command = 'K';
        break;
      case 1090474159:
        command = 'L';
        break;
      case 1090506799:
        command = 'M';
        break;
      case 1090498639:
        command = 'N';
        break;
      case 1090482319:
        command = 'O';
        break;
      case 1090514959:
        command = 'P';
        break;
      case 1090472119:
        command = 'Q';
        break;
      case 1090476199:
        command = 'R';
        break;
      case 1090463959:
        command = 'S';
        break;
      case 1090464469:
        command = 'T';
        break;
      case 1090512919:
        command = 'U';
        break;
      case 1090497109:
        command = 'V';
        break;
      case 1090468039:
        command = 'W';
        break;
      case 1090461919:
        command = 'X';
        break;
      default:
        understood = false;
    }
    if (understood == true) Serial.println(command);
    irrecv.resume(); // Receive the next value
  }
}
