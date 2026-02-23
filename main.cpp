#include "Mehmet.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

using namespace std;
bool On_Write = false;
int Textlen = 0;
int time_of_prograss;

void Backspace(int count, int speed) {
    for (int i = 0; i < count; i++) {
        cout << "\b \b" << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

void TextAnimation(string Text, float speed_ms, int error_rate, int remove_speed) { 
    Textlen = Text.length();
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(time(0));
        isSeeded = true;
    }

    float original_speed_ms = speed_ms;
    int Error_Waiting = 450;

    cout << "|" << flush; this_thread::sleep_for(chrono::milliseconds(400));
    cout << "\b \b" << flush; this_thread::sleep_for(chrono::milliseconds(400));
    for (int i = 0; i < (int)Text.length(); i++) {
        cout << "\a";
        time_of_prograss = ((i + 1) * 100) / Textlen;

        speed_ms = original_speed_ms;
        float RandSpeed = 0.2f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2.0f - 0.2f))); 
        speed_ms = speed_ms * RandSpeed;

        if (Text[i] == '.' || Text[i] == ',' || Text[i] == '!' || Text[i] == '?') {
            this_thread::sleep_for(chrono::milliseconds(350));
        }

        int RandNumber = rand() % 101;
        // Hata yapma mantığı
        if ((RandNumber < error_rate && Text[i] != ' ') && (i + 1 < (int)Text.length())) {
            cout << RED;
            On_Write = true;
            cout << (char)(Text[i] + 2) << Text[i + 1] << flush;
            this_thread::sleep_for(chrono::milliseconds(Error_Waiting));
            
            Backspace(2, remove_speed);
            cout << RESET;
            cout << Text[i] << Text[i + 1] << flush;
            i++;
        } else {
            cout << RESET;
            cout << Text[i] << flush;
            On_Write = true;
        }
        
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(speed_ms))); 
    }
    cout << endl; 
}


void ShowProgressBar(int len_of_bar, int WaitTime) {
    cout << YELLOW;
    cout << "[" << flush; 
    for (int i = 0; i < len_of_bar; i++) {
        cout << "#" << flush;
        this_thread::sleep_for(chrono::milliseconds(WaitTime));
    }
    cout << "] Yukleme Tamamlandi!" << endl;
    cout << RESET;
}

void AutoScript(string text, int AutoSpeed,int text_speed, int error_possibility){
    int len_of_text = text.length();
    int a = len_of_text / 2;
    ShowProgressBar(a , AutoSpeed);

    cout << endl;

    TextAnimation(text, text_speed, error_possibility);
}
