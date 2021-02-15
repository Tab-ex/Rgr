#include "GL/freeglut.h"
#include "math.h"
#include "ctime"
//#include "stdafx.h"
#include <iostream>
#include <vector>



clock_t curTime, startTime;

struct Figure
{
    float r, g, b;
    float x, y;
    float w, e;
};

std::vector<Figure> cats;

Figure circle1;
Figure circle2;
Figure circle3;
Figure car1;
Figure sheap1;
Figure Cat1;
Figure drawMario1;
Figure fon1;
Figure sky;
Figure wood1;
Figure hause1;
Figure цветок1;
Figure graund;
Figure graund1 = {0.1, 0.1, 0.1, -1.375,-.75,};
Figure see;

void renderScene(void);
void animateScene(int value);
void drawMario(Figure f);
void fon(Figure f);
void hause(Figure f);
void wood(Figure f);
void цветок(Figure f);
void Cat(Figure f);
void car(Figure f);
void sheap(Figure f);
void circle(Figure f);
void animation_kolo();
void animation_elips(void);
void animation_quad();
void vertical();
void cats1();

void initForest()
{
    //stand(10);
    srand(clock());
    Figure f;
    for (int i = 0;i < 50;i++)
    {
        f.x = .1 * (rand() % 100) - 5;
        f.y = .1 * (rand() % 10) - 3;
        f.g = .01 * (rand() % 10) - .1;
        f.b = .1 * (rand() % 10) - .3;
        cats.push_back(f);
    }
}

int main(int argc, char* argv[])
{
    initForest();
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Узри сие творение!");
    glutDisplayFunc(renderScene);
    glutTimerFunc(1000 / 60, animateScene, 1);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    int a = 0;
     
    sky.b = .3;
   
    float PI = 3.14;
   
    glPushMatrix();
    fon1.r = 1;
    fon1.g = 1;
    fon1.b = 1;

    fon(fon1);

    switch (a)
    {
    case 0:
        drawMario1 = { .1,.1,.1 };
        drawMario(drawMario1);
        break;
    case 1:
        hause(hause1);
        wood(wood1);
        цветок(цветок1);
        break;
    case 2:
        cats1;//(Cat1);
        //sheap(sheap1);
        //car(car1);
        break;
    case 3:
        circle1.r = 0.1;
        circle1.g = 0.6;
        circle1.b = 0;
        circle2.r = 0.6;
        circle2.g = 0.;
        circle2.b = 0;
        glScalef(0.1, 0.1, 1);
        circle(circle1);
        break;
    case 4:
        //animation_elips();
         //animation_kolo();
        animation_quad();
        break;

    case 5:
        circle1.r = 0.1;
        circle1.g = 0.6;
        circle1.b = 0;
        circle2.r = 0.6;
        circle2.g = 0.;
        circle2.b = 0;
        glScalef(0.1, 0.1, 1);
        circle(circle1);
        glTranslated(.0, 2, 0);
        circle(circle2);
        break;
    case 6:
        glPushMatrix();
       
        
        Cat(Cat1);
        fon(sky);
        animation_elips();

        glScaled(5, 5, 1);
        graund.g = .8;
        graund.y =  -.375;
        fon(graund);
        see.b = 1;
        see.x = 1;
        see.y = -1;
        circle(see);
        graund1.r = .3;
        graund1.g = .3;
        graund1.b = .3;
        graund1.x = -.7;
        graund1.y = -0.368;
      //  fon(graund1);
       
        glPushMatrix();
        glScalef(0.5,.5, 1);
        glTranslated(.35, 0,0);
        hause(hause1);
        glPopMatrix();
       
        //glTranslated(-2, -.4, 0);
        //
        //float PI = 3.14;
        curTime = clock();
        float phi = curTime * 0.001;
        int j = 300;
        //glScalef(0.6, 0.6, 1);
       
            float x = sin(PI * j / 15 + phi) * 2.6;
            float y = cos(1 - PI * j / 15 + phi)*2;
            curTime = clock() - startTime;
        //
        //    glPushMatrix();
        //    glTranslated(-0.1, 0, 0);
            car1.x = -4;
            car1.y = y-.366;
            car1.r = x;
            car1.g = y;
            graund1.w = 3;
            graund1.e = 3;
             // glTranslated(2, 0, 0);
            if (x <= -0.4) {
                fon(graund1);
                car(car1);
            }
            else {
                car(car1);
             //   fon(graund1);
            }
          // glPopMatrix();
       
        
        break;
    }

    glPopMatrix();
   glutSwapBuffers();

}

