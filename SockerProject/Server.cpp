#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
//#include <ctime>

#define MAX_SIZE 1024 //��� ����
#define MAX_CLIENT 3 //�ִ� �ο� 3

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct SOCKET_INFO { //����ü ����
    SOCKET sck; //ctrl + Ŭ��, unsigned int pointer��
    string user; //user  : ����� �̸�
};

vector<SOCKET_INFO> sck_list; //������ ����� client�� ������ ����.
//�������� �� �� ������ vector�� ����.
SOCKET_INFO server_sock; //��������� ������ ������ ����.
int client_count = 0; //���� ���ӵ� Ŭ���̾�Ʈ �� ī��Ʈ �뵵.

string get_current_time();
void server_init(); //������ ������ ����� �Լ�
void add_client(); //accept �Լ� ����ǰ� ���� ����
void send_msg(const char* msg); //send() ����
void recv_msg(int idx); //recv() ����
void del_client(int idx); //Ŭ���̾�Ʈ���� ������ ���� ��

vector<string> name = {};
int main() {
    WSADATA wsa;
    // Winsock�� �ʱ�ȭ�ϴ� �Լ�. MAKEWORD(2, 2)�� Winsock�� 2.2 ������ ����ϰڴٴ� �ǹ�.
    // ���࿡ �����ϸ� 0��, �����ϸ� �� �̿��� ���� ��ȯ.
    // 0�� ��ȯ�ߴٴ� ���� Winsock�� ����� �غ� �Ǿ��ٴ� �ǹ�.

    int code = WSAStartup(MAKEWORD(2, 2), &wsa); //�����ϸ� 0, !0 => 1

 

    if (!code) {
        server_init();

        std::thread th1[MAX_CLIENT]; //�����带 ��� �迭 th1 , �迭�� ��� �ڷ����� thread
        //ũ�Ⱑ �ƽ�Ŭ���̾�Ʈ�� �迭 ����.
        //������� ! add_client �� �߳��������� ����� �� �ִ� ������ �����?
        //�� ������������� �����Լ��� �����Ű�� �ʴ´�

        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i] = std::thread(add_client);
            //Ŭ���̾�Ʈ�� ���� �� �ִ� ���¸� ������� accept
        }

        while (1) {
            string text, msg = "";

            std::getline(cin, text);
            const char* buf = text.c_str();
            msg = server_sock.user + " : " + buf;
            send_msg(msg.c_str());
        }
        /* �� �ڵ�� C++ ���α׷��� �� ����Ͽ� Ŭ���̾�Ʈ���� �Է��� ���ڿ��� ������ �����ϴ� ���� ������ �����մϴ�.
            while���� �׻� ��(true)�̹Ƿ�, ������ ������ �ʰ� ��� ����˴ϴ�.
            std::getline(cin, text)�� ����ڰ� Ű����� �Է��� ���ڿ��� �о���̴� �Լ��Դϴ�.
            getline() �Լ��� �� �پ� ���ڿ��� �о���Դϴ�.�о���� ���ڿ��� text ������ ����˴ϴ�.
            const char* buf = text.c_str()�� string ��ü�� text�� ������ C ��Ÿ���� ���ڿ��� ��ȯ�Ͽ� buf ������ ������ �����մϴ�.
            msg = server_sock.user + " : " + buf; �� ������ user �̸��� ����ڰ� �Է��� ���ڿ��� ���ļ� ���ο� ���ڿ� msg�� �����մϴ�.
            send_msg(msg.c_str())�� ������ ���ڿ� msg�� ������ �����ϴ� �Լ��Դϴ�.c_str() �Լ��� ���ڿ��� C ��Ÿ���� ���ڿ��� ��ȯ�Ͽ� �����մϴ�.
            ��, �� �ڵ�� ����ڰ� �Է��� ���ڿ��� ������ �����ϴ� ���� ������ �����ϴ� �ڵ��Դϴ�.*/
        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i].join();
        }

        closesocket(server_sock.sck);
    }
    else {
        cout << "���α׷� ����. (Error code : " << code << ")";
    }

    WSACleanup();

    return 0;
}

