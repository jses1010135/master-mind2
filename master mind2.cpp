#include <iostream>
#include <cstdlib>
#include <ctime>

void generateGuess(int guess[4]) {
    bool used[10] = { false };
    for (int i = 0; i < 4; i++) {
        int num;
        do {
            num = rand() % 10;
        } while (used[num]);
        guess[i] = num;
        used[num] = true;
    }
}

int main() {
    srand(time(NULL));

    int guess[4];
    int a = 0, b = 0;
    int attempts = 0;
    int score = 0;

	while (a != 4) {//a不等於4就繼續猜
		generateGuess(guess);//產生猜測
		attempts++;//猜的次數

        std::cout << "電腦猜測：";
        for (int i = 0; i < 4; i++) {
            std::cout << guess[i];
        }
        std::cout << std::endl;

        std::cout << "請輸入幾A幾B：";
        std::cin >> a >> b;

        

        if (a == 4) {
            std::cout << "電腦猜對了！總共猜了 " << attempts << " 次。" << std::endl;
            
        }
    }

    return 0;
}