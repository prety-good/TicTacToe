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
};  //存储棋盘信息
void checkerboard::play(int a, int b)  //玩家下棋
{
    x[a][b] = 1;
}
int checkerboard::get(int a, int b)  //获取目标棋格状态
{
    return x[a][b];
}
int checkerboard::judge()   //判断胜负是否发生
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
void checkerboard::AI()    //AI下棋
{
    //AI可以直接获胜
    //行
    if (x[0][0] == 2 && x[0][1] == 2 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][0] == 2 && x[0][2] == 2 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 2 && x[0][2] == 2 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[1][0] == 2 && x[1][1] == 2 && x[1][2] == 0)  x[1][2] = 2;
    else if (x[1][0] == 2 && x[1][2] == 2 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 2 && x[1][2] == 2 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[2][0] == 2 && x[2][1] == 2 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[2][0] == 2 && x[2][2] == 2 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[2][1] == 2 && x[2][2] == 2 && x[2][0] == 0)  x[2][0] = 2;
    //列
    else if (x[0][0] == 2 && x[1][0] == 2 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[1][0] == 2 && x[2][0] == 2 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[0][0] == 2 && x[2][0] == 2 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[0][1] == 2 && x[1][1] == 2 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[1][1] == 2 && x[2][1] == 2 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 2 && x[2][1] == 2 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[0][2] == 2 && x[1][2] == 2 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[1][2] == 2 && x[2][2] == 2 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 2 && x[2][2] == 2 && x[1][2] == 0)  x[1][2] = 2;
    //斜
    else if (x[0][0] == 2 && x[1][1] == 2 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[0][0] == 2 && x[2][2] == 2 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 2 && x[2][2] == 2 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[2][0] == 2 && x[1][1] == 2 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 2 && x[1][1] == 2 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[2][0] == 2 && x[0][2] == 2 && x[1][1] == 0)  x[1][1] = 2;
    //防止玩家获胜
    else if (x[0][0] == 1 && x[1][0] == 0 && x[2][0] == 0 && x[0][1] == 0 && x[1][1] == 2 && x[2][1] == 0 && x[0][2] == 0 && x[1][2] == 0 && x[2][2] == 1)  x[1][2] = 2;
    else if (x[0][0] == 0 && x[1][0] == 0 && x[2][0] == 1 && x[0][1] == 0 && x[1][1] == 2 && x[2][1] == 0 && x[0][2] == 1 && x[1][2] == 0 && x[2][2] == 0)  x[2][1] = 2;
    //行
    else if (x[0][0] == 1 && x[0][1] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][0] == 1 && x[0][2] == 1 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 1 && x[0][2] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[1][0] == 1 && x[1][1] == 1 && x[1][2] == 0)  x[1][2] = 2;
    else if (x[1][0] == 1 && x[1][2] == 1 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 1 && x[1][2] == 1 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[2][0] == 1 && x[2][1] == 1 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[2][0] == 1 && x[2][2] == 1 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[2][1] == 1 && x[2][2] == 1 && x[2][0] == 0)  x[2][0] = 2;
    //列
    else if (x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[1][0] == 1 && x[2][0] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[0][0] == 1 && x[2][0] == 1 && x[1][0] == 0)  x[1][0] = 2;
    else if (x[0][1] == 1 && x[1][1] == 1 && x[2][1] == 0)  x[2][1] = 2;
    else if (x[1][1] == 1 && x[2][1] == 1 && x[0][1] == 0)  x[0][1] = 2;
    else if (x[0][1] == 1 && x[2][1] == 1 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[0][2] == 1 && x[1][2] == 1 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[1][2] == 1 && x[2][2] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 1 && x[2][2] == 1 && x[1][2] == 0)  x[1][2] = 2;
    //斜
    else if (x[0][0] == 1 && x[1][1] == 1 && x[2][2] == 0)  x[2][2] = 2;
    else if (x[0][0] == 1 && x[2][2] == 1 && x[1][1] == 0)  x[1][1] = 2;
    else if (x[1][1] == 1 && x[2][2] == 1 && x[0][0] == 0)  x[0][0] = 2;
    else if (x[2][0] == 1 && x[1][1] == 1 && x[0][2] == 0)  x[0][2] = 2;
    else if (x[0][2] == 1 && x[1][1] == 1 && x[2][0] == 0)  x[2][0] = 2;
    else if (x[2][0] == 1 && x[0][2] == 1 && x[1][1] == 0)  x[1][1] = 2;
    //特殊情况
    else if (x[0][1] == 1 && x[1][0] == 1 && x[1][1] == 2 && x[0][2]==0)  x[0][2] = 2;
    else if (x[0][1] == 1 && x[1][2] == 1 && x[1][1] == 2)  x[0][0] = 2;
    else if (x[1][0] == 1 && x[2][1] == 1 && x[1][1] == 2)  x[0][0] = 2;
    else if (x[2][1] == 1 && x[1][2] == 1 && x[1][1] == 2 && x[0][2]==0)  x[0][2] = 2;
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

