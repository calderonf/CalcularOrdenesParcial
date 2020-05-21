/*
  Parcial # 3 Señales y sistemas punto taller en casa:
  Use el código suministrado para implementar 3 filtros
*/
/*******PONGA AQUI SUS DATOS:*******/
char *nombre[] = {"Nombres Apellidos"};
long documento = 1029854031;
/***********************************/

/*no olvide configurar el serial a 1 mega o 1000000*/


/*No tocar de aqui para abajo:*/
int maxorder = 50;
int minorder = 20;

float fs = 100;
float mincut = 2.0;
float maxcut = 10.0;

char calcule_orden_primer_FIR(long documento) {
  return (((~((documento ^ ~(documento >> 8)))) % (maxorder - minorder)) + minorder) % (maxorder - minorder) + minorder;
}
char calcule_orden_segundo_FIR(long documento) {
  return (((~((documento ^ ~(documento >> 4)))) % (maxorder - minorder)) + minorder) % (maxorder - minorder) + minorder;
}
float calcule_corte_IIR(long documento, int*randNumber) {
  randomSeed(documento);
  * randNumber = random(1000);
  float denominador = ((float) * randNumber + 1.0) / 1000.0f;
  return ((maxcut - mincut) * denominador) + mincut;
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);/*velocidad maxima para que no interfiera en tiempos*/
  char ordenFIR1 = calcule_orden_primer_FIR(documento);
  char ordenFIR2 = calcule_orden_segundo_FIR(documento);
  int randNumber;
  float  corteIIR  = calcule_corte_IIR(documento, &randNumber);
  while (!Serial) {
    ; // Esperar a que el puerto inicie
  }
Serial.print("Mi nombre es: ");
  Serial.println(nombre[0]);
Serial.print("Mi documento es: ");
  Serial.println(documento);
  Serial.print("Y me comprometo a hacer mi parcial ");
Serial.println("con los siguientes datos:");
Serial.print("Orden del primer FIR pasobajos: \t");
  Serial.println((int)ordenFIR1);
Serial.print("Orden del segundo FIR pasoaltos: \t");
  Serial.println((int)ordenFIR2);
Serial.print("Corte del IIR: \t\t\t");
  Serial.println(corteIIR);
Serial.print("checksum1: ");
  Serial.println(~((documento ^ ~(documento >> 8))));
Serial.print("checksum2: ");
  Serial.println(~((documento ^ ~(documento >> 4))));
Serial.print("checksum3: ");
  Serial.println(randNumber);


}

  void loop() {
}
