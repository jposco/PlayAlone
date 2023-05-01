#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
//#include <ctime>
 
#define MAX_SIZE 1024 //상수 선언
#define MAX_CLIENT 3 //최대 인원 3

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct SOCKET_INFO { //구조체 정의 
    SOCKET sck; //ctrl + 클릭, unsigned int pointer형
    string user; //user  : 사람의 이름
};

vector<SOCKET_INFO> sck_list; //서버에 연결된 client를 저장할 변수.
//여러명이 될 수 있으니 vector로 선언.
SOCKET_INFO server_sock; //서브소켓의 정보를 저장할 정보.
int client_count = 0; //현재 접속된 클라이언트 수 카운트 용도.

string get_current_time();
void server_init(); //서버용 소켓을 만드는 함수
void add_client(); //accept 함수 실행되고 있을 예정
void send_msg(const char* msg); //send() 실행
void recv_msg(int idx); //recv() 실행
void del_client(int idx); //클라이언트와의 연결을 끊을 때

vector<string> name = {};
int main() {
    WSADATA wsa;
    // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
    // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
    // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.

    int code = WSAStartup(MAKEWORD(2, 2), &wsa); //성공하면 0, !0 => 1

 

    if (!code) {
        server_init();

        std::thread th1[MAX_CLIENT]; //쓰레드를 담는 배열 th1 , 배열에 담긴 자료형은 thread
        //크기가 맥스클라이언트인 배열 생성.
        //쓰레드란 ! add_client 가 잘끝날때까지 대기할 수 있는 공간을 만든다?
        //잘 끝나지않을경우 메인함수를 종료시키지 않는다

        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i] = std::thread(add_client);
            //클라이언트를 받을 수 있는 상태를 만들어줌 accept
        }

        while (1) {
            string text, msg = "";

            std::getline(cin, text);
            const char* buf = text.c_str();
            msg = server_sock.user + " : " + buf;
            send_msg(msg.c_str());
        }
        /* 이 코드는 C++ 프로그래밍 언어를 사용하여 클라이언트에서 입력한 문자열을 서버로 전송하는 무한 루프를 구현합니다.
            while문은 항상 참(true)이므로, 루프가 끝나지 않고 계속 실행됩니다.
            std::getline(cin, text)는 사용자가 키보드로 입력한 문자열을 읽어들이는 함수입니다.
            getline() 함수는 한 줄씩 문자열을 읽어들입니다.읽어들인 문자열은 text 변수에 저장됩니다.
            const char* buf = text.c_str()는 string 객체인 text의 내용을 C 스타일의 문자열로 변환하여 buf 포인터 변수에 저장합니다.
            msg = server_sock.user + " : " + buf; 는 서버의 user 이름과 사용자가 입력한 문자열을 합쳐서 새로운 문자열 msg를 생성합니다.
            send_msg(msg.c_str())는 생성된 문자열 msg를 서버로 전송하는 함수입니다.c_str() 함수는 문자열을 C 스타일의 문자열로 변환하여 전송합니다.
            즉, 이 코드는 사용자가 입력한 문자열을 서버로 전송하는 무한 루프를 구현하는 코드입니다.*/
        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i].join();
        }

        closesocket(server_sock.sck);
    }
    else {
        cout << "프로그램 종료. (Error code : " << code << ")";
    }

    WSACleanup();

    return 0;
}

//현재 시간을 출력하는 코드
string get_current_time() {
    time_t rawtime;
    struct tm timeinfo;
    char Buffer[80];

    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);

    strftime(Buffer, sizeof(Buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return Buffer;
}

void server_init() //서버측 소켓 활성화
{

    server_sock.sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //서버 소켓을 특정할 수 있는 int형 숫자를 담음.
    //server_sock의 sck -> SOCKET_INFO sck, user

    SOCKADDR_IN server_addr = {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7777); //123.0.0.1:7777 중에 ------:7777을 정의
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //123.0.0.1:----을 정의한다.

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr));
    //server_sock.sck, 주소를 할당하고 싶은 socket
    //server_adrr의 자료형 SOCKADDR_IN을 sockaddr*형으로 변환

    listen(server_sock.sck, SOMAXCONN);

    server_sock.user = "server";

    cout << "Server On" << endl;
}

void add_client() {
    //클라이언트와 연결을 성공하면 서버에 새로운 소켓이 생성된다.
    //그 소켓의 주소를 담을 변수 => addr이다.
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { }; //메시지의 최대길이를 설정해준다. 1024

    ZeroMemory(&addr, addrsize); //addr을 0x00으로 초기화

    SOCKET_INFO new_client = {};
    //sck, user : 클라이언트의 소켓 정보를 저장, 밑에서 sck_list에 추가함.

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    //소켓 주소, 주소의 길이
    //클라이언트 수만큼 accept실행 connect()
    recv(new_client.sck, buf, MAX_SIZE, 0); //클라이언트 connect(), send()
    //클라이언트 측에서 바로 user 이름을 담아서 send를 함. recv()로 받기 위해
    new_client.user = string(buf); //buf엔 사용자가 입력한 이름이 들어있다.
    //user는 char형으로 들어오기 때문에 string형으로 형변환 해줘서 저장.

    string msg = "▶" + new_client.user + " 님이 대화방에 입장했습니다.";
    string warn = "※지인을 사칭하여 금전을 요구할 수 있으니 도용이 의심될 경우 대화를 중단하시기 바랍니다.";
    name.push_back(new_client.user);
    //정제철(제주삼다수)님이 입장하셨습니다.
    cout << msg << endl << warn << endl;
    sck_list.push_back(new_client); //sck_list에 추가함.
    //[ {1234, jechul}, { 1234, jechul }, { 1234, jechul } ]

    std::thread th(recv_msg, client_count);//join을 만나는 순간까지 대기를 한다.
    //끝나지않도록 대기시키기위해 thread를 사용한다.
    //방금 생성된 클라이언트가 앞으로도 계속 메시지를 받을 수 있도록 recv실행 대기
    client_count++;


    cout << "▶현재 접속자 수 : " << client_count << "명" << endl;
    /*cout << "▷대화참여자 : ";
    for (int i = 0; i < sck_list.size(); i++)
    {
        cout << name.at(i) +" ";
    }
    cout << endl;*/
    //참여자 : 윤소라 정제철
    send_msg(msg.c_str());

    th.join();
}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) {
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
        //현재 접속한 모든 클라이언트에게 send메시지 한다
    }
}

void recv_msg(int idx) {
    char buf[MAX_SIZE] = { };
    string msg = "";


    while (1) {
        ZeroMemory(&buf, MAX_SIZE);//0로 초기화


        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) {//대기. 메세지가 들어오면 0보다 커진다
            msg = "|보낸사람 : " + sck_list[idx].user + "\t 보낸시간 : " + get_current_time() + "\n|전송내용 : " + buf;
            //정제철(시라소니)님의 말 : endl;
            cout << msg << endl;
            send_msg(msg.c_str());
        }
       // 
        else {
            msg = "▶" + sck_list[idx].user + " 님이 퇴장했습니다.";
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