void animation_quad()
{

    float PI = 3.14;
    curTime = clock();
    float phi = curTime * 0.001;
    int j = 1;
    glScalef(0.01, 0.01, 1);
    while (j < 2) {
        curTime = clock() - startTime;

        float x = 0;
        float y = 0;

        if (curTime < 1000) {
            x = curTime * 0.001;
        }
        else {
            if (curTime < 2000) {
                x = (1000) * 0.001;
                y = (curTime - 1000) * 0.001;
            }
            else {
                if (curTime < 3000) {
                    x = -(curTime - 3000) * 0.001;
                    y = (1000) * 0.001;
                }
                else {
                    if (curTime < 4000) {
                        x = 0;
                        y = -(curTime - 4000) * 0.001;
                    }
                    else {
                        startTime = clock();
                    }
                }
            }
            glTranslated(x, y, 0);

            circle3.r = x;
            circle3.g = y;

            circle(circle3);
            j++;
        }
    }
}

void animation_kolo()
{
    float PI = 3.14;
    curTime = clock();
    float phi = curTime * 0.001;
    int j = 1;
    glScalef(0.1, 0.1, 1);
    while (j < 20) {
        float x = sin(PI * j / 15 + phi);
        float y = cos(1 - PI * j / 15 + phi);
        curTime = clock() - startTime;

        glTranslated(x, y, 0);

        circle3.r = x;
        circle3.g = y;

        circle(circle3);
        j++;
    }
}

void vertical() 
{

}

void animation_elips()
{
    glPushMatrix;
    
    glScaled(.2, .2, 1);
    curTime = clock();
    float phi = curTime * 0.001;
    int j = 1;
   
  
    
        curTime = clock() - startTime;

        float x = 0;
        float y = 0;

        float r1 = 5;
        float r2 = 4;
        x = r1 * sin(phi);
        y = r2 * cos(phi);

        /*if (j % 10 == 0)
        {
            
        }
        else
        {
            x = r1* sin(phi);
            y = r2 * cos(phi);
        }*/
        //glTranslated(x, y, 0);

        circle3.r = .8;
        circle3.g = .8;
        circle3.b = .01;
        circle3.x = x;
        circle3.y = y;


        circle(circle3);
        glPopMatrix;
       
 }


void animateScene(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, animateScene, 1);
}

void circle(Figure f)
{
    float PI = 3.14;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(f.r, f.g, f.b);
    glVertex3f(f.x, f.y, 0);
    for (float i = 0; i < 2 * PI; i += PI / 4)
        glVertex2f(cos(i)+f.x, sin(i)+f.y);
    glEnd();
}

void car(Figure f)
{
    glPushMatrix();
    glTranslated(f.x, f.y, 0);
    glBegin(GL_QUADS);
    glColor3f(0,0, 0);
    glVertex2f(.875, -.875);
    glVertex2f(.875, -1);
    glVertex2f(.75, -1);
    glVertex2f(.75, -.875);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0, 0);
    glVertex2f(.25, -.875);
    glVertex2f(.25, -1);
    glVertex2f(.125, -1);
    glVertex2f(.125, -.875);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.2+f.r, .2+f.g, 6+f.b);
    glVertex2f(.125, -.875);
    glVertex2f(.125, -.625);
    glVertex2f(.25, -.375);
    glVertex2f(.75, -.375);
    glVertex2f(.875, -.675);
    glVertex2f(.875, -.875);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, .0);
    glVertex2f(.625, -.625);
    glVertex2f(.75, -.625);
    glVertex2f(.75, -.75);
    glVertex2f(.625, -.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, .0);
    glVertex2f(.25, -.625);
    glVertex2f(.375, -.625);
    glVertex2f(.375, -.75);
    glVertex2f(.25, -.75);
    glEnd();
    glPopMatrix();
}