void UI::init()   //初始化背景和标题
{
    Mat img1(700, 700, CV_8UC3, Scalar(255, 255, 255));
    img1.copyTo(img);
    cvui::text(img, 280, 40, "TicTacToe", 1, 0x000000);
}

void UI::tip() //信息提示
{
    cvui::text(img, 20, 20, "It's your turn!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::win() //信息提示
{
    cvui::text(img, 20, 20, "You win!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::lose() //信息提示
{
    cvui::text(img, 20, 20, "You lost!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::draw() //信息提示
{
    cvui::text(img, 20, 20, "Rraw!", 0.6, 0x808080);
    cvui::text(img, 12, 60, "Press esc to exit the game", 0.6, 0x800000);
}

void UI::deltip()  //清除之前的信息提示
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
        for (a = 0, c = 100; a < 3 && c <= 500; a++, c = c + 200)   //玩家下棋并判断鼠标输入,若有输入，将信息传入 checkerboard 并更改图片显示
        {
            for (b = 0, d = 100; b < 3 && d <= 500; b++, d = d + 200)
            {
                if ((i % 2 == 1) && board.get(a, b) == 0 && cvui::button(ui.img, d, c, ui.part, ui.play, ui.play))
                {
                    cvui::image(ui.img, d, c, ui.play); board.play(a, b); i++;
                }
            }
        }
        //判断棋局是否结束
        if (board.judge() == 1) { ui.deltip(); ui.win(); imshow("TicTacToe", ui.img); waitKey(); break; }
        else if (board.judge() == 2) { ui.deltip(); ui.lose(); imshow("TicTacToe", ui.img); waitKey(); break; }
        else if (board.judge() == 3) { ui.deltip(); ui.draw(); imshow("TicTacToe", ui.img); waitKey(); break; }

        if (i % 2 == 0) { waitKey(30); board.AI(); i++; }  //AI下棋
        for (a = 0, c = 100; a < 3 && c <= 500; a++, c = c + 200)    //更新AI下棋对棋盘信息的改变,更新UI界面的图片显示
        {
            for (b = 0, d = 100; b < 3 && d <= 500; b++, d = d + 200)
            {
                if (board.get(a, b) == 2) { cvui::image(ui.img, d, c, ui.ai); }
            }
        }
        cvui::update();
        imshow("TicTacToe", ui.img);
        //判断棋局是否结束
        if (board.judge() == 1) { ui.deltip(); ui.win(); imshow("TicTacToe", ui.img); waitKey(); break; }
        else if (board.judge() == 2) { ui.deltip(); ui.lose(); imshow("TicTacToe", ui.img); waitKey(); break; }
        else if (board.judge() == 3) { ui.deltip(); ui.draw(); imshow("TicTacToe", ui.img); waitKey(); break; }
        //按esc退出程序
        if (waitKey(30) == 27) { break; }
    }
    return 0;
}