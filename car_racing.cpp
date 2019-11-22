#include<graphics.h>

#define carX1 300
#define carX2 340
#define carY1 385
#define carY2 455
#define enemyCarWidth 20

void CreateNMoveEnemyCar(int x, int y, int moveFactor, colors body, colors head)
{
    setcolor(BLACK);
    rectangle(x, y+moveFactor, x+enemyCarWidth, -30+y+moveFactor);
    setfillstyle(SOLID_FILL, body);
    floodfill(x+1, -30+y+moveFactor+1, BLACK);

    setcolor(BLACK);
    rectangle(x+5, y+moveFactor, x+(enemyCarWidth-5), 5+y+moveFactor);
    setfillstyle(SOLID_FILL, head);
    floodfill(x+6, 5+y+moveFactor-1, BLACK);

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");

    int roadX1 = 200, roadX2 = 400, roadY1 = -1, roadY2 = 500;
    int roadLineY =- 300;

    int carX = 0, carSpeed = 5;
    int enemyNormal = 0, enemyFast = 0, enemySlow = 0;

    int point = 0, life = 3;
    char pointBuffer[10] = {'0'};

    while(1)
    {
        setactivepage(0);
        setvisualpage(1);
        cleardevice();

        ///For background
        setcolor(CYAN);
        rectangle(0, 0, 1000, 1000);
        setfillstyle(SOLID_FILL, CYAN);
        floodfill(1, 1, CYAN);

        ///For road
        setcolor(WHITE);
        rectangle(roadX1, roadY1, roadX2, roadY2);
        setfillstyle(SOLID_FILL, DARKGRAY);  /// Sets the current fill pattern and fill color
        floodfill(roadX1+1, roadY1+1, WHITE);  ///Fill an enclosed area

        ///Lines in road
        for(int i=0; i<450; i+=105)
        {
            rectangle(roadX1+90, 10+i+roadLineY, roadX2-90, 50+i+roadLineY);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(291, 11+i+roadLineY, WHITE);
        }

        /// For repeat road lines
        roadLineY += 15;
        if(roadLineY > 500)
            roadLineY = - 500;

        ///For life and points label
        settextstyle(BOLD_FONT, 0, 2);
        outtextxy(10, 10,"LIFE:");
        outtextxy(10, 40,"POINTS:");

        ///Drawing circle for life
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, RED);
        switch(life)
        {
        case 0:
            ///Exit when life is no longer
            delay(3000);
            exit(0);
        case 1:
            circle(90, 20, 6);
            floodfill(91, 21, WHITE);
            break;
        case 2:
            circle(90, 20, 6);
            floodfill(91, 21, WHITE);
            circle(110, 20, 6);
            floodfill(111, 21, WHITE);
            break;
        case 3:
            circle(90, 20, 6);
            floodfill(91, 21, WHITE);
            circle(110, 20, 6);
            floodfill(111, 21, WHITE);
            circle(130, 20, 6);
            floodfill(131, 21, WHITE);
            break;
        }

        ///Display points
        outtextxy(100, 40, pointBuffer);

        ///Body of car
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, RED);
        rectangle(carX1+carX, carY1+15, carX2+carX, carY2+5);
        floodfill(301+carX, carY1+16, BLACK);

        setfillstyle(SOLID_FILL, GREEN);
        rectangle(carX1+5+carX, carY1+20, (carX2-5)+carX, carY2);
        floodfill(306+carX, carY1+21, BLACK);

        ///Front of car
        setfillstyle(SOLID_FILL, BROWN);
        rectangle(carX1+5+carX, carY1, (carX2-5)+carX, carY2-55);
        floodfill(306+carX, carY1+1, BLACK);

        ///Car wheels
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(carX1+5+carX, carY1+7, 90, 270, 6);
        pieslice(carX1+37+carX, carY1+7, 270, 90, 5);

        ///Enemy car 1
        CreateNMoveEnemyCar(350, -50, enemyFast, RED, GREEN);
        if (enemyFast >= (carY1 + 50))
        {
            switch(carX + carX1)
            {
            case (350 - (carX2-carX1)) ... (350 + enemyCarWidth):
                life--;
                delay(2000);
                enemyFast = - 10;
            }
        }
        ///Enemy car 2
        CreateNMoveEnemyCar(300, -100, enemyNormal, BLUE, BROWN);
        if (enemyNormal >= (carY1 + 100))
        {
            switch(carX + carX1)
            {
            case (300 - (carX2-carX1)) ... (300 + enemyCarWidth):
                life--;
                delay(2000);
                enemyNormal = - 10;
            }
        }
        ///Enemy car 3
        CreateNMoveEnemyCar(250, -30, enemySlow, YELLOW, CYAN);
        if (enemySlow >= (carY1 + 30))
        {
            switch(carX + carX1)
            {
            case (250 - (carX2-carX1)) ... (250 + enemyCarWidth):
                life--;
                delay(2000);
                enemySlow = - 10;
            }
        }

        enemyNormal += 5;
        enemyFast += 8;
        enemySlow += 3;

        /// For repeat enemy cars
        if (enemyNormal > getmaxy() + 50)
        {
            point += 3;
            itoa(point, pointBuffer, 10);
            enemyNormal = - 50;
        }

        if (enemyFast > getmaxy() + 100)
        {
            point += 5;
            itoa(point, pointBuffer, 10);
            enemyFast = - 100;
        }

        if (enemySlow > getmaxy() + 30)
        {
            point += 1;
            itoa(point, pointBuffer, 10);
            enemySlow = - 30;
        }

        /// For car movement
        if(GetAsyncKeyState(VK_LEFT))
        {
            if ((carX + carX1) >= roadX1)
                carX -= carSpeed;
        }
        else if(GetAsyncKeyState(VK_RIGHT))
        {
            if ((carX + carX1 + (carX2-carX1)) <= roadX2)
                carX += carSpeed;
        }

        ///Display game over when life is no longer
        if (life == 0)
        {
            setcolor(WHITE);
            settextstyle(BOLD_FONT, 0, 5);
            outtextxy(roadX1-10, roadY2-280, "Game Over");
        }

        delay(100);
    }

    closegraph();

    return 0;
}
