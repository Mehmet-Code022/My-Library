#ifndef MEHMET_H
#define MEHMET_H
#include <string>

void TextAnimation(std::string Text, float speed_ms, int error_rate, int remove_speed = 100);
void Backspace(int count, int speed);
void ShowProgressBar(int len_of_bar, int WaitTime); 
void AutoScript(std::string text, int AutoSpeed,int text_speed, int error_possibility);

#endif
