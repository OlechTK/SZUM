#define X_MAX_PIN           2
#define Y_MAX_PIN          15
#define Z_MAX_PIN          19

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40

int x=0,y=0,z=0;
int flaga=0;

int pozycja=0;

int wyzerowany=0;

void setup() 
{
  Serial.begin(57600);

    pinMode(X_MAX_PIN,INPUT);
  digitalWrite(X_MAX_PIN,HIGH);
    pinMode(Y_MAX_PIN,INPUT);
  digitalWrite(Y_MAX_PIN,HIGH);
    pinMode(Z_MAX_PIN,INPUT);
  digitalWrite(Z_MAX_PIN,HIGH);

////////////////////////////////////

 pinMode(X_STEP_PIN,OUTPUT);
      pinMode(X_DIR_PIN,OUTPUT);
      pinMode(X_ENABLE_PIN,OUTPUT);
      pinMode(X_CS_PIN,OUTPUT);
      digitalWrite(X_ENABLE_PIN,LOW);
  digitalWrite(X_DIR_PIN,LOW);

  pinMode(Y_STEP_PIN,OUTPUT);
      pinMode(Y_DIR_PIN,OUTPUT);
      pinMode(Y_ENABLE_PIN,OUTPUT);
      pinMode(Y_CS_PIN,OUTPUT);
      digitalWrite(Y_ENABLE_PIN,LOW);
  digitalWrite(Y_DIR_PIN,LOW);

  pinMode(Z_STEP_PIN,OUTPUT);
      pinMode(Z_DIR_PIN,OUTPUT);
      pinMode(Z_ENABLE_PIN,OUTPUT);
      pinMode(Z_CS_PIN,OUTPUT);
      digitalWrite(Z_ENABLE_PIN,LOW);
  digitalWrite(Z_DIR_PIN,LOW);


} // koniec setup


void loop() 
{
String a;

///////////////


//////////////////
while ( Serial.available() )
{
a=Serial.readString();
sscanf(a.c_str(),"x %d y %d z %d",&x,&y,&z);



//Serial.println(x);
//Serial.println(y);
//Serial.println(z);



if (x<0) 
{
    digitalWrite(X_DIR_PIN,HIGH);
  x=-x;
} else  digitalWrite(X_DIR_PIN,LOW);

if (y<0) 
{
    digitalWrite(Y_DIR_PIN,HIGH);
  y=-y;
} else  digitalWrite(Y_DIR_PIN,LOW);

if (z<0) 
{
    digitalWrite(Z_DIR_PIN,HIGH);
  z=-z;
} else  digitalWrite(Z_DIR_PIN,LOW);



  
} // koniec while ( Serial.available() )

    if(digitalRead(X_MAX_PIN) == 1)
    {
      digitalWrite(X_DIR_PIN,HIGH);
      x=300;
      
      digitalWrite(X_STEP_PIN,HIGH);
      x--;
      
    }

        if(digitalRead(Y_MAX_PIN) == 1)
    {
      digitalWrite(Y_DIR_PIN,HIGH);
      y=300;

      digitalWrite(Y_STEP_PIN,HIGH);
      y--;
    }

        if(digitalRead(Z_MAX_PIN) == 1)
    {
      digitalWrite(Z_DIR_PIN,HIGH);
      z=300;

            digitalWrite(Z_STEP_PIN,HIGH);
      z--;
    }   

    if(digitalRead(X_MAX_PIN) != 1 && x>0)  //// X 
    {   
      digitalWrite(X_STEP_PIN,HIGH);
      x--;
    }
    
        if(digitalRead(Y_MAX_PIN) != 1 && y>0)  //// Y 
    {   
      digitalWrite(Y_STEP_PIN,HIGH);
      y--;
    }

        if(digitalRead(Z_MAX_PIN) != 1 && z>0) ///// Z 
    {   
      digitalWrite(Z_STEP_PIN,HIGH);
      z--;
    }

    delay(1);
   // delayMicroseconds(80);
    digitalWrite(X_STEP_PIN,LOW);
    digitalWrite(Y_STEP_PIN,LOW);
    digitalWrite(Z_STEP_PIN,LOW);
    //delayMicroseconds(80);
    delay(1);

    if(x==0 && y==0 && z==0 && flaga==0) 
    {
      Serial.println("1");
      flaga=1;
    }

    if((x!=0 || y!=0 || z!=0) && flaga==1) 
    {
      Serial.println("0");
      flaga=0;
    }


    
    




} //koniec loop
