# PLOTTER

Рік випуску: __2017__<br/>
Версія: __1.2.2__<br/>
Розробник: __PrintTeam__<br/>
Платформа: __Arduino Uno__<br/>
<br/>

# Апаратне забезпечення

## Складання схеми Arduino

Наша команда радить використати цей [гайд](https://create.arduino.cc/projecthub/Mrinnovative/arduino-based-mini-cnc-2d-plotter-234462). Там є відео про збірку плоттера.

## Оcобливості пристроїв

* каретки можуть блокуватися, якщо їх розмістити у крайніх позиціях, тому їх потрібно залишати у позиції на один крок до краю
* для більшої плавності і коректності рисування плавних кривих ліній варто переконатись у міцності закріплення олівця 
* олівець не повинен тиснути на горизонтальну каретку, оскільки це може порушити її роботу

# Програмне забезпечення 

## Завантаження коду на плату Arduino UNO:
Для завантаження коду необхідно:
1. Мати в наявності середовище [Arduino IDE](https://www.arduino.cc/en/main/software) (important:>=2.4).
1. Завантажити та встановити бібліотеку [Adafruit Motor shield](https://github.com/adafruit/Adafruit-Motor-Shield-library).
2. Відкрити [файл](https://github.com/progbase/gdk/blob/master/samples/basic_servo_motor.ino) у Arduino IDE.
3. Підключити плату до комп'ютера за допомогою USB-кабеля.
4. Завантажити код на плату за допомогою клавіші "Upload" або комбінації клавіш "Ctrl+U".
 
## Програмування складових пристрою:
Для малювання треба писати код для Arduino:
* Підключити заголовочні файли `<AFMotor.h>` та `<Servo.h>`
* `servoMotor.write(servo_position)` - зміна позиції серво-мотора, який відповідає за позиції олівця, 
де `servo_position` - це позиція в градусах відносно початкової позицї
* `AF_Stepper Stepper1(48, 2);`
  `AF_Stepper Stepper2(48, 1);` підключення кареток, де 2 або 1 це номер порта, у який підключена каретка
* `Stepper1.setSpeed(х)` - швидкість руху кареток
* `Stepper1.step(100, FORWARD, SINGLE)` 
  `Stepper2.step(100,FORWARD,SINGLE)` рух кареток, 100 - довжина, `FORWARD` - напрям (`FORWARD` або `BACKWARD`)

---

# Результати роботи пристрою

Рисунки:

![samples](https://trello-attachments.s3.amazonaws.com/55c9eb62b3c625897bfd3b48/593c63227a0f59630b5df691/dbf4feb296a65ec269419807fd697dd8/pixlr_20170611002140247.jpg)

[Відео процесу рисування](https://youtu.be/XvzxU51w5mE).

Код для даних рисунків можна знайти у директорії [`/samples`](https://github.com/progbase/gdk/tree/master/samples).

---

**Склад команди:**

- Віталіна Мірошник (**_Product Owner_**) 
- Ілья Шкуренко (**_Scrum Master_**) 
- Олександр Дюкарев (**_Team Lead_**) 
- Микола Мединський (**_QA Lead_**) 
- Данило Дзенік (**_Розробник/Тестувальник_**) 
- Микита Маслов (**_Розробник/Тестувальник_**) 

---

**_Artifacts_**: 

Презентації: 
[Тема](https://docs.google.com/presentation/d/1OY_tqmEDnNz6hrbzQ7ytALHOpbBxI2-pYZAZCOH-Im4/) | 
[Sprint 1](https://docs.google.com/presentation/d/1T1wAQpsOCEFu72t43GAawP0izPLj81JajwGZa7nsV1g/edit?usp=sharing) |
[Sprint 2](https://docs.google.com/presentation/d/1UKvrilGTcnLewPC7UgFHKMzLJuBw65j8lEtUlAgVeBo/edit?usp=sharing) |
[Sprint 3](https://docs.google.com/presentation/d/17GkNjmEWU-II5cSZznFsurBOtL1SfL4aFqHGCp7xAJU/edit?usp=sharing)

[Беклог продукту](https://docs.google.com/spreadsheets/d/1JVIrdSNkkqdG2RSLHyG2HKRIE9UhnrqPDRy3gCZOlGo/)

[Дошка задач](https://trello.com/b/WcNKVhkJ/-)

[Burndown Chart](https://docs.google.com/spreadsheets/d/19KKF0ZNmHPPWMTa3YHdzxx7NwX1hhEt0l8ualjpYSPQ/)

---
