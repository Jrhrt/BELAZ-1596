//#include "IRremote.h"
#define LEFT_SENSOR_PIN 8
#define RIGHT_SENSOR_PIN 9
#define LEFT_MOTOR_PIN 2
#define RIGHT_MOTOR_PIN 4
#define LEFT_MOTOR_SPEED 3
#define RIGHT_MOTOR_SPEED 5
int IrRecv = 10;
int pult = 0;
int g_s = 50;
int flag = 0;
int leftSensorValue = 0;
int rightSensorValue = 0;
//IRrecv irrecv(IrRecv);
//decode_results results;
void goforward() {
    if (leftSensorValue == 1 && rightSensorValue == 1) {
      // Оба датчика на белом поле
      analogWrite(LEFT_MOTOR_SPEED, g_s);
      analogWrite(RIGHT_MOTOR_SPEED, g_s); // Двигаться вперед
    } else if (rightSensorValue == 1) {
      // Левый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, g_s*4.1); // Остановить левый мотор
      analogWrite(RIGHT_MOTOR_SPEED, g_s*0.5); // Повернуть вправо
    } else if (leftSensorValue == 1) {
      // Правый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, g_s*0.5); // Повернуть влево
      analogWrite(RIGHT_MOTOR_SPEED, g_s*4.1); // Остановить правый мотор
    } else if (rightSensorValue == 0 && rightSensorValue == 0) {
      // Оба датчика чёрной линии
      analogWrite(LEFT_MOTOR_SPEED, 0);
      analogWrite(RIGHT_MOTOR_SPEED, 0); // Двигаться вперед
      flag++;
    }
}
void goforward_l() {
    if (leftSensorValue == 0 && rightSensorValue == 0) {
      // Оба датчика на белом поле
      analogWrite(LEFT_MOTOR_SPEED, 0);
      analogWrite(RIGHT_MOTOR_SPEED, 0); // Двигаться вперед
      flag++;
    } else if (leftSensorValue == 1) {
      // Левый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, g_s*0.5); // Остановить левый мотор
      analogWrite(RIGHT_MOTOR_SPEED, g_s*4.1); // Повернуть вправо
    } else {
      // Правый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, g_s*4.1); // Повернуть влево
      analogWrite(RIGHT_MOTOR_SPEED, g_s*0.5); // Остановить правый мотор
    }
}
void goforward_r() {
    if (leftSensorValue == 0 && rightSensorValue == 0) {
      // Оба датчика на белом поле
      analogWrite(LEFT_MOTOR_SPEED, 0);
      analogWrite(RIGHT_MOTOR_SPEED, 0); // Двигаться вперед
      flag++;
    } else if (rightSensorValue == 1) {
      // Левый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, g_s*4.1); // Остановить левый мотор
      analogWrite(RIGHT_MOTOR_SPEED, g_s*0.5); // Повернуть вправо
    } else {
      // Правый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, g_s*0.5); // Повернуть влево
      analogWrite(RIGHT_MOTOR_SPEED, g_s*4.1); // Остановить правый мотор
    }
}
void goback() {
    if (leftSensorValue == 1 && rightSensorValue == 1) {
      // Оба датчика на белом поле
      analogWrite(LEFT_MOTOR_PIN, 255-g_s);
      analogWrite(RIGHT_MOTOR_PIN, 255-g_s); // Двигаться вперед
    } else if (rightSensorValue == 1) {
      // Левый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, (255-g_s)*1.1); // Остановить левый мотор
      analogWrite(RIGHT_MOTOR_SPEED, 255-g_s); // Повернуть вправо
    } else if (leftSensorValue == 1) {
      // Правый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, 255-g_s); // Повернуть влево
      analogWrite(RIGHT_MOTOR_SPEED, (255-g_s)*1.1); // Остановить правый мотор
    } else {
      // Оба датчика чёрной линии
      analogWrite(LEFT_MOTOR_SPEED, 0);
      analogWrite(RIGHT_MOTOR_SPEED, 0); // Двигаться вперед
      flag++;
    }
}
void goback_r() {
    if (leftSensorValue == 0 && rightSensorValue == 0) {
      // Оба датчика на белом поле
      analogWrite(LEFT_MOTOR_PIN, 0);
      analogWrite(RIGHT_MOTOR_PIN, 0); // Двигаться вперед
      flag++;
    } else if (rightSensorValue == 1) {
      // Левый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, (255-g_s)*1.1); // Остановить левый мотор
      analogWrite(RIGHT_MOTOR_SPEED, 255-g_s); // Повернуть вправо
    } else {
      // Оба датчика чёрной линии
      analogWrite(LEFT_MOTOR_SPEED, 255-g_s);
      analogWrite(RIGHT_MOTOR_SPEED, (255-g_s)*1.1); // Двигаться вперед
      flag++;
    }
}
void goback_l() {
    if (leftSensorValue == 0 && rightSensorValue == 0) {
      // Оба датчика на белом поле
      analogWrite(LEFT_MOTOR_PIN, 0);
      analogWrite(RIGHT_MOTOR_PIN, 0); // Двигаться вперед
      flag++;
    } else if (leftSensorValue == 1) {
      // Левый датчик на черной линии
      analogWrite(LEFT_MOTOR_SPEED, 255-g_s); // Остановить левый мотор
      analogWrite(RIGHT_MOTOR_SPEED, (255-g_s)*1.1); // Повернуть вправо
    } else {
      // Оба датчика чёрной линии
      analogWrite(LEFT_MOTOR_SPEED, (255-g_s)*1.1);
      analogWrite(RIGHT_MOTOR_SPEED, 255-g_s); // Двигаться вперед
      flag++;
    }
}
void rotater() {
  if (rightSensorValue == 0) {
    analogWrite(LEFT_MOTOR_SPEED, g_s);
    analogWrite(RIGHT_MOTOR_SPEED, 355-g_s);
  } else {
    analogWrite(LEFT_MOTOR_SPEED, 0);
    analogWrite(RIGHT_MOTOR_SPEED, 0);
    flag++;
  }
}
void rotatel() {
  if (leftSensorValue == 0) {
    analogWrite(LEFT_MOTOR_SPEED, 355-g_s);
    analogWrite(RIGHT_MOTOR_SPEED, g_s);
  } else {
    analogWrite(LEFT_MOTOR_SPEED, 0);
    analogWrite(RIGHT_MOTOR_SPEED, 0);
    flag++;
  }
}
void miniforward() {
    analogWrite(LEFT_MOTOR_SPEED, g_s);
    analogWrite(RIGHT_MOTOR_SPEED, g_s);
    delay(100);
    analogWrite(LEFT_MOTOR_SPEED, 0);
    analogWrite(RIGHT_MOTOR_SPEED, 0);
    flag++;
}
void miniback() {
    analogWrite(LEFT_MOTOR_SPEED, 255-g_s);
    analogWrite(RIGHT_MOTOR_SPEED, 355-g_s);
    delay(100);
    analogWrite(LEFT_MOTOR_SPEED, 0);
    analogWrite(RIGHT_MOTOR_SPEED, 0);
    flag++;
}
void razgruz() {
    delay(1000);
    //тут будет код разгрузки
    flag++;
}
void setup() {
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_SPEED, OUTPUT);
  pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  //irrecv.enableIRIn();
  Serial.begin(9600); 
}
void loop() {
  leftSensorValue = digitalRead(LEFT_SENSOR_PIN);
  rightSensorValue = digitalRead(RIGHT_SENSOR_PIN);
  if (pult == 0) {
    if (flag == 0) {
      goforward_r();
      Serial.println(1);
    }
    else if (flag == 1) {
      rotater();
      Serial.println(2);
    }
    else if (flag == 2) {
      miniback();
      Serial.println(3);
    }
    else {
      flag = 0;
      pult++;
    }
    Serial.println(00000);
    
  }
  //pult = ... ;
  if (pult == 1) {
    if (flag == 0) {
      delay(1000);
      flag++;//тут загрузка красный
    }
    else if (flag == 1) {
      goforward_r();
    }
    else if (flag == 2) {
      miniback();
    }
    else if (flag == 3) {
      rotater();
    }
    else if (flag == 4) {
      goback_l();
    }
    else if (flag == 5) {
      razgruz();//выгрузка красный
    }
    else if (flag == 6) {
      miniforward();
    }
    else if (flag == 7) {
      goforward_l();
    }
    else if (flag == 8) {
      miniback();
    }
    else if (flag == 9) {
      rotatel();
    }
    else {
      flag = 0;
      pult++;
    }
    Serial.println(10001);
  }
  if (pult == 2) {
    if (flag == 0) {
      delay(1000);
      flag++;//тут загрузка зелёный
    }
    else if (flag == 1) {
      goforward_l();
    }
    else if (flag == 2) {
      miniback();
    }
    else if (flag == 3) {
      rotatel();
    }
    else if (flag == 4) {
      goback_r();
    }
    else if (flag == 5) {
      razgruz();//выгрузка зелёный
    }
    else if (flag == 6) {
      miniforward();
    }
    else if (flag == 7) {
      goforward_r();
    }
    else if (flag == 8) {
      rotater();
    }
    else {
      flag = 0;
      pult++;
    }Serial.println(20002);
  }
  if (pult == 3) {
    analogWrite(LEFT_MOTOR_SPEED, 0);
    analogWrite(RIGHT_MOTOR_SPEED, 0);
    delay(1000);//тут загрузка синий
    razgruz();//выгрузка синий
    flag = 0;
    
  }
  digitalWrite(RIGHT_MOTOR_SPEED, goforward);
  digitalWrite(LEFT_MOTOR_SPEED, 1);
//  Serial.print(rightSensorValue);
//  Serial.println(leftSensorValue);
 // Serial.println(irrecv.decode( &results ));
  //irrecv.resume();
} 
