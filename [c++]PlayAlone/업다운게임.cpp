#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << " -----------------------------------------------" << endl;
    cout << " | '업다운 게임' 1 - 100 중 랜덤 숫자 맞히기!  |" << endl;
    cout << " -----------------------------------------------" << endl;

    // 랜덤 시드 설정
    srand((unsigned int)time(NULL));

    // 랜덤한 수 생성
    int answer = rand() % 100 + 1;
    int cnt = 0;//도전 횟수 카운트

    while (true)
    {
        int guess;

        // 사용자 입력값 받기
        cout << "1 - 100까지의 숫자를 입력해주세요. ";
        cin >> guess;


        // 입력값 검증
        if (guess < 1 || guess > 100)
        {
            cout << "잘못 입력하셨습니다." << endl;
            continue;
        }

        // 비교 및 출력
        if (guess == answer)
        {
            cout << "정답입니다. 게임승리!" << endl;
            cout << cnt << "회 만에 성공하셨습니다!" << endl;
            break;
        }
        else if (guess < answer)
        {
            cout << "업!" << endl;
            cnt++;
        }
        else
        {
            cout << "다운!" << endl;
            cnt++;
        }
    }

    return 0;
}