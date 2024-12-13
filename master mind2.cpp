#include <iostream>

//產生猜測
void generateGuess(int guess[4]) {//int guess[4]代表猜測的數字
	bool used[10] = { false };//用來檢查數字是否重複 used[0]~used[9]分別代表0~9是否已經使用 true代表已使用 false代表未使用
	for (int i = 0; i < 4; i++) {//產生4個數字
		int num;//用來存放產生的數字
        do {
			num = rand() % 10;//產生0~9的數字
		} while (used[num]);//如果數字重複就重新產生
		guess[i] = num;//將數字存入猜測
		used[num] = true;//將數字標記為已使用
    }
}
//輸入答案
int main() {
	srand(time(NULL));//設定亂數種子
	int answer = 0;//答案
	int guess[4];//猜測
	int a = 0, b = 0;//a代表正確數字正確位置的數量 b代表正確數字錯誤位置的數量
	int attempts = 0;//猜的次數
	
    
	while (a != 4) {//a不等於4就繼續猜
		generateGuess(guess);//產生猜測
		attempts++;//猜的次數

        std::cout << "電腦猜測：";
        for (int i = 0; i < 4; i++) {
			std::cout << guess[i];//輸出猜測
        }
		std::cout << std::endl;//換行

        std::cout << "請輸入幾A幾B：";
		answer = a, b;//輸入答案 std::cin >> a >> b;
		
		std::cin >> answer;//輸入答案

        

        if (a == 4) {
            std::cout << "電腦猜對了！總共猜了 " << attempts << " 次。" << std::endl;
            
        }
    }

    return 0;
}