/*
AdderCircuit.ino
Upper nibble and Lower nibble addition
Coded by Jorick Caberio
PUP BSCoE
September 18, 2012
*/

int inputPins [] = {2,3,4,5,6,7,A2,A3};       //pin 2 LSB
int outputPins [] = {8,9,10,11,12,13,A1,A0};  //pin 8 LSB
int x_n [8];
void setup(){
  for(int i=0;i<7;i++){
  pinMode(inputPins[i],INPUT);
  pinMode(outputPins[i], OUTPUT);
  }
}

void loop(){ 
  int x =0; 
  for(int j=0;j<8;j++){ 
  x_n[j] = (digitalRead(inputPins[j]))*bit(j);
  x += x_n[j]; 
  }
   int l = x & 15;       // extract lower nibble
   int u = (x & 240)>>4; // extract upper nibble
   int sum = l + u;      // obtain sum
   for(int n=0;n<7;n++){
   digitalWrite(outputPins[n],sum%2); //display he sum in binary form
     sum /= 2;   
   }
}
