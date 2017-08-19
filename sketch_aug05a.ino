 
#define TRIG  12
#define ECHO  8
#define GREEN_LIGHT 10
#define RED_LIGHT 6

#define DANGER_ZONE 6
 
long duration;
int distance;
int isFirst = 1;
 
void setup()
{
  pinMode(GREEN_LIGHT, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop()
{
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  distance = duration / 29 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance <= DANGER_ZONE)
  {
    digitalWrite(RED_LIGHT, HIGH);
    digitalWrite(GREEN_LIGHT, LOW);
    Serial.println("Too close. Should do something.");
  }
  else
  {
    digitalWrite(GREEN_LIGHT, HIGH);
    digitalWrite(RED_LIGHT, LOW);
    Serial.println("Safe..");
  }
  delay(500);
}
