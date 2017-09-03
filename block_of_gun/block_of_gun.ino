unsigned long currentDown;
unsigned long currentUP; // переменны для времени
unsigned long loopTime;
unsigned long TimeButton;

void setup() {
  Serial.begin(9600);
 vw_set_ptt_inverted(true); // Необходимо для DR3100
  vw_setup(2000); // Устанавливаем скорость передачи (бит/с)
  lcd.init(); 
  lcd.init();
   
pinMode(led, OUTPUT); //порт вывода для лазера
pinMode(button, INPUT);// порт ввода для кнопки
pinMode(din, OUTPUT);// порт вывода для динамик
 lcd.backlight();// Инициализируем дисплей: 2 строки по 16 символов 
 currentDown = millis(); 
 sump=n;
 lcd.setCursor(0, 0);
    lcd.print ("Patrons:");
    lcd.setCursor(0, 1); //перевод курсора в 2 столбец 2й строки
    lcd.print(n); 
}
void loop(){ 
  if (digitalRead(restart)== HIGH){
    String strmsg = "z ";
    strmsg+=res;
    strmsg += " ";
    char msg[255];
  strmsg.toCharArray(msg, 255);
  Serial.println(msg); 
  vw_send((uint8_t *)msg, strlen(msg));
    vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx();
   n=15;
   sump=15;
   lcd.setCursor(0, 1); //перевод курсора в 2 столбец 2й строки
   lcd.print(n); 
    }
  else{
    String strmsg = "z ";
    strmsg+=sump;
    strmsg += " ";
    char msg[255];
  strmsg.toCharArray(msg, 255);
  Serial.println(msg); 
  vw_send((uint8_t *)msg, strlen(msg));
    vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx();
   
  if(n!=0){//условие прекращения работы пистолета
   
    if (digitalRead(button) == HIGH) {//условие работы кнопки всего 3 милисекунды 
 currentUP = millis(); 
 
   TimeButton=currentUP-currentDown;//нахождение времени пока мы держим кнопку
 if (TimeButton<300){//условие если держать больше 3 милисекунд
 
  digitalWrite(led, HIGH);

  delay(100);
 
  for(inter=800;inter>=650;inter=inter-10){
  tone(din,inter);
  delay(10);}
  delay(200);
  noTone(din);

 digitalWrite(led, LOW);
 
 sump=sump-1; 
   n=n-1;// вычитание одного патрона
   if(n<=9){
     lcd.setCursor(0, 1);
     lcd.print("0");
      lcd.setCursor(1, 1); //перевод курсора в 2 столбец 2й строки
    lcd.print(n);
   }
  else{
    lcd.setCursor(0, 1); //перевод курсора в 2 столбец 2й строки
    lcd.print(n);//выводим оставшиеся патроны
    } 
     /* vw_send((uint8_t *)msg, strlen(msg));
        vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx(); // Ждем пока передача будет оконченаv 
     vw_send((uint8_t *)msg, strlen(msg));
        vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx(); // Ждем пока передача будет оконченаv */
   }
   else {
digitalWrite(led, LOW);//отключение светодиода
   }
  }else {                          
digitalWrite(led, LOW);   //отключение светодиода        
 currentDown = millis();
}
  }         else
    { 
      lcd.setCursor(0, 0);
    lcd.print("Patrons:");
    lcd.setCursor(0, 1); //перевод курсора в 1 столбец 2 строки
    digitalWrite(led, LOW);//отключить лазер
   
     vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx(); // Ждем пока передача будет оконченаv  
 }  
  }
}

