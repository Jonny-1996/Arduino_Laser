int laser_input_1 = 5;
int laser_input_2 = 6;

int laser_output_1 = 7;
int laser_output_2 = 8;

int status_loading;
int status_active;

void setup(){
    //Ishga tushmagan xolat, Kutish xolati!
    pinMode(1, OUTPUT);  
    pinMode(2, INPUT);
    
    //Ishga tushgan xolat
    pinMode(3, OUTPUT); 
    pinMode(4, INPUT);

    digitalWrite(1, HIGH);
    digitalWrite(3, LOW);

    //laser qabul qiluvchi
    pinMode(laser_input_1, INPUT);
    pinMode(laser_input_2, INPUT);

    //laser chiquvchi
    pinMode(laser_output_1, OUTPUT);
    pinMode(laser_output_2, OUTPUT);
}

void loop(){
    :A
    status_loading = digitalRead(2);
    status_active = digitalRead(4);
    if(status_loading == 1 && status_active == 0){
        // 2-controllerga signal beriladi
        for(int i = 1; i <= 3; i++){
            digitalWrite(laser_output_1, HIGH);
            delay(500);
            digitalWrite(laser_output_1, LOW);
            delay(500);
        }

        //chiqivchi lazerlar yoqiladi
        digitalWrite(laser_output_1, HIGH);
        digitalWrite(laser_output_2, HIGH);

        // Keyin, status_loading rejimi o'chiriladi va status_active rejimi yoqiladi
        digitalWrite(1, LOW);
        digitalWrite(3, HIGH);
        goto A;
    }else{
        if(status_loading == 0 && status_active == 1){
            while(1){
                if(!(digitalRead(laser_input_1) && digitalRead(laser_input_2))){
                    //Trivoga
                }
            }
        }
    }
}