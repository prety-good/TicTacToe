/**
 * @Author: Szw
 * @Date: 2020-10-5
 */
#define CVUI_IMPLEMENTATION
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include"cvui.h"
using namespace std;
using namespace cv;
class checkerboard
{
private:
    int x[3][3];
public:
    checkerboard() { int x[3][3] = { 0,0,0,0,0,0,0,0,0 }; }
    void play(int a, int b);
    void AI();
    int get(int a, int b);
    int judge();
};  //�洢������Ϣ
void checkerboard::play(int a, int b)  //�������
{
    x[a][b] = 1;
}
int checkerboard::get(int a, int b)  //��ȡĿ�����״̬
{
    return x[a][b];
}
int checkerboard::judge()   //�ж�ʤ���Ƿ���
{
    if ((x[0][0] == 1 && x[0][1] == 1 && x[0][2] == 1) || (x[1][0] == 1 && x[1][1] == 1 && x[1][2] == 1) || (x[2][0] == 1 && x[2][1] == 1 && x[2][2] == 1) ||
        (x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 1) || (x[0][1] == 1 && x[1][1] == 1 && x[2][1] == 1) || (x[0][2] == 1 && x[1][2] == 1 && x[2][2] == 1) ||
        (x[0][0] == 1 && x[1][1] == 1 && x[2][2] == 1) || (x[0][2] == 1 && x[1][1] == 1 && x[2][0] == 1)) {
        return 1;
    }
    else if ((x[0][0] == 2 && x[0][1] == 2 && x[0][2] == 2) || (x[1][0] == 2 && x[1][1] == 2 && x[1][2] == 2) || (x[2][0] == 2 && x[2][1] == 2 && x[2][2] == 2) ||
        (x[0][0] == 2 && x[1][0] == 2 && x[2][0] == 2) || (x[0][1] == 2 && x[1][1] == 2 && x[2][1] == 2) || (x[0][2] == 2 && x[1][2] == 2 && x[2][2] == 2) ||
        (x[0][0] == 2 && x[1][1] == 2 && x[2][2] == 2) || (x[0][2] == 2 && x[1][1] == 2 && x[2][0] == 2)) {
        return 2;
    }
    else if (x[0][0] != 0 && x[1][0] != 0 && x[2][0] != 0 && x[0][1] != 0 && x[1][1] != 0 && x[2][1] != 0 && x[0][2] != 0 && x[1][2] != 0 && x[2][2] != 0) { return 3; }
    else { return 0; }
}
void checkerboard::AI()    //AI����
{
    //AI����ֱ�ӻ�ʤ
    //��
    if (x[0][0] == 2 && x[0][1] == 2 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][0] == 2 && x[0][2] == 2 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 2 && x[0][2] == 2 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[1][0] == 2 && x[1][1] == 2 && x[1][2] == 0)  x[1][2] = 2;
    else if (x[1][0] == 2 && x[1][2] == 2 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 2 && x[1][2] == 2 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[2][0] == 2 && x[2][1] == 2 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[2][0] == 2 && x[2][2] == 2 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[2][1] == 2 && x[2][2] == 2 && x[2][0] == 0)  x[2][0] = 2;
    //��
    else if (x[0][0] == 2 && x[1][0] == 2 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[1][0] == 2 && x[2][0] == 2 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[0][0] == 2 && x[2][0] == 2 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[0][1] == 2 && x[1][1] == 2 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[1][1] == 2 && x[2][1] == 2 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 2 && x[2][1] == 2 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[0][2] == 2 && x[1][2] == 2 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[1][2] == 2 && x[2][2] == 2 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 2 && x[2][2] == 2 && x[1][2] == 0)  x[1][2] = 2;
    //б
    else if (x[0][0] == 2 && x[1][1] == 2 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[0][0] == 2 && x[2][2] == 2 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 2 && x[2][2] == 2 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[2][0] == 2 && x[1][1] == 2 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 2 && x[1][1] == 2 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[2][0] == 2 && x[0][2] == 2 && x[1][1] == 0)  x[1][1] = 2;
    //��ֹ��һ�ʤ
    else if (x[0][0] == 1 && x[1][0] == 0 && x[2][0] == 0 && x[0][1] == 0 && x[1][1] == 2 && x[2][1] == 0 && x[0][2] == 0 && x[1][2] == 0 && x[2][2] == 1)  x[1][2] = 2;
    else if (x[0][0] == 0 && x[1][0] == 0 && x[2][0] == 1 && x[0][1] == 0 && x[1][1] == 2 && x[2][1] == 0 && x[0][2] == 1 && x[1][2] == 0 && x[2][2] == 0)  x[2][1] = 2;
    //��
    else if (x[0][0] == 1 && x[0][1] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][0] == 1 && x[0][2] == 1 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 1 && x[0][2] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[1][0] == 1 && x[1][1] == 1 && x[1][2] == 0)  x[1][2] = 2;
    else if (x[1][0] == 1 && x[1][2] == 1 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 1 && x[1][2] == 1 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[2][0] == 1 && x[2][1] == 1 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[2][0] == 1 && x[2][2] == 1 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[2][1] == 1 && x[2][2] == 1 && x[2][0] == 0)  x[2][0] = 2;
    //��
    else if (x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[1][0] == 1 && x[2][0] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[0][0] == 1 && x[2][0] == 1 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[0][1] == 1 && x[1][1] == 1 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[1][1] == 1 && x[2][1] == 1 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 1 && x[2][1] == 1 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[0][2] == 1 && x[1][2] == 1 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[1][2] == 1 && x[2][2] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 1 && x[2][2] == 1 && x[1][2] == 0)  x[1][2] = 2;
    //б
    else if (x[0][0] == 1 && x[1][1] == 1 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[0][0] == 1 && x[2][2] == 1 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 1 && x[2][2] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[2][0] == 1 && x[1][1] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 1 && x[1][1] == 1 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[2][0] == 1 && x[0][2] == 1 && x[1][1] == 0)  x[1][1] = 2;
    //�������
    else if (x[0][1] == 1 && x[1][0] == 1 && x[1][1] == 2)  x[0][2] = 2;
    else if (x[0][1] == 1 && x[1][2] == 1 && x[1][1] == 2)  x[0][0] = 2;
    else if (x[1][0] == 1 && x[2][1] == 1 && x[1][1] == 2)  x[0][0] = 2;
    else if (x[2][1] == 1 && x[1][2] == 1 && x[1][1] == 2)  x[0][2] = 2;
    else if (x[0][1] == 1 && x[1][0] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[0][1] == 1 && x[1][2] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[1][0] == 1 && x[2][1] == 1 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[2][1] == 1 && x[1][2] == 1 && x[2][2] == 0)  x[2][2] = 2;
    //
    else if (x[1][1] == 0) x[1][1] = 2; //zhongxin
    else if (x[0][0] == 0) x[0][0] = 2; //jiao
    else if (x[2][0] == 0) x[2][0] = 2;
    else if (x[0][2] == 0) x[0][2] = 2;
    else if (x[2][2] == 0) x[2][2] = 2;
    else if (x[0][1] == 0) x[0][1] = 2; // bian
    else if (x[1][0] == 0) x[1][0] = 2;
    else if (x[1][2] == 0) x[1][2] = 2;
    else if (x[2][1] == 0) x[2][1] = 2;
}

