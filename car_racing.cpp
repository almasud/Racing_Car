#include<stdio.h>
#include<graphics.h>

void CreateNMoveEnemyCar(int x, int y, int moveFactor, colors body, colors head)
{
    setcolor(BLACK);
    rectangle(x, y+moveFactor, x+20, -30+y+moveFactor);
    setfillstyle(SOLID_FILL, body);
    floodfill(x+1, -30+y+moveFactor+1, BLACK);

    setcolor(BLACK);
    rectangle(x+5, y+moveFactor, x+15, 5+y+moveFactor);
    setfillstyle(SOLID_FILL, head);
    floodfill(x+6, 5+y+moveFactor-1, BLACK);

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    int page = 0, roadY =- 300;
    int carX = 0, carSpeed = 5;
    int enemyNormal = 0, enemyFast = 0, enemySlow = 0;

    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        ///For background
        setcolor(CYAN);
        rectangle(0, 0, 1000, 1000);
        setfillstyle(SOLID_FILL, CYAN);
        floodfill(1,1, CYAN);

        ///For road
        setcolor(WHITE);
        rectangle(200, -1, 400, 500);
        setfillstyle(SOLID_FILL, DARKGRAY);  /// Sets the current fill pattern and fill color
        floodfill(201,0, WHITE);  ///Fill an enclosed area

        ///Lines in road
        for(int i=0; i<450; i+=105)
        {
            rectangle(290, 10+i+roadY, 310, 50+i+roadY);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(291, 11+i+roadY, WHITE);
        }

        /// For repeat road lines
        roadY += 15;
        if(roadY > 500)
            roadY = - 500;


        ///for life and points
        settextstyle(BOLD_FONT, 0 , 2);
        outtextxy(10,10,"LIFE:");
        outtextxy(10,40,"POINTS:");
        ///drawing circle for life
        setfillstyle(SOLID_FILL, WHITE);
        circle(90,20,6);
        floodfill(91,21, WHITE);
        circle(110,20,6);
        floodfill(111,21, WHITE);
        circle(130,20,6);
        floodfill(131,21, WHITE);

        outtextxy(100,40,"0");

        ///Body of car
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, RED);
        rectangle(300+carX, 400, 340+carX, 460);
        floodfill(301+carX, 401, BLACK);

        setfillstyle(SOLID_FILL, GREEN);
        rectangle(305+carX, 405, 335+carX, 455);
        floodfill(306+carX, 406, BLACK);

        ///Front of car
        setfillstyle(SOLID_FILL, BROWN);
        rectangle(305+carX, 385, 335+carX, 400);
        floodfill(306+carX, 386, BLACK);

        ///Car wheels
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(305+carX, 392, 90, 270, 6);
        pieslice(337+carX, 392, 270, 90, 5);


        ///Enemy car 1
        CreateNMoveEnemyCar(350, -50, enemyFast, RED, GREEN);
        if (enemyFast >= (385 + 50)) {
            switch(carX + 300) {
            case (350 - 40) ... (350 + 20):
                printf("GAME OVER");
                delay(2000);
                exit(1);
            }
        }
        ///Enemy car 2
        CreateNMoveEnemyCar(300, -100, enemyNormal, BLUE, BROWN);
        if (enemyNormal >= (385 + 100)) {
            switch(carX + 300) {
            case (300 - 40) ... (300 + 20):
                printf("GAME OVER");
                delay(2000);
                exit(1);
            }
        }
        ///Enemy car 3
        CreateNMoveEnemyCar(250, -30, enemySlow, YELLOW, CYAN);
        if (enemySlow >= (385 + 30)) {
            switch(carX + 300) {
            case (250 - 40) ... (250 + 20):
                printf("GAME OVER");
                delay(2000);
                exit(1);
            }
        }

        enemyNormal += 5;
        enemyFast += 8;
        enemySlow += 3;


        /// For repeat enemy cars
        if (enemyNormal > getmaxy() + 50)
            enemyNormal = - 50;

        if (enemyFast > getmaxy() + 100)
            enemyFast = - 100;

        if (enemySlow > getmaxy() + 30)
            enemySlow = - 30;

        /// For car movement
        if(GetAsyncKeyState(VK_LEFT))
            carX -= carSpeed;
        else if(GetAsyncKeyState(VK_RIGHT))
            carX += carSpeed;

//        page = 1 - page;
        delay(50);
    }

    getch();
}
