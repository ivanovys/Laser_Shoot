#include <LiquidCrystal.h>
#include <ServoTimer2.h>
#include <VirtualWire.h>
#include <VirtualWire.h>

ServoTimer2 s,s1,s2,s3,s4; 

int p=A0, p1=A1,p2=A2, p3=A3, p4=A4,din=A5; 
int mish=5;
int res=7,och=0,led=1, sump,r=0;
int serv=0, serv1=0, serv2=0, serv3=0, serv4=0,k=0,l=0;

LiquidCrystal lcd(13, 12, 10, 9, 8, 7);

 int x,y,z,b,a;

void setup()
{
  Serial.begin(9600);
  vw_set_ptt_inverted(true); // Необходимо для DR3100
  vw_setup(2000); // Задаем скорость приема
  vw_rx_start(); // Начинаем мониторинг эфира
 lcd.begin(16, 2); // для дисплея

  pinMode(p,INPUT);
  pinMode(p1,INPUT);
   pinMode(p2,INPUT);
  pinMode(p3,INPUT);
   pinMode(p4,INPUT);
   pinMode(din,OUTPUT);

    s.attach(2);  
   
    s.write(150);
    delay(300);
    
     s1.attach(3);  
   
    s1.write(150);
     delay(300);
    
     s2.attach(4);  
   
    s2.write(150);
     delay(300);
    
     s3.attach(5);  
   
    s3.write(150);
     delay(300);
     
     s4.attach(6);  
   
    s4.write(150);
     
     delay(500);
  s.detach();
  s1.detach();
  s2.detach();
  s3.detach();
  s4.detach();
}

int incPulse(int val, int inc){
   if( val + inc  > 2000 )
      return 1000 ;
   else
       return val + inc;  
}

void loop()
{
    lcd.setCursor(0, 0);
 lcd.print("Poyehali!");
 lcd.setCursor(0, 1);
   lcd.print("!!!Ochki:");

   x = analogRead(p)/4; 
  y = analogRead(p1)/4; 
    z = analogRead(p2)/4; 
  b = analogRead(p3)/4; 
    a = analogRead(p4)/4; 
    
     Serial.println(b);
 
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Буфер для сообщения
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Длина буфера
  if (vw_get_message(buf, &buflen)) // Если принято сообщение
  {
    // Начинаем разбор
    int i;
    // Если сообщение адресовано не нам, выходим
    if (buf[0] != 'z')
    {
      return; 
    }
    
    // Числовой параметр начинается с индекса 4
    i = 2; 
    sump = 0;
    // Поскольку передача идет посимвольно, то нужно преобразовать набор символов в число
    while (buf[i] != ' ')
    {
      sump *= 10;
      sump += buf[i] - '0';
      i++;
    }
    
  }
  
    if(sump==25){
     noTone(din);
     mish=5;
     och=0;
     sump=15;
     
     s.attach(2);  
   
    s.write(150);
     delay(300);
     s1.attach(3);  
   
    s1.write(150);
    
     delay(300);
     s2.attach(4);  
    delay(300);
    s2.write(150);
    
     s3.attach(5);  
    delay(300);
    s3.write(150);
    
     s4.attach(6);  
   
    s4.write(150);
    
     delay(500);
  s.detach();
  s1.detach();
  s2.detach();
  s3.detach();
  s4.detach();
  
  serv=0;
  serv1=0;
  serv2=0;
  serv3=0;
  serv4=0;
  sump=15;
  och=0;
  mish=5;
  
k=0;
l=0;
lcd.setCursor(0, 1);
   lcd.print("!!!Ochki:");
lcd.setCursor(9, 1);
 lcd.print(och);
 lcd.setCursor(10, 1);
 lcd.print("0");}

  if(mish>0 && mish<=5){ 
   
if(sump>0 && sump<=15){
   
   //  digitalWrite(led,LOW);
 
  if(x>220 && serv<1){
    s.attach(2);
    s.write(1500);
    delay(200);
    s.detach();
   mish=mish-1;
    serv=serv+1;
   
  // digitalWrite(led,HIGH);
  
  }
  
  if(y>200 && serv2<1){

  //  digitalWrite(led,HIGH);
   s1.attach(3);
    s1.write(1500);
    delay(200);
    s1.detach();
mish=mish-1;
    serv2=serv2+1;
  }
  if(z>220 && serv1<1){
  s2.attach(4);
    s2.write(1500);
    delay(200);
     s2.detach();
   mish=mish-1;
    serv1=serv1+1;
  //  digitalWrite(led,HIGH);
 
  }
  
  if(b>220 && serv3<1){
 
   // digitalWrite(led,HIGH);
 
     s3.attach(5);
    s3.write(1500);
    delay(200);
    s3.detach();
    mish=mish-1;
    serv3=serv3+1;
  }
  if(a>220 && serv4<1){
 
   // digitalWrite(led,HIGH);
 s4.attach(6);
    s4.write(1500);
    delay(200);
    s4.detach();
mish=mish-1;
    serv4=serv4+1;
  }
}
if(sump==0&&l==0){
 l=l+1;

och=5-mish;
    //Serial.println(och);
 
 lcd.setCursor(0, 1);
   lcd.print("!!!Ochki:");
lcd.setCursor(9, 1);
 lcd.print(och);

analogWrite ( din ,  255 ) ; 
  delay ( 50 ) ; 
  analogWrite ( din ,  40 ) ; 
  delay ( 10 ) ; 
  analogWrite ( din ,  255 ) ; 
  delay ( 50 ) ; 
  analogWrite ( din ,  100 ) ; 
  delay ( 50 ) ; 

}
}

if(mish==0&&k==0){

  och=5+sump-1;

    //Serial.println(och);
 lcd.setCursor(0, 1);
   lcd.print("!!!Ochki:");
lcd.setCursor(9, 1);
 lcd.print(och);
 
 k=k+1;

}
}