class UI
{
public:Mat part, play, ai, img;
      UI() {
          part = imread("data/o_f.png");
          play = imread("data/o_o.png");
          ai = imread("data/o_x.png");
      }
      void init();
      void tip();
      void deltip();
      void win();
      void lose();
      void draw();
};

void UI::init()   //��ʼ�������ͱ���
{
    Mat img1(700, 700, CV_8UC3, Scalar(255, 255, 255));
    img1.copyTo(img);
    cvui::text(img, 280, 40, "TicTacToe", 1, 0x000000);
}

void UI::tip() //��Ϣ��ʾ
{
    cvui::text(img, 20, 20, "It's your turn!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::win() //��Ϣ��ʾ
{
    cvui::text(img, 20, 20, "You win!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::lose() //��Ϣ��ʾ
{
    cvui::text(img, 20, 20, "You lost!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::draw() //��Ϣ��ʾ
{
    cvui::text(img, 20, 20, "Rraw!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::deltip()  //���֮ǰ����Ϣ��ʾ
{
    line(img, Point(20, 30), Point(200, 30), Scalar(255, 255, 255), 30, LINE_4, 0);
}

checkerboard board;
UI ui;

int main()
{
    int i = 1, a = 0, b = 0, c = 100, d = 100;
    namedWindow("TicTacToe", WINDOW_AUTOSIZE);
    cvui::init("TicTacToe");
    ui.init();
    while (1)
    {
        if (board.judge() == 0) { ui.tip(); }
        for (a = 0, c = 100; a < 3 && c <= 500; a++, c = c + 200)   //������岢�ж��������,�������룬����Ϣ���� checkerboard ������ͼƬ��ʾ
        {
            for (b = 0, d = 100; b < 3 && d <= 500; b++, d = d + 200)
            {
                if ((i % 2 == 1) && board.get(a, b) == 0 && cvui::button(ui.img, d, c, ui.part, ui.play, ui.play))
                {
                    cvui::image(ui.img, d, c, ui.play); board.play(a, b); i++;
                }
            }
        }
        if (i % 2 == 0) { board.AI(); i++; }  //AI����
        for (a = 0, c = 100; a < 3 && c <= 500; a++, c = c + 200)    //����AI�����������Ϣ�ĸı�,����UI�����ͼƬ��ʾ
        {
            for (b = 0, d = 100; b < 3 && d <= 500; b++, d = d + 200)
            {
                if (board.get(a, b) == 2) { cvui::image(ui.img, d, c, ui.ai); }
            }
        }
        cvui::update();
        imshow("TicTacToe", ui.img);
        //�ж�����Ƿ����
        if (board.judge() == 1) { ui.deltip(); ui.win(); imshow("TicTacToe", ui.img); waitKey(); break; }
        else if (board.judge() == 2) { ui.deltip(); ui.lose(); imshow("TicTacToe", ui.img); waitKey(); break; }
        else if (board.judge() == 3) { ui.deltip(); ui.draw(); imshow("TicTacToe", ui.img); waitKey(); break; }
        //��esc�˳�����
        if (waitKey(30) == 27) { break; }
    }
    return 0;
}