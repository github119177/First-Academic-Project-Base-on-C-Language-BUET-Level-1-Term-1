
#include "iGraphics.h"
#define pi 3.1416
#include<time.h>
#include<math.h>



#define totalBricks 36
#define totalBricks3 25
#define totalBricks2  20
#define screenHight 650
#define screenWide 1200
#define yAxisMergin 50
#define tetadefine 90
#define pi 3.1416




int score=0;
int scorelevel2=0;
int level=1;
  static int  a=25;


int help;
int home;

int c=0;
int c2=0;


char sc[10];
char sc2[10];



char s[10];
char s2[10];
char ch;
int life =  0;
int life2 =  0;

int l = 4;
//int l2= 5;





int x,y;
char str[106]="S";
int bcindex=0;
int red=0,blue=250,green=0;
int xball=(int)screenWide/2;
int yball= yAxisMergin;
int radiuscircle=10;

bool musicon =true;
int xboard=xball-50;
int yboard=yball-20;
int dxboard=100;
int dyboard=10;
bool isstated =false;
int mode=0;

static int v=10;
int teta =tetadefine;
float  dx =(float)v*cos(teta*pi/180);
float  dy =(float)v*sin(teta*pi/180);



struct buttoncoordinate
{
    int x;
    int y;
};






struct brickstructure
{
    int x;
    int y;
    int dx=25;
    int dy=25;
    bool show = true;
    int red;
    int green;
    int blue;
};

   struct brickstructure Bricks[totalBricks];
   struct brickstructure Bricks2[totalBricks2];
   struct brickstructure Bricks3[totalBricks3];
//int teta =45;
//int velocity=10;
//dx=velocity*cos(teta);
//dy=velocity*sin(teta);



void ballchange();
void restartball();
void definebricks();
char *int_to_string(int n,char *s);


