//==============================================================================
///
/// @file
/// @brief Программа для робота Карела и стартовая функция
///
//==============================================================================


#include "karel.h"
#include <iostream>

void PickAllBeepers();
void TurnRight();
void PutDoubleBeepers(int& beeper_counter);
void PickAllBeepers(int& beeper_counter);
void GrapAndPut(int& beeper_counter);
//==============================================================================
/// Программа для робота Карела
///
void KarelProgram() {
    bool is_even = false;
    int beeper_counter = 0;
    while(FrontIsClear()){
        while(FrontIsClear()){
            GrapAndPut(beeper_counter);
            Move();
        }
        GrapAndPut(beeper_counter);
        if(!is_even){
            TurnLeft();
            if(!FrontIsClear())
                return;
            Move();
            TurnLeft();
            
        }
        else{
            TurnRight();
            if(!FrontIsClear())
                return;
            Move();
            TurnRight();
        }
        is_even = !is_even;
        }

}

void PutDoubleBeepers(int& beeper_counter){
    for( ;beeper_counter > 0; beeper_counter--){
        for(int i = 0; i < 2; i++)
            PutBeeper();
    }
        
}

void PickAllBeepers(int& beeper_counter){
    while (BeepersPresent()){
        PickBeeper();
        beeper_counter++;
    }
}

void TurnRight(){
    for(int i = 0; i < 3; i++){
        TurnLeft();
    }
}

void GrapAndPut(int& beeper_counter){
    PickAllBeepers(beeper_counter);
    PutDoubleBeepers(beeper_counter);
}
//==============================================================================
/// Стартовая функция
///
int main() {
    LoadWorld("worlds/Double_beepers_02.w");
    KarelProgram();
    Finish();
    return 0;
}