//���� �ð��� ����ϴ� �ڵ�
string get_current_time() {
    time_t rawtime;
    struct tm timeinfo;
    char Buffer[80];

    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);

    strftime(Buffer, sizeof(Buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return Buffer;
}

void server_init() //������ ���� Ȱ��ȭ
{

    server_sock.sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //���� ������ Ư���� �� �ִ� int�� ���ڸ� ����.
    //server_sock�� sck -> SOCKET_INFO sck, user

    SOCKADDR_IN server_addr = {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7777); //123.0.0.1:7777 �߿� ------:7777�� ����
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //123.0.0.1:----�� �����Ѵ�.

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr));
    //server_sock.sck, �ּҸ� �Ҵ��ϰ� ���� socket
    //server_adrr�� �ڷ��� SOCKADDR_IN�� sockaddr*������ ��ȯ

    listen(server_sock.sck, SOMAXCONN);

    server_sock.user = "server";

    cout << "Server On" << endl;
}

void add_client() {
    //Ŭ���̾�Ʈ�� ������ �����ϸ� ������ ���ο� ������ �����ȴ�.
    //�� ������ �ּҸ� ���� ���� => addr�̴�.
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { }; //�޽����� �ִ���̸� �������ش�. 1024

    ZeroMemory(&addr, addrsize); //addr�� 0x00���� �ʱ�ȭ

    SOCKET_INFO new_client = {};
    //sck, user : Ŭ���̾�Ʈ�� ���� ������ ����, �ؿ��� sck_list�� �߰���.

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    //���� �ּ�, �ּ��� ����
    //Ŭ���̾�Ʈ ����ŭ accept���� connect()
    recv(new_client.sck, buf, MAX_SIZE, 0); //Ŭ���̾�Ʈ connect(), send()
    //Ŭ���̾�Ʈ ������ �ٷ� user �̸��� ��Ƽ� send�� ��. recv()�� �ޱ� ����
    new_client.user = string(buf); //buf�� ����ڰ� �Է��� �̸��� ����ִ�.
    //user�� char������ ������ ������ string������ ����ȯ ���༭ ����.

    string msg = "��" + new_client.user + " ���� ��ȭ�濡 �����߽��ϴ�.";
    string warn = "�������� ��Ī�Ͽ� ������ �䱸�� �� ������ ������ �ǽɵ� ��� ��ȭ�� �ߴ��Ͻñ� �ٶ��ϴ�.";
    name.push_back(new_client.user);
    //����ö(���ֻ�ټ�)���� �����ϼ̽��ϴ�.
    cout << msg << endl << warn << endl;
    sck_list.push_back(new_client); //sck_list�� �߰���.
    //[ {1234, jechul}, { 1234, jechul }, { 1234, jechul } ]

    std::thread th(recv_msg, client_count);//join�� ������ �������� ��⸦ �Ѵ�.
    //�������ʵ��� ����Ű������ thread�� ����Ѵ�.
    //��� ������ Ŭ���̾�Ʈ�� �����ε� ��� �޽����� ���� �� �ֵ��� recv���� ���
    client_count++;


    cout << "������ ������ �� : " << client_count << "��" << endl;
    /*cout << "����ȭ������ : ";
    for (int i = 0; i < sck_list.size(); i++)
    {
        cout << name.at(i) +" ";
    }
    cout << endl;*/
    //������ : ���Ҷ� ����ö
    send_msg(msg.c_str());

    th.join();
}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) {
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
        //���� ������ ��� Ŭ���̾�Ʈ���� send�޽��� �Ѵ�
    }
}

void recv_msg(int idx) {
    char buf[MAX_SIZE] = { };
    string msg = "";


    while (1) {
        ZeroMemory(&buf, MAX_SIZE);//0�� �ʱ�ȭ


        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) {//���. �޼����� ������ 0���� Ŀ����
            msg = "|������� : " + sck_list[idx].user + "\t �����ð� : " + get_current_time() + "\n|���۳��� : " + buf;
            //����ö(�ö�Ҵ�)���� �� : endl;
            cout << msg << endl;
            send_msg(msg.c_str());
        }
       // 
        else {
            msg = "��" + sck_list[idx].user + " ���� �����߽��ϴ�.";
            cout << msg << endl;
            send_msg(msg.c_str());
            del_client(idx);
            return;
        }
    }
}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    client_count--;
}