void iDraw()
{




    if(mode==0)
    {

        iClear();
        iShowBMP(0,0,"bin\\7.bmp");

        //   iShowBMP2(50,100,menu,255);
        iSetColor(250,250,250);
        iFilledRectangle(480,500,240,50);
        iSetColor(0,0,0);
        iText(530,520,"PLAY GAME",GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(600,400,st);
        iSetColor(250,250,250);
        iFilledRectangle(480,400,240,50);
        iSetColor(0,0,0);
        iText(530,420,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(250,250,250);
        iFilledRectangle(480,300,240,50);
        iSetColor(0,0,0);
        iText(560,320,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);





        if(help==1)
        {
            iClear();
            iShowBMP(0,0,"bin\\10.bmp");
            iRectangle(1100,4,80,20);
            iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);



            if(home==1)
            {

                iShowBMP(0,0,"bin\\7.bmp");

                //   iShowBMP2(50,100,menu,255);
                iSetColor(250,250,250);
                iFilledRectangle(480,500,240,50);
                iSetColor(0,0,0);
                iText(530,520,"PLAY GAME",GLUT_BITMAP_TIMES_ROMAN_24);
                //iText(600,400,st);
                iSetColor(250,250,250);
                iFilledRectangle(480,400,240,50);
                iSetColor(0,0,0);
                iText(530,420,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
                iSetColor(250,250,250);
                iFilledRectangle(480,300,240,50);
                iSetColor(0,0,0);
                iText(560,320,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);

            }

        }



    }







    if(mode==1)
    {

        if(level==1)
        {


        iClear();

        //iShowBMP(0,0,"bin\\4.bmp");
        iSetColor(red,green,blue);
        iFilledCircle(xball,yball,radiuscircle,1000);
        iSetColor(0,0,250);
        iFilledRectangle(xboard,yboard,dxboard,dyboard);
        iRectangle(1100,4,80,20);
        iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


        //place your drawing codes her
        for(int i=0; i<totalBricks; i++)
        {
            if(Bricks[i].show)
            {

                iSetColor(Bricks[i].red,Bricks[i].green,Bricks[i].blue);



                iFilledRectangle(Bricks[i].x,Bricks[i].y,Bricks[i].dx,Bricks[i].dy );
                //SetColor(0,250,0);
                //iText(Bricks[i].x +25,Bricks[i].y+15,str);
            }
        }


        //score=0;

        int_to_string(score,sc);

        iText( 6,10,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText( 100,10,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        // l=4;

        int_to_string(l,s);
        iText( 600,10,"LIFE :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText( 700,10,s,GLUT_BITMAP_TIMES_ROMAN_24);



        if(c==totalBricks)

        {
            //iShowBMP(0,0,"bin\\10.bmp");
            iClear();

            iSetColor(0,250,0);
            iText(530,520,"LEVEL COMPLETE ",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(250,0,0);
            iText(480,420,"PRESS 'g'  TO GO LEVEL 2",GLUT_BITMAP_TIMES_ROMAN_24);




        }

        if(life==4)

        {
            //iShowBMP(0,0,"bin\\9.bmp");
            iClear();

            iSetColor(0,250,0);
            iText(530,520,"GAME OVER ",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(250,0,0);
            iText(480,420,"PRESS 'b'  TO GO LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);

        }
    }





    if(level==2)
    {

            iClear();

        //iShowBMP(0,0,"bin\\4.bmp");
        iSetColor(red+10,green,blue);
        iFilledCircle(xball,yball,radiuscircle,1000);
        iSetColor(69,50,250);
        iFilledRectangle(xboard,yboard,dxboard,dyboard);
        iRectangle(1100,4,80,20);
        iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


        //place your drawing codes her


        for(int i=0; i<totalBricks2; i++)
        {
            if(Bricks2[i].show)
            {

                iSetColor(Bricks2[i].red,Bricks2[i].green,Bricks2[i].blue);



                iFilledRectangle(Bricks2[i].x,Bricks2[i].y,Bricks2[i].dx,Bricks2[i].dy );
                //SetColor(0,250,0);
                //iText(Bricks[i].x +25,Bricks[i].y+15,str);
            }
        }


        //score=0;

        int_to_string(score,sc);

        iText( 6,10,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText( 100,10,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        // l=4;

        int_to_string(l,s);
        iText( 600,10,"LIFE :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText( 700,10,s,GLUT_BITMAP_TIMES_ROMAN_24);



        if(c==totalBricks2)

        {
            //iShowBMP(0,0,"bin\\10.bmp");
            iClear();

            iSetColor(0,250,0);
            iText(530,520,"LEVEL COMPLETE ",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(250,0,0);
            iText(480,420,"PRESS 'g'  TO GO LEVEL 3",GLUT_BITMAP_TIMES_ROMAN_24);




        }

        if(life==5)

        {
            //iShowBMP(0,0,"bin\\9.bmp");
            iClear();

            iSetColor(0,250,0);
            iText(530,520,"GAME OVER ",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(250,0,0);
            iText(480,420,"PRESS 'b'  TO GO LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);

        }


    }
      if(level==3)
    {

            iClear();

        //iShowBMP(0,0,"bin\\4.bmp");
        iSetColor(red+10,green,blue);
        iFilledCircle(xball,yball,radiuscircle,1000);
        iSetColor(69,50,250);
        iFilledRectangle(xboard,yboard,dxboard,dyboard);
        iRectangle(1100,4,80,20);
        iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


        //place your drawing codes her


        for(int i=0; i<totalBricks3; i++)
        {
            if(Bricks3[i].show)
            {

                iSetColor(Bricks3[i].red,Bricks3[i].green,Bricks3[i].blue);



                iFilledRectangle(Bricks3[i].x,Bricks3[i].y,Bricks3[i].dx,Bricks3[i].dy );
                //SetColor(0,250,0);
                //iText(Bricks[i].x +25,Bricks[i].y+15,str);
            }
        }


        //score=0;

        int_to_string(score,sc);

        iText( 6,10,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText( 100,10,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        // l=4;

        int_to_string(l,s);
        iText( 600,10,"LIFE :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText( 700,10,s,GLUT_BITMAP_TIMES_ROMAN_24);



        if(c==totalBricks3)

        {
            //iShowBMP(0,0,"bin\\10.bmp");
            iClear();

            iSetColor(0,250,0);
            iText(530,520,"LEVEL COMPLETE ",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(250,0,0);
            iText(480,420,"PRESS 'g'  TO GO LEVEL 4",GLUT_BITMAP_TIMES_ROMAN_24);




        }

        if(life==4)

        {
            //iShowBMP(0,0,"bin\\9.bmp");
            iClear();

            iSetColor(0,250,0);
            iText(530,520,"GAME OVER ",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(250,0,0);
            iText(480,420,"PRESS 'b'  TO GO LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);

        }


    }




    }





}












void definebricks()
{

    int sumx = 100;
    int sumy = 450;
    for(int i=0; i<totalBricks; i++)
    {
        Bricks[i].red = rand() %255;
        Bricks[i].green= rand() %255;
        Bricks[i].blue= rand() %255;
        Bricks[i].x =sumx;
        Bricks[i].y =sumy;
        sumx+=120;
        if(sumx>1120)
        {
            sumx=150;
            sumy+=50;
        }
    }

}



void definebricks2()
{

    int sumx = 100;
    int sumy = 350;
    for(int i=0; i<totalBricks2; i++)
    {


        Bricks2[i].red = rand() %255;
        Bricks2[i].green= rand() %255;
        Bricks2[i].blue= rand() %255;
        Bricks2[i].x =sumx;
        Bricks2[i].y =sumy;
        sumx+=130;
        if(sumx>1120)
        {
            sumx=150;
            sumy+=50;
        }
    }

}

void definebricks3()
{

    int sumx = 100;
    int sumy = 350;
    for(int i=0; i<totalBricks3; i++)
    {


        Bricks3[i].red = rand() %255;
        Bricks3[i].green= rand() %255;
        Bricks3[i].blue= rand() %255;
        Bricks3[i].x =sumx;
        Bricks3[i].y =sumy;
        sumx+=130;
        if(sumx>1120)
        {
            sumx=150;
            sumy+=50;
        }
    }

}




char *int_to_string(int n,char *s)
{
    if(n<10)
    {
        *s='0'+n;
        *++s=0;
        return s;
    }
    s=int_to_string(n/10,s);
    *s='0'+n%10;
    *++s=0;
    return s;
}




void ballchange()
{
    if(isstated)
    {

        xball+=dx;
        yball+=dy;
        if(xball>=screenWide-10)
        {
            dx*=(-1);
        }
        if(xball<10)
        {
            dx+=10;
        }


        if(yball>=screenHight -20 )
        {
            dy*=(-1);

        }
if(level==1)
{

            for(int i=0; i<totalBricks; i++)
        {
            if(Bricks[i].show)
            {

                if(xball >= Bricks[i].x -10 && xball <= Bricks[i].x + Bricks[i].dx +10 )
                {
                    if(yball >= Bricks[i].y  -10  &&  yball <= Bricks[i].y + Bricks[i].dy +10)
                    {
                        dy*=(-1);
                        Bricks[i].show =false;
                        score++;
                        c++;
                    }
                }


                  else  if(yball >= Bricks[i].y-10&& yball <= Bricks[i].y + Bricks[i].dy +10)

                        {

                            if(xball >= Bricks[i].x -10 && xball <= Bricks[i].x + Bricks[i].dx+10)
                            {
                                dx*=(-1);
                                Bricks[i].show =false;
                                score++;
                                c++;

                            }
                        }




                        if(xball>=xboard-10 && xball<= xboard + dxboard +10 && yball >= yboard +10&& yball<=yboard +dyboard +10)
                        {
                            teta=dxboard +xboard +40-xball;
                            dx=10*cos(teta*pi /180);
                            dy=10*sin(teta*pi /180);
                        }


            }
        }
        }
if(level==2)
{

        for(int i=0; i<totalBricks2; i++)
        {
            if(Bricks2[i].show)
            {

                if(xball >= Bricks2[i].x -10 && xball <= Bricks2[i].x + Bricks2[i].dx +10 )
                {
                    if(yball >= Bricks2[i].y  -10  &&  yball <= Bricks2[i].y + Bricks2[i].dy +10)
                    {
                        dy*=(-1);
                        Bricks2[i].show =false;
                        score++;
                        c++;
                    }
                }


                  else  if(yball >= Bricks2[i].y-10&& yball <= Bricks2[i].y + Bricks2[i].dy +10)

                        {

                            if(xball >= Bricks2[i].x -10 && xball <= Bricks2[i].x + Bricks2[i].dx+10)
                            {
                                dx*=(-1);
                                Bricks2[i].show =false;
                                score++;
                                c++;

                            }
                        }



                        if(xball>=xboard-10 && xball<= xboard + dxboard +10 && yball >= yboard +10&& yball<=yboard +dyboard +10)
                        {
                            teta=dxboard +xboard +40-xball;
                            dx=20*cos(teta*pi /180);
                            dy=20*sin(teta*pi /180);
                        }


            }
        }
}

if(level==3)
{

            for(int i=0; i<totalBricks3; i++)
        {
            if(Bricks3[i].show)
            {

                if(xball >= Bricks3[i].x -10 && xball <= Bricks3[i].x + Bricks3[i].dx +10 )
                {
                    if(yball >= Bricks3[i].y  -10  &&  yball <= Bricks3[i].y + Bricks3[i].dy +10)
                    {
                        dy*=(-1);
                        Bricks3[i].show =false;
                        score++;
                        c++;
                    }
                }


                  else  if(yball >= Bricks3[i].y-10&& yball <= Bricks3[i].y + Bricks3[i].dy +10)

                        {

                            if(xball >= Bricks3[i].x -10 && xball <= Bricks3[i].x + Bricks3[i].dx+10)
                            {
                                dx*=(-1);
                                Bricks3[i].show =false;
                                score++;
                                c++;

                            }
                        }




                        if(xball>=xboard-10 && xball<= xboard + dxboard +10 && yball >= yboard +10&& yball<=yboard +dyboard +10)
                        {
                            teta=dxboard +xboard +40-xball;
                            dx=10*cos(teta*pi /180);
                            dy=10*sin(teta*pi /180);
                        }


            }
        }
        }
/*

xball+=dx;
        yball+=dy;
        if(xball>=screenWide-10)
        {
            dx*=(-1);
        }
        if(xball<10)
        {
            dx+=10;
        }


        if(yball>=screenHight -20 )
        {
            dy*=(-1);

        }

*/

/*
                        if(xball>=xboard-10 && xball<= xboard + dxboard +10 && yball >= yboard +10&& yball<=yboard +dyboard +10)
                        {
                            teta=dxboard +xboard +40-xball;
                            dx=v*cos(teta*pi /180);
                            dy=v*sin(teta*pi /180);
                        }*/


                           if(yball<yboard)
                            {



                                bool isstated=false;
                                restartball();


                            }
                    }

                }



        void restartball()
        {

            life++;
            life2++;

            l--;
           // l2--;


            xball=(int)screenWide/2;
            yball= yAxisMergin;

            dx*=(-1);
            dy*=(-1);
            xboard=xball -50;
            yboard=yball -20;
            isstated=false;


        }

           void restartball2()
        {




            xball=(int)screenWide/2;
            yball= yAxisMergin;

            //dx=7;
            //dy=5;
            xboard=xball -50;
            yboard=yball -20;
            isstated=false;


        }





        /*
        	function iMouseMove() is called when the user presses and drags the mouse.
        	(mx, my) is the position where the mouse pointer is.
        	*/

        void iMouseMove(int mx, int my)
        {
            printf("x = %d, y= %d\n",mx,my);
            //place your codes here
        }

        /*
        	function iMouse() is called when the user presses/releases the mouse.
        	(mx, my) is the position where the mouse pointer is.
        	*/
        void iMouse(int button, int state, int mx, int my)
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {

                if(mx>=480 && my>=500 && mx<=720 && my<=550 && mode==0)
                {
                    mode=1;
                }


                if(mx>=480 && my>=300 && mx<=720 && my<=350 && mode==0)
                {
                    help=1;
                }


                if(mx>=1100 && my>=4 && mx<=1180 && my<=24 && mode==1)
                {
                    mode=0;
                }

                if(mx>=1100 && my>=4 && mx<=1180 && my<=24 &&  ( mode==0 || mode== 1) && help==1)
                {
                    home=1;
                }
                //place your codes here
                //	printf("x = %d, y= %d\n",mx,my);
                x += 10;
                y += 10;
            }
            if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {

                //place your codes here
                x -= 10;
                y -= 10;
            }
        }

        /*
        	function iKeyboard() is called whenever the user hits a key in keyboard.
        	key- holds the ASCII value of the key pressed.
        	*/


        void iKeyboard(unsigned char key)
        {
            if (key == 'q')
            {
                exit(0);
            }

            else if (key == ' ' || key== 's')
            {

                {
                    if(!isstated)
                    {
                        isstated=true;
                    }
                }
            }

            else if (key == 'g')
            {


                    c=0;
                    //l=5;
                    //score=0;
                    a=5;


                    for(int i=0;i<totalBricks ;i++)
                    {
                        Bricks[i].show=true;
                    }
                    level++;
                // isstated=false;
                restartball2();

            }
            else if (key == 'b')
            {

                {
                   level=1;
                   life=0;
                   l=4;
                   score=0;
                   /*for(int i=0;i<totalBricks ;i++)
                    {
                        Bricks[i].show=true;
                    }
                    for(int i=0;i<totalBricks2 ;i++)
                    {
                        Bricks2[i].show=true;
                    }*/
                }

            }
            //place your codes for other keys here
        }

        /*
        	function iSpecialKeyboard() is called whenver user hits special keys like-
        	function keys, home, end, pg up, pg down, arraows etc. you have to use
        	appropriate constants to detect them. A list is:
        	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
        	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
        	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
        	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
        	*/

        void iSpecialKeyboard(unsigned char key)
        {

            if (key == GLUT_KEY_END)
            {
                exit(0);
            }
            if (key == GLUT_KEY_LEFT)
            {
                if(xboard>0)
                {
                    xboard-=50;
                    if(!isstated)
                    {
                        xball -=50;
                    }
                }
            }
            if (key == GLUT_KEY_RIGHT)
            {
                if(xboard<screenWide-dxboard)
                {
                    xboard+=50;
                    if(!isstated)
                    {
                        xball+=50;
                    }
                }
            }

            //place your codes for other keys here
        }


        int main()

        {
            definebricks();
            definebricks2();
            definebricks3();

            iSetTimer(a,ballchange );

            iInitialize(screenWide,screenHight,"DX BALL GAME");


            return 0;
        }

