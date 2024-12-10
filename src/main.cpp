//==============================================================================
///
/// @file
/// @brief Программа для робота Карела и стартовая функция
///
//==============================================================================


#include "karel.h"


//==============================================================================
/// Программа для робота Карела
///
void KarelProgram() {
/// @todo Добавить программу для Карела

TurnLeft();
while(FrontIsClear() == true){
TurnLeft();
TurnLeft();
TurnLeft();
    while( FrontIsClear() == true){
  if (BeepersPresent() == true){
    PickBeeper();
}
  if(BeepersPresent() == false and FrontIsClear() == true){
    Move();
}
}
while (BeepersPresent() == true){
    PickBeeper();
}
TurnLeft();
Move();
TurnLeft();
while(FrontIsClear() == true){
    Move();
}
TurnLeft();
TurnLeft();
TurnLeft();
}

TurnLeft();
TurnLeft();
TurnLeft();
    while( FrontIsClear() == true){
  if (BeepersPresent() == true){
    PickBeeper();
}
  if (BeepersPresent() == false and FrontIsClear() == true){
    Move();
}
}
while(BeepersPresent() == true){
    PickBeeper();
}
}



//==============================================================================
/// Стартовая функция
///
int main() {
    LoadWorld("worlds/CB_01.w");
    KarelProgram();
    Finish();
    return 0;
}