void sheap(Figure f)
{
    glBegin(GL_QUADS);
    glColor3f(.5 + f.r, .3 + f.g, .3 + f.b);
    glVertex2f(.125, .125);
    glVertex2f(.875, .125);
    glVertex2f(1, .25);
    glVertex2f(0, .25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.5 + f.r, .3 + f.g, .3 + f.b);
    glVertex2f(.375, .25);
    glVertex2f(.375, .875);
    glVertex2f(.5, .875);
    glVertex2f(.5, .25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.3, .3, 5);
    glVertex2f(.875, .5);
    glVertex2f(.5, .875);
    glVertex2f(.5, .25);
    glEnd();
}

void fon(Figure f)
{
    glPushMatrix();
    glScaled(f.w, f.e, 1);
    glTranslated(f.x, f.y, 0);
    glBegin(GL_POLYGON);
    glColor3f(f.r, f.g, f.b);  //фон
    glVertex2f(-1 + f.x, 1 + f.y);
    glVertex2f(1 + f.x, 1 + f.y);
    glVertex2f(1 + f.x, -1 + f.y);
    glVertex2f(-1 + f.x, -1 + f.y);
    glEnd();
    glPopMatrix();
}

void Cat(Figure f)
{

    glBegin(GL_TRIANGLES);
    glColor3f(.3 + f.r, .3 + f.g, .3 + f.b);
    glVertex2f(-.75, .75);
    glVertex2f(-.625, .875);
    glVertex2f(-.75, 1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.3 + f.r, .3 + f.g, .3 + f.b);
    glVertex2f(-.25, .75);
    glVertex2f(-.3755, .875);
    glVertex2f(-.25, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.3 + f.r, .3 + f.g, .3 + f.b);
    glVertex2f(-.625, -1);
    glVertex2f(-1, .125);
    glVertex2f(-.5, .625);
    glVertex2f(0, .125);
    glVertex2f(-.375, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.4, .4, .4);
    glVertex2f(-.5, .125);
    glVertex2f(-.875, .625);
    glVertex2f(-.625, .875);
    glVertex2f(-0.375, .875);
    glVertex2f(-.125, .625);
    glEnd();
}

void hause(Figure f)
{
    // дымоход
    glBegin(GL_QUADS);
    glColor3f(.60, .3, 1);
    glVertex2f(-.375, 1);
    glVertex2f(-.25, 1);
    glVertex2f(-.25, .75);
    glVertex2f(-.375, .75);
    glEnd();
    // крыша
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0);
    glVertex2f(-1, .625);
    glVertex2f(-.5, 1);
    glVertex2f(0, .625);
    glEnd();
    // основа
    glBegin(GL_QUADS);
    glColor3f(.0 + f.r, 1 + f.g, 1 + f.b);
    glVertex2f(-.125, .625);
    glVertex2f(-.125, .0);
    glVertex2f(-.875, .0);
    glVertex2f(-.875, .625);
    glEnd();
    // дверь
    glBegin(GL_QUADS);
    glColor3f(.60, 1, 1);
    glVertex2f(-.5, .375);
    glVertex2f(-.25, .375);
    glVertex2f(-.25, .0);
    glVertex2f(-.5, .0);
    glEnd();
    // окно
    glBegin(GL_QUADS);
    glColor3f(.60, 1, .5);
    glVertex2f(-.81, .375);
    glVertex2f(-.688, .375);
    glVertex2f(-.688, .25);
    glVertex2f(-.81, .25);
    glEnd();


}

void wood(Figure f)
{
    glBegin(GL_POLYGON);
    glColor3f(.3, .5, .3);
    glVertex2f(0, .625);
    glVertex2f(0, .75);
    glVertex2f(0.25, 1);
    glVertex2f(0.625, 1);
    glVertex2f(1, .625);
    glVertex2f(1, .5);
    glVertex2f(0.125, .5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.3 + f.r, .3 + f.g, .3 + f.b);
    glVertex2f(0.375, .5);
    glVertex2f(0.625, .5);
    glVertex2f(0.625, .125);
    glVertex2f(0.75, 0);
    glVertex2f(.125, 0);
    glVertex2f(0.25, .125);
    glVertex2f(0.325, .125);
    glEnd();


}

void цветок(Figure f)
{
    glBegin(GL_POLYGON);
    glColor3f(0 + f.r, 1 + f.g, 0 + f.b);
    glVertex2f(.5, -.375);
    glVertex2f(.375, -.875);
    glVertex2f(.375, -1);
    glVertex2f(.25, -1);
    glVertex2f(.25, -.875);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(.375, -.875);
    glVertex2f(.5, -.75);
    glVertex2f(.75, -.875);

    glEnd();

    glBegin(GL_QUADS);// большой
    glColor3f(1, 1, 0);
    glVertex2f(.375, 0);
    glVertex2f(.75, -.25);
    glVertex2f(.5, -.625);
    glVertex2f(.125, -.375);
    glEnd();


    glBegin(GL_QUADS);// среднипй
    glColor3f(1, 0, 1);
    glVertex2f(.25, -.25);
    glVertex2f(.5, -.125);
    glVertex2f(.625, -.375);
    glVertex2f(.375, -.5);
    glEnd();

    glBegin(GL_QUADS); // центр
    glColor3f(1, 1, 1);
    glVertex2f(.375, -.25);
    glVertex2f(.5, -.25);
    glVertex2f(.5, -.375);
    glVertex2f(.375, -.375);
    glEnd();
}

void drawMario(Figure f)
{
    // glTranslated(1.5, 0, 0);
    glBegin(GL_POLYGON);// голова
    glColor3f(.76, .76, .56);
    glVertex2f(-.5, .125);//15
    glVertex2f(.25, .125);//84
    glVertex2f(.25, .625);//85
    glVertex2f(.125, .625);//86
    glVertex2f(.125, .75);//87
    glVertex2f(-.75, .75);//69
    glVertex2f(-.75, 0.375);//76
    glVertex2f(-.625, 0.5);//73
    glEnd();

    glBegin(GL_POLYGON);// нос
    glColor3f(.76, .76, .56);
    glVertex2f(.25, .375);//90
    glVertex2f(.25, .625);//85
    glVertex2f(.375, .625);//87
    glVertex2f(.375, .5);
    glVertex2f(.5, .5);//88
    glVertex2f(.5, .375);//89

    glEnd();

    glBegin(GL_POLYGON);// правое плечё
    glColor3f(.15, 0.075, .0);
    glVertex2f(.125, -.25);//5
    glVertex2f(0, -.25);//6
    glVertex2f(0, 0);//9
    glVertex2f(.375, 0);//42
    glVertex2f(.375, -0.125);//41
    glVertex2f(.5, -0.125);//40
    glVertex2f(.5, -.25);//36
    glVertex2f(.25, -.25);//37
    glVertex2f(.25, -.375);//38
    glVertex2f(.125, -.375);//39
    glEnd();

    glBegin(GL_POLYGON);// левое плечё1
    glColor3f(.15, 0.075, .0);
    glVertex2f(-1, -.125);//48
    glVertex2f(-.875, -.125);//47
    glVertex2f(-.5, -.125);//49

    glVertex2f(-.5, -.25);//16
    glVertex2f(-.625, -.25);//17
    glVertex2f(-.625, -.375);//30
    glVertex2f(-.75, -.375);//31
    glVertex2f(-.75, -.25);//32
    glVertex2f(-1, -.25);//33
    glEnd();

    glBegin(GL_POLYGON);// левое плечё2
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.875, -.125);//47
    glVertex2f(-.875, 0);//46
    glVertex2f(-.5, 0);//50
    glVertex2f(-.5, -.125);//49
    glEnd();

    glBegin(GL_POLYGON);// левое плечё3
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.75, -.0);//45
    glVertex2f(-0.75, 0.125);//44
    glVertex2f(-.5, .125);//15
    glVertex2f(-.5, 0);//50

    glEnd();

    glBegin(GL_POLYGON);// горло
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.375, -.125);//12
    glVertex2f(-.375, .125);//14
    glVertex2f(0, .125);//51
    glVertex2f(0, 0);//9
    glVertex2f(-.125, 0);//10
    glVertex2f(-.125, -.125);//11

    glEnd();

    glBegin(GL_POLYGON);// усы
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.125, .25);//52
    glVertex2f(-.125, .375);//53
    glVertex2f(.375, .375);//58
    glVertex2f(.375, .25);//59
    glEnd();

    glBegin(GL_POLYGON);// усы2
    glColor3f(.15, 0.075, .0);
    glVertex2f(0, .375);//54
    glVertex2f(0, 0.5);//55
    glVertex2f(.125, 0.5);//56
    glVertex2f(.125, .375);//57
    glEnd();

    glBegin(GL_POLYGON);// глаз
    glColor3f(.15, 0.075, .0);
    glVertex2f(0, 0.5);//55
    glVertex2f(0, .75);//60
    glVertex2f(-.125, 0.75);//61
    glVertex2f(-.125, .5);//62
    glEnd();

    glBegin(GL_POLYGON);// висок1
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.375, 0.375);//63
    glVertex2f(-.375, 0.5);//64
    glVertex2f(-.625, 0.5);//73
    glVertex2f(-.625, .375);//72
    glEnd();

    glBegin(GL_POLYGON);// висок2
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.625, 0.625);//71
    glVertex2f(-.75, 0.625);//70
    glVertex2f(-.75, .75);//69
    glVertex2f(-.375, .75);//68
    glVertex2f(-.375, .625);//67
    glEnd();

    glBegin(GL_POLYGON);// висок3
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.625, 0.5);//73a
    glVertex2f(-.5, 0.5);//65
    glVertex2f(-.5, 0.625);//66
    glVertex2f(-.625, 0.625);//71
    glEnd();

    glBegin(GL_POLYGON);// затылок
    glColor3f(.15, 0.075, .0);
    glVertex2f(-.75, 0.375);//76
    glVertex2f(-.625, .375);//72
    glVertex2f(-.625, 0.25);//73
    glVertex2f(-.875, 0.25);//74
    glVertex2f(-.875, 0.625);//75
    glVertex2f(-.75, 0.625);//70
    glEnd();

    glBegin(GL_POLYGON);//шапка
    glColor3f(.85 + f.r, 0.15 + f.g, .0 + f.b);
    glVertex2f(-.625, .875);//83
    glVertex2f(-.75, .875);//81
    glVertex2f(-.75, .75);//69
    glVertex2f(.25, .75);//77
    glVertex2f(.25, 0.875);//78
    glVertex2f(-.125, 0.875);//82
    glVertex2f(-.125, 1);//79
    glVertex2f(-.625, 1);//80


    glEnd();


    glBegin(GL_POLYGON);// левая рука
    glColor3f(.76, .76, .56);
    glVertex2f(-1, -.625);//28
    glVertex2f(-.75, -.625);//29
    glVertex2f(-.75, -.5);//19
    glVertex2f(-.625, -.5);//18
    glVertex2f(-.625, -.375);//30
    glVertex2f(-.75, -.375);//31
    glVertex2f(-.75, -.25);//32
    glVertex2f(-1, -.25);//33
    glEnd();

    glBegin(GL_POLYGON);// правая рука
    glColor3f(.76, .76, .56);
    glVertex2f(.25, -.625);//34
    glVertex2f(.5, -.625);//35
    glVertex2f(.5, -.25);//36
    glVertex2f(.25, -.25);//37
    glVertex2f(.25, -.375);//38
    glVertex2f(.125, -.375);//39
    glVertex2f(.125, -.5);//4
    glVertex2f(.25, -.5);//3

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.15, 0.075, .0);  // левая нога
    glVertex2f(-1, -1);
    glVertex2f(-0.875, -1);
    glVertex2f(-0.875, -0.875);
    glVertex2f(-1, -0.875);
    glEnd();

    glBegin(GL_POLYGON);// левая нога,2
    glColor3f(.15, 0.075, .0);
    glVertex2f(-0.875, -1);
    glVertex2f(-0.5, -1);
    glVertex2f(-0.5, -.75);
    glVertex2f(-0.875, -.75);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(.15, 0.075, .0);  //правая нога
    glVertex2f(.0, -1);
    glVertex2f(0.5, -1);
    glVertex2f(0.5, -.875);
    glVertex2f(0.375, -.875);
    glVertex2f(0.375, -.75);
    glVertex2f(.0, -.75);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.85, 0.15, .0);  //тело1
    glVertex2f(-.125, -.75);//1
    glVertex2f(.25, -.75);//2
    glVertex2f(.25, -.5);//3
    glVertex2f(.125, -.5);//4
    glVertex2f(.125, -.25);//5
    glVertex2f(0, -.25);//6
    glVertex2f(-.125, -.625);//8

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.85, 0.15, .0);  //тело2
    glVertex2f(0, -.25);//6
    glVertex2f(0, 0);//9
    glVertex2f(-.125, 0);//10
    glVertex2f(-.125, -.125);//11
    glVertex2f(-.125, -.625);//8
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.85, 0.15, .0); //тело3
    glVertex2f(-.125, -.125);//11
    glVertex2f(-.375, -.125);//12
    glVertex2f(-.375, -.625);//13
    glVertex2f(-.125, -.625);//8
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.85, 0.15, .0);//тело4
    glVertex2f(-.375, -.125);//12
    glVertex2f(-.375, .125);//14
    glVertex2f(-.5, .125);//15
    glVertex2f(-.5, -.625);//15a
    glVertex2f(-.375, -.625);//13
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.85, 0.15, .0);  //тело5
    glVertex2f(-.625, -.5);//18
    glVertex2f(-.75, -.5);//19
    glVertex2f(-.75, -.75);//20
    glVertex2f(-.375, -.75);//21
    glVertex2f(-.375, -.625);//13
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.85, 0.15, .0);//тело6
    glVertex2f(-.5, -.25);//16
    glVertex2f(-.625, -.25);//17
    glVertex2f(-.625, -.5);//18
    glVertex2f(-.375, -.625);//13
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.06, .1, .1);  //пуговка левая
    glVertex2f(-.5, -.25);//16
    glVertex2f(-.5, -.375);//24
    glVertex2f(-.375, -.375);//23
    glVertex2f(-.375, -.25);//22
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.06, .1, .1);  //пуговка правая
    glVertex2f(-.125, -.25);//25
    glVertex2f(-.125, -.375);//26
    glVertex2f(0, -.375);//27
    glVertex2f(0, -.25);//22
    glEnd();


    glEnd();
   //  glutSwapBuffers();



}

void cats1() {
    glPushMatrix();
    glScalef(.5, .5, 1);
    for (int i = 0; i < cats.size();i++) 
    {
        car(cats[i]);
    }
    glPopMatrix();
};

