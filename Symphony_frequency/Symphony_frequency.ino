const int pin = A2;
long getFrequency(int pin);

void setup() 
{
  pinMode(pin,INPUT);
  Serial.begin(115200);
}

void loop() 
{
  long freq = 0;
  freq = getFrequency(pin);
  Serial.println(freq);
  delay(100);
}

long getFrequency(int pin)
{
  #define SAMPLES 4096
  long freq = 0;
  for(unsigned int j=0; j<SAMPLES ; j++)
  {
    freq += 500000/pulseIn(pin,HIGH,250000); 
  }
  return freq/SAMPLES;
}

