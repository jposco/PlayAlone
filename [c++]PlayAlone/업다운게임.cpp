#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << " -----------------------------------------------" << endl;
    cout << " | '���ٿ� ����' 1 - 100 �� ���� ���� ������!  |" << endl;
    cout << " -----------------------------------------------" << endl;

    // ���� �õ� ����
    srand((unsigned int)time(NULL)); 

    // ������ �� ����
    int answer = rand() % 100 + 1;
    int cnt = 0;//���� Ƚ�� ī��Ʈ

    while (true)
    {
        int guess;

        // ����� �Է°� �ޱ�
        cout << "1 - 100������ ���ڸ� �Է����ּ���. ";
        cin >> guess;


        // �Է°� ����
        if (guess < 1 || guess > 100)
        {
            cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
            continue;
        }

        // �� �� ���
        if (guess == answer)
        {
            cout << "�����Դϴ�. ���ӽ¸�!" << endl;
            cout << cnt << "ȸ ���� �����ϼ̽��ϴ�!" << endl;
            break; 
        }
        else if (guess < answer)
        {
            cout << "��!" << endl;
            cnt++;
        }
        else
        {
            cout << "�ٿ�!" << endl;
            cnt++;
        }
    }

    return 0;
}