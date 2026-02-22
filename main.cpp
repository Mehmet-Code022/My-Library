#include "Mehmet.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

void Backspace(int count, int speed) {
    for (int i = 0; i < count; i++) {
        cout << "\b \b" << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

void TextAnimation(string Text, float speed_ms, int error_rate, int remove_speed) {
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(time(0));
        isSeeded = true;
    }

    float original_speed_ms = speed_ms;
    int Error_Waiting = 450;

    for (int i = 0; i < (int)Text.length(); i++) {
        speed_ms = original_speed_ms;
        float RandSpeed = 0.2f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2.0f - 0.2f))); // 2.0 ile 0.2 arasi rastgele sayi
        speed_ms = speed_ms * RandSpeed;

        if (Text[i] == '.' || Text[i] == ',' || Text[i] == '!' || Text[i] == '?') {
            this_thread::sleep_for(chrono::milliseconds(350));
        }

        int RandNumber = rand() % 101;
        // Hata yapma mantığı
        if ((RandNumber < error_rate && Text[i] != ' ') && (i + 1 < (int)Text.length())) {
            cout << (char)(Text[i] + 2) << Text[i + 1] << flush;
            this_thread::sleep_for(chrono::milliseconds(Error_Waiting));
            
            Backspace(2, remove_speed);
            
            cout << Text[i] << Text[i + 1] << flush;
            i++;
        } else {
            cout << Text[i] << flush;
        }
        
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(speed_ms))); // static_cast<int> ile float degerimizi integera cevirdik ki hata almayalim
    }
    cout << endl; // Satırı bitir
}
