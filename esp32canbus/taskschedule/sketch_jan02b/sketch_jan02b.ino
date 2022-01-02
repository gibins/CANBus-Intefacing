
TaskHandle_t Task1;
TaskHandle_t Task2;

void setup() {

  Serial.begin(115200);
  
  xTaskCreatePinnedToCore(
    Task1code,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    -1,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */
  delay(500);

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
    Task2code,   /* Task function. */
    "Task2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    12,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    1);          /* pin task to core 1 */
  delay(500);
}
//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
     Serial.print("Task1 running on core looping ");
    Serial.println(xPortGetCoreID());
    //digitalWrite(led1, HIGH);
    delay(1000);
    //digitalWrite(led1, LOW);
    delay(1000);
  }

}
//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ) {
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    Serial.print("Task2 running on core looping ");
    Serial.println(xPortGetCoreID());
    //digitalWrite(led2, HIGH);
    delay(700);
    //digitalWrite(led2, LOW);
    delay(700);
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("From loop() running on core ");
  Serial.println(xPortGetCoreID());

}
