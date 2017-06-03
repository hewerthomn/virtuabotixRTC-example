
#include <virtuabotixRTC.h>

#define PIN_RTC_CLK   6
#define PIN_RTC_DATA  7
#define PIN_RTC_RST   8

int _day        = 3,
    _month      = 6,
    _year       = 2017,
    _dayofweek  = 7,
    _hour       = 7,
    _minutes    = 51,
    _seconds    = 14
;

// rtc(clock, data, rst)
virtuabotixRTC myRTC(PIN_RTC_CLK, PIN_RTC_DATA, PIN_RTC_RST);

void setup() {
  Serial.begin(9600);

  //    setDS1302Time(seconds, minutes, hour, dayofweek, day, month, year)
  myRTC.setDS1302Time(_seconds, _minutes, _hour, _dayofweek, _day, _month, _year);
}

void loop() {
  myRTC.updateTime();

  Serial.print("Data: ");
  imprime_dia_da_semana(myRTC.dayofweek);
  Serial.print(", ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print("Hora : ");
  // Adiciona um 0 caso o valor da hora seja <10
  if (myRTC.hours < 10) {
    Serial.print("0");
  }
  Serial.print(myRTC.hours);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos minutos seja <10
  if (myRTC.minutes < 10) {
    Serial.print("0");
  }
  Serial.print(myRTC.minutes);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos segundos seja <10
  if (myRTC.seconds < 10)
  {
    Serial.print("0");
  }
  Serial.println(myRTC.seconds);

  delay(1000);
}

void imprime_dia_da_semana(int dia)
{
  switch (dia)
  {
    case 1:
      Serial.print("Domingo");
    break;
    case 2:
      Serial.print("Segunda");
    break;
    case 3:
      Serial.print("Terca");
    break;
    case 4:
      Serial.print("Quarta");
    break;
    case 5:
      Serial.print("Quinta");
    break;
    case 6:
      Serial.print("Sexta");
    break;
    case 7:
      Serial.print("Sabado");
    break;
  }
}
