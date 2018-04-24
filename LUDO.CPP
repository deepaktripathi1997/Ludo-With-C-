#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include<math.h>
 static int red,blue,green,yellow;    //no of buttons

 int open(int,int);                  //opening the button


 void valondice();//opening and moving the button
 static  void move(int step,int butnum,int temp,int redbutton[8][60],int bluebutton[8][60],int yellowbutton[8][60],int greenbutton[8][60]);

static void movered(int step,int redbutton[8][60],int butnum);
static void mover1(int step,int redbutton[8][60]);
static void mover2(int step,int redbutton[8][60]);
static void mover3(int step,int redbutton[8][60]);
static void mover4(int step,int redbutton[8][60]);


static void moveyellow(int step,int yellowbutton[8][60],int butnum);
static void movey1(int step,int yellowbutton[8][60]);
static void movey2(int step,int yellowbutton[8][60]);
static void movey3(int step,int yellowbutton[8][60]);
static void movey4(int step,int yellowbutton[8][60]);

static void moveblue(int step,int bluebutton[8][60],int butnum);
static void moveb1(int step,int bluebutton[8][60]);
static void moveb2(int step,int bluebutton[8][60]);
static void moveb3(int step,int bluebutton[8][60]);
static void moveb4(int step,int bluebutton[8][60]);

static void movegreen(int step,int greenbutton[8][60],int butnum);
static void moveg1(int step,int greenbutton[8][60]);
static void moveg2(int step,int greenbutton[8][60]);
static void moveg3(int step,int greenbutton[8][60]);
static void moveg4(int step,int greenbutton[8][60]);

 int redbutton[4][60];                 //taking the locaion of each button in red
 int bluebutton[4][60];                //taking the locaion of each button in red
 int greenbutton[4][60];               //taking the locaion of each button in red
 int yellowbutton[4][60];              //taking the locaion of each button in red


 static int startx = 0;
 static int starty = 0;
 int bx[55];
 int by[55];
 int rx[55];
 int ry[55];
 int gx[55];
 int gy[55];
 int yx[55];
 int yy[55];

 int brx[4] ;
 int bry[4] ;
 int bgx[4] ;
 int bgy[4] ;
 int byx[4] ;
 int byy[4] ;
 int bbx[4] ;
 int bby[4] ;

 void initialise();

 int dice(int);

 void start();

static void table();

 void dicenum(int);

 void start()
 {
   int gd=DETECT,gm,x,y;
   initgraph(&gd,&gm,"c:\\TC\\bgi");     //Initializing Graphics Mode

   int midx = getmaxx()/2;
   int midy = getmaxy()/2;

   int i=0;

   cout<<"\nPress Enter To play\n";

   while(!kbhit()){
   setbkcolor(i);
   setcolor(i);
   i++;
   if(i==14)
   i=0;
   settextstyle(10,0,3);
   delay(500);
   outtextxy(midx-100,midy-50," Let's Play Ludo ");
   }
 }

static void table()
 {
   int midx=getmaxx()/2;
   int midy=getmaxy()/2;
   setbkcolor(3);
   setcolor(WHITE);
   setfillstyle(1,2);
   bar(midx-40,midy+40,midx+40,midy-40);

   settextstyle(1,0,2);
   outtextxy(midx-30,midy-20,"Winner");

   for(int i=70;i<220;i=i+30)
  {
     setcolor(YELLOW);
     setfillstyle(9,14);
     fillellipse(midx+i,midy,10,10);

     setcolor(GREEN);
     setfillstyle(9,2);
      fillellipse(midx,midy+i,10,10);

     setcolor(RED);
     setfillstyle(9,4);
     fillellipse(midx-i,midy,10,10);

     setcolor(BLUE);
     setfillstyle(9,1);
     fillellipse(midx,midy-i,10,10);

   }
      setcolor(15);
      setfillstyle(10,15);

      fillellipse(midx+220,midy,10,10);

      fillellipse(midx,midy+220,10,10);

      fillellipse(midx-220,midy,10,10);

      fillellipse(midx,midy-220,10,10);



   for(i=220;i>60;i=i-30)
   {
     setcolor(WHITE);

     setfillstyle(10,15);
     fillellipse(midx+i,midy-30,10,10);

     fillellipse(midx+i,midy+30,10,10);

     setfillstyle(10,15);
     fillellipse(midx-30,midy+i,10,10);

     fillellipse(midx+30,midy+i,10,10);


     setfillstyle(10,15);
     fillellipse(midx-i,midy-30,10,10);

     fillellipse(midx-i,midy+30,10,10);


     setfillstyle(10,15);
     fillellipse(midx-30,midy-i,10,10);

     fillellipse(midx+30,midy-i,10,10);



   }
     setcolor(14);
     setfillstyle(6,14);
     fillellipse(midx+190,midy+30,10,10);


     fillellipse(midx+30,midy+160,10,10);

     setcolor(1);
     setfillstyle(6,1);
     fillellipse(midx+160,midy-30,10,10);
 //    ptr  =  func(root,ptr,midx+160,midy-30,6,1);

     fillellipse(midx+30,midy-190,10,10);
//     ptr  =  func(root,ptr,midx+30,midy-190,6,1);

     setcolor(4);
     setfillstyle(6,4);
     fillellipse(midx-30,midy-160,10,10);
//     ptr  =  func(root,ptr,midx+30,midy-160,6,4);

     fillellipse(midx-190,midy-30,10,10);
//     ptr  =  func(root,ptr,midx-190,midy-30,6,4);

     setcolor(2);
     setfillstyle(6,2);
     fillellipse(midx-160,midy+30,10,10);
//     ptr  =  func(root,ptr,midx-160,midy+30,6,2);

     fillellipse(midx-30,midy+190,10,10);
//     ptr  =  func(root,ptr,midx-30,midy+190,6,2);

     //Red Color
     setfillstyle(8,4);
     bar(midx-230,midy-230,midx-70,midy-70);
     setcolor(12);
     setfillstyle(7,4);
     fillellipse(midx-190,midy-190,10,10);
     fillellipse(midx-110,midy-190,10,10);
     fillellipse(midx-190,midy-110,10,10);
     fillellipse(midx-110,midy-110,10,10);


     //Blue Color
     setfillstyle(8,1);
     bar(midx+230,midy-230,midx+70,midy-70);
     setcolor(9);
     setfillstyle(7,1);
     fillellipse(midx+190,midy-190,10,10);
     fillellipse(midx+110,midy-190,10,10);
     fillellipse(midx+190,midy-110,10,10);
     fillellipse(midx+110,midy-110,10,10);

     //Yellow color	       `
     setfillstyle(8,14);
     bar(midx+230,midy+230,midx+70,midy+70);
     setcolor(15);
     setfillstyle(7,14);
     fillellipse(midx+190,midy+190,10,10);
     fillellipse(midx+110,midy+190,10,10);
     fillellipse(midx+190,midy+110,10,10);
     fillellipse(midx+110,midy+110,10,10);

    //Green Color
     setfillstyle(8,2);
     bar(midx-230,midy+230,midx-70,midy+70);
     setcolor(10);
     setfillstyle(7,2);
     fillellipse(midx-190,midy+190,10,10);
     fillellipse(midx-110,midy+190,10,10);
     fillellipse(midx-190,midy+110,10,10);
     fillellipse(midx-110,midy+110,10,10);



   getch();


  }


  void initialise(){
  int i,j;

  int midx = getmaxx()/2;
  int midy = getmaxy()/2;
  brx[0] = 129; brx[1] = 209 ; brx[2] = 129 ;  brx[3] = 209;
  bry[0] = 49; bry[1] = 49 ; bry[2] = 129 ;  bry[3] = 129;

  bbx[0] = 509; bbx[1] = 429 ; bbx[2] = 509 ;  bbx[3] = 429;
  bby[0] = 49; bby[1] = 49 ; bby[2] = 129 ;  bby[3] = 129;


  byx[0] = 509; byx[1] = 429 ; byx[2] = 509 ;  byx[3] = 429;
  byy[0] = 429; byy[1] = 429 ; byy[2] = 349 ;  byy[3] = 349;


  bgx[0] = 129; bgx[1] = 209 ; bgx[2] = 129 ;  bgx[3] = 209;
  bgy[0] = 429; bgy[1] = 429 ; bgy[2] = 349 ;  bgy[3] = 349;


  //Red Color
	      i=0;
	      j=190;
	      while(i<5){
	      bx[i] = midx + 30;
	      by[i] = midy - j;
	      i++;
	      j = j -30;
	      }
	      j=70;
	      while(i<11){
	      bx[i] = midx + j;
	      by[i] = midy - 30;
	      i++;
	      j=j+30;
	      }
	      bx[i] = midx + 220 ;
	      by[i] = midy ;
	      i++;
	      bx[i] = midx + 220;
	      by[i] = midy + 30;
	      i++;
	      j=190;
	      while(i<18){
	      bx[i] = midx + j;
	      by[i] = midy + 30;
	      i++;
	      j = j-30;
	      }
	      j=70;
	      while( i < 24){
	      bx[i] = midx + 30;
	      by[i] = midy + j;
	      i++;
	      j = j+30;
	      }
	      bx[i] = midx;
	      by[i] = midy + 220;
	      i++;
	      bx[i] = midx - 30;
	      by[i] = midy + 220;
	      i++;
	      j = 190;
	      while(i < 31 )
	      { bx[i] = midx - 30;
		by[i] = midy + j;
		i++;
		j = j - 30;
	      }
	      j = 70;
	      while(i<37){
	      bx[i] = midx - j;
	      by[i] = midy + 30;
	      i++;
	      j = j + 30;
	      }
	      bx[i] = midx - 220;
	      by[i] = midy;
	      i++;
	      bx[i] = midx - 220;
	      by[i] = midy - 30;
	      i++;
	      j=190;
	      while(i<44) {
	      bx[i] = midx - j;
	      by[i] = midy - 30;
	      i++;
	      j = j-30;
	      }
	      j = 70;
	      while(i<50){
	      bx[i] = midx - 30;
	      by[i] = midy - j;
	      i++;
	      j = j + 30;
	      }
	      bx[i] = midx ;
	      by[i] = midy - 220;
	      i++;
	      bx[i] = midx + 30;
	      by[i] = midy - 220;
	      i++;
	      bx[i] = bx[0];
	      by[i] = by[0];


	   //Yellow Color
	      i=0;
	      j=190;
	      while(i<5){
	      yx[i] = midx + j;
	      yy[i] = midy + 30;
	      i++;
	      j = j-30;
	      }
	      j=70;
	      while( i < 11){
	      yx[i] = midx + 30;
	      yy[i] = midy + j;
	      i++;
	      j = j+30;
	      }
	      yx[i] = midx;
	      yy[i] = midy + 220;
	      i++;
	      yx[i] = midx - 30;
	      yy[i] = midy + 220;
	      i++;
	      j = 190;
	      while(i < 18 )
	      { yx[i] = midx - 30;
		yy[i] = midy + j;
		i++;
		j = j - 30;
	      }
	      j = 70;
	      while(i<24){
	      yx[i] = midx - j;
	      yy[i] = midy + 30;
	      i++;
	      j = j + 30;
	      }
	      yx[i] = midx - 220;
	      yy[i] = midy;
	      i++;
	      yx[i] = midx - 220;
	      yy[i] = midy - 30;
	      i++;
	      j=190;
	      while(i<31) {
	      yx[i] = midx - j;
	      yy[i] = midy - 30;
	      i++;
	      j = j-30;
	      }
	      j = 70;
	      while(i<37){
	      yx[i] = midx - 30;
	      yy[i] = midy - j;
	      i++;
	      j = j + 30;
	      }
	      yx[i] = midx ;
	      yy[i] = midy - 220;
	      i++;
	      yx[i] = midx + 30;
	      yy[i] = midy - 220;
	      i++;
	      while(i<44){
	      yx[i] = midx + 30;
	      yy[i] = midy - j;
	      i++;
	      j = j -30;
	      }
	      j=70;
	      while(i<50){
	      yx[i] = midx + j;
	      yy[i] = midy - 30;
	      i++;
	      j=j+30;
	      }
	      yx[i] = midx + 220 ;
	      yy[i] = midy ;
	      i++;
	      yx[i] = midx + 220;
	      yy[i] = midy + 30;
	      i++;
	      yx[i] = yx[0];
	      yy[i] = yy[0];


	     //Green Color
	      i=0;
	      j=190;
	      while(i < 5 )
	      {
	      gx[i] = midx - 30;
	      gy[i] = midy + j;
		i++;
		j = j - 30;
	      }
	      j = 70;
	      while(i<11){
	      gx[i] = midx - j;
	      gy[i] = midy + 30;
	      i++;
	      j = j + 30;
	      }
	      gx[i] = midx - 220;
	      gy[i] = midy;
	      i++;
	      gx[i] = midx - 220;
	      gy[i] = midy - 30;
	      i++;
	      j=190;
	      while(i<18) {
	      gx[i] = midx - j;
	      gy[i] = midy - 30;
	      i++;
	      j = j-30;
	      }
	      j = 70;
	      while(i<24){
	      gx[i] = midx - 30;
	      gy[i] = midy - j;
	      i++;
	      j = j + 30;
	      }
	      gx[i] = midx ;
	      gy[i] = midy - 220;
	      i++;
	      gx[i] = midx + 30;
	      gy[i] = midy - 220;
	      i++;
	      while(i<31){
	      gx[i] = midx + 30;
	      gy[i] = midy - j;
	      i++;
	      j = j -30;
	      }
	      j=70;
	      while(i<37){
	      gx[i] = midx + j;
	      gy[i] = midy - 30;
	      i++;
	      j=j+30;
	      }
	      gx[i] = midx + 220 ;
	      gy[i] = midy ;
	      i++;
	      gx[i] = midx + 220;
	      gy[i] = midy + 30;
	      i++;
	      j = 190 ;
	      while(i<44){
	      gx[i] = midx + j;
	      gy[i] = midy + 30;
	      i++;
	      j = j-30;
	      }
	      j=70;
	      while( i < 50){
	      gx[i] = midx + 30;
	      gy[i] = midy + j;
	      i++;
	      j = j + 30;
	      }
	      gx[i] = midx + 30 ;
	      gy[i] = midy + 220;
	      i++;
	      gx[i] = midx ;
	      gy[i] = midy + 220;
	      i++;
	      gx[i] = gx[0];
	      gy[i] = gy[0];

	  //Red Color
	      i=0;
	      j=190;
	      while(i<5) {
	      rx[i] = midx - j;
	      ry[i] = midy - 30;
	      i++;
	      j = j-30;
	      }
	      j = 70;
	      while(i<11){
	      rx[i] = midx - 30;
	      ry[i] = midy - j;
	      i++;
	      j = j + 30;
	      }
	      rx[i] = midx ;
	      ry[i] = midy - 220;
	      i++;
	      rx[i] = midx + 30;
	      ry[i] = midy - 220;
	      i++;
	      while(i<18){
	      rx[i] = midx + 30;
	      ry[i] = midy - j;
	      i++;
	      j = j -30;
	      }
	      j=70;
	      while(i<24){
	      rx[i] = midx + j;
	      ry[i] = midy - 30;
	      i++;
	      j=j+30;
	      }
	      rx[i] = midx + 220 ;
	      ry[i] = midy ;
	      i++;
	      rx[i] = midx + 220;
	      ry[i] = midy + 30;
	      i++;
	      j = 190 ;
	      while(i<31){
	      rx[i] = midx + j;
	      ry[i] = midy + 30;
	      i++;
	      j = j-30;
	      }
	      j=70;
	      while( i < 37){
	      rx[i] = midx + 30;
	      ry[i] = midy + j;
	      i++;
	      j = j + 30;
	      }
	      rx[i] = midx + 30 ;
	      ry[i] = midy + 220;
	      i++;
	      rx[i] = midx ;
	      ry[i] = midy + 220;
	      i++;
	      while(i < 44 )
	      {
	      rx[i] = midx - 30;
	      ry[i] = midy + j;
		i++;
		j = j - 30;
	      }
	      j = 70;
	      while(i< 50 ){
	      rx[i] = midx - j;
	      ry[i] = midy + 30;
	      i++;
	      j = j + 30;
	      }
	      rx[i] = midx - 220;
	      ry[i] = midy;
	      i++;
	      rx[i] = midx - 220;
	      ry[i] = midy - 30;
	      i++;

	      rx[i] = rx[0];
	      ry[i] = ry[0];



  }


/*  struct node * func(struct node * root,struct node * ptr , int x1,int y1,int f,int c){
  {   struct node * newnode;
      newnode = new node;
      newnode -> x = x1;
      newnode -> y = y1;
      newnode -> fs = f;
      newnode -> col =c ;
      newnode ->next =NULL;

      if(root == NULL){
      root = newnode;
      ptr = root;
      }
      else
      {  ptr ->next =newnode;
	 ptr = newnode;
      }

      return ptr;
  }
    */




  void dicenum(int num){
  switch(num){
  case 1 :  cout<<" You got ONE\n";
	    break;
  case 2 :  cout<<" You got TWO\n";
	    break;
  case 3 :  cout<<" You got THREE\n";
	    break;
  case 4 :  cout<<" You got FOUR\n";
	    break;
  case 5 :  cout<<" You got FIVE\n";
	    break;
  case 6 :  cout<<" You got SIX\n";
	    break;  }
  }

  int dice(int temp){
  char ch;
  int num,num1=0,num2=0;
  switch(temp)
  {
    case 0: cout<<"\nIts red turn to roll the dice (y or n) \n";
	    break;
    case 1: cout<<"\nIts Blue turn to roll the dice (y or n) \n";
	    break;
    case 2: cout<<"\nIts Yellow turn to roll the dice (y or n) \n";
	    break;
    case 3: cout<<"\nIts Green turn to roll the dice (y or n) \n";
	    break;
  }

  cin>>ch;
  if(ch=='y'||ch=='Y')
  {  randomize();
     num=(rand()%6)+1;
  dicenum(num);}
  if(num==6)
  {randomize();
  num1=random(6-1+1)+1;
  dicenum(num1);}
  if(num1==6)
 {randomize();
  num2=(rand()%6)+1;
  dicenum(num2);}
  if(num2==6)
  {cout<<"\n You got three sixes you lose your turn \n";
   num2=0;
  }
 return (num+num1+num2);
  }


  void valondice()
  {
   red=4,yellow =4,green=4,blue=4;

   int butnum;

   for(int i=0;i<8;i++)
      {
   for(int j=0;j<60;j++)
   {
     redbutton[i][j] = 0;        //initialising button num and their locations
     greenbutton[i][j] = 0;
     yellowbutton[i][j] = 0;
     bluebutton[i][j] = 0;
   }
      }


   table();

   cout<<"\nLets give First chance to red then blue then yellow and green last\n";
   int temp = 0;

   while(red!=0){
   int num,num1,num2;
label : num = dice(temp);

       if(num!=18) {
       if(temp==0)
       cout<<"\nRed Lose its turn\n";
       if(temp==1)
       cout<<"\nBlue Lose its turn\n";
       if(temp==0)
       cout<<"\nYellow Lose its turn\n";
       if(temp==0)
       cout<<"\nGreen Lose its turn\n";
       temp++;
       goto label;   }

  else
  {
   if(num>6&&num<12)
   {
     num1=num-6;
     num=6;
     num2 =0;
   }
   else if(num>=12&&num<18)
   {
      num2=num-12;
      num=6;
      num1=6;
   }
     }



   if(red>0||blue>0||green>0||yellow>0){
   if(num==6||num==1){
   switch(temp){
case 0 :
	if(red>0)
	{
	cout<<" \n Red can unlock the pawn \n " ;
	if(num==1)
       {
	char ch;
	cout<<" \n You got 1 Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&red>0)
	{
	 butnum = open(red,temp);
	 red--;
	}
	else
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
       }

	if(num==6&&num1!=6)
       {
	char ch;
	cout<<" \n You got 6 1st Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&red>0)
	{
	 butnum = open(red,temp);
	 red--;
	 move(num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	}
	else
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
		}

	else if(num==6&&num1==6)
       {
	char ch;
	cout<<" \n You got 6 1st and 2nd 6 also Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&red>0)
	{
	butnum = open(red,temp);
	  red--;
	 cout<<" \n You got another 6 also Press y to open your pawn \n";
	 cin>>ch;
	 if((ch=='y'||ch=='Y')&&red>0)
	 {
	 butnum = open(red,temp);
	  red--;
	  move(num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);   }
	  else
	  move(num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }
	else
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

		  }			}
	break;

case 1 :if(blue>0)
	{
	cout<<" \n Blue can unlock the pawn \n " ;
	if(num==1)
	{
	char ch;
	cout<<" \n You got 1 Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&blue>0)
	{
	butnum = open(blue,temp);
	 blue--;
	}
	else
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
      }

	else if(num==6&&num1!=6)
      {
	char ch;
	cout<<" \n You got 6 1st Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&blue>0)
	{
	butnum = open(blue,temp);
	 blue--;
	 move(num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	}
	else
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
      }

	else if(num==6&&num1==6&&red>0)
      {
	char ch;
	cout<<" \n You got 6 1st and 2nd 6 also Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&blue>0)
	{
	butnum = open(blue,temp);
	 blue--;
	 cout<<" \n You got another 6 also Press y to open your pawn \n";
	 cin>>ch;
	 if((ch=='y'||ch=='Y')&&blue>0)
	 {
	butnum =  open(blue,temp);
	  blue--;
	  move(num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }
	  else
	  move(num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	}
	else
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

			     }		}
	break;

case 2 :if(yellow>0)
	{
	 cout<<" \n Yellow can unlock the pawn \n " ;
	if(num==1){
	char ch;
	cout<<" \n You got 1 Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&yellow>0)
	{
	butnum = open(yellow,temp);
	 yellow--;}
	else
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }

	else if(num==6&&num1!=6){
	char ch;
	cout<<" \n You got 6 1st Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&yellow>0)
	{
	butnum = open(yellow,temp);
	 yellow--;
	 move(num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }
	else
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
		}

	else if(num==6&&num1==6&&red>0){
	char ch;
	cout<<" \n You got 6 1st and 2nd 6 also Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&yellow>0)
	{
	butnum = open(yellow,temp);
	 yellow--;
	 cout<<" \n You got another 6 also Press y to open your pawn \n";
	 cin>>ch;
	 if((ch=='y'||ch=='Y')&&yellow>0)
	 {
	  butnum =  open(yellow,temp);
	  yellow--;
	  move(num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);   }
	  else
	  move(num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }
	else
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

				}	}
	break;

case 3 :if(green>0)
	{ cout<<" \n Green can unlock the pawn \n " ;
	if(num==1){
	char ch;
	cout<<" \n You got 1 Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&green>0)
	{
	butnum = open(green,temp);
	 green--;}
	else
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }

	else if(num==6&&num1!=6){
	char ch;
	cout<<" \n You got 6 1st Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&green>0)
	{
	butnum = open(green,temp);
	 green--;
	 move(num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }
	else
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
		}

	else if(num==6&&num1==6&&red>0){
	char ch;
	cout<<" \n You got 6 1st and 2nd 6 also Press y to open your pawn \n";
	cin>>ch;
	if((ch=='y'||ch=='Y')&&green>0)
	{
	butnum = open(green,temp);
	 green--;
	 cout<<" \n You got another 6 also Press y to open your pawn \n";
	 cin>>ch;
	 if((ch=='y'||ch=='Y')&&green>0)
	 {
	butnum =  open(green,temp);
	  green--;
	  move(num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);   }
	  else
	  move(num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);
	 }
	else
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

				}	}
	break;


  } //Switch

       }//if
	     } //if


  else
  {
	switch(temp){

case 0 :
	if(num!=6)
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1!=6)
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1==6&&num2!=6)
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	break;

case 1 :
	if(num!=6)
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1!=6)
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1==6&&num2!=6)
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	break;

case 2 :
	if(num!=6)
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1!=6)
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1==6&&num2!=6)
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	break;

case 3 :
	if(num!=6)
	move(num,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1!=6)
	move(num+num1,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	if(num==6&&num1==6&&num2!=6)
	move(num+num1+num2,butnum,temp,redbutton,bluebutton,yellowbutton,greenbutton);

	break;

  } //Switch

       }//else



   temp++;

   if(temp==4)
   temp=0;

       }  //while loop

  getch();

  }



 int open(int num,int temp)
 {
 //  int midx=getmaxx()/2;
 //  int midy=getmaxy()/2;
    int butnum;


    int choice;
    cout<<"\n Which pawn you want to open Buttons are arranged as : \n";
    cout<<"\n Top left - 1 \n Top right - 2 \n Bottom left - 3 \n Bottom right - 4 \n";
    cin>>choice;

    table();
    if(temp==0){
    setcolor(4);

    table();
   switch (choice){

   case 0 :	setfillstyle(4,12);
		fillellipse(brx[0],bry[0],10,10);
		fillellipse(rx[0],ry[0],10,10);
		butnum=1;
		break;
   case 1 :     setfillstyle(4,12);
		fillellipse(brx[1],bry[1],10,10);
		fillellipse(rx[0],ry[0],10,10);
		butnum=2;
		break;
   case 2 :     setfillstyle(4,12);
		fillellipse(brx[2],bry[2],10,10);
		fillellipse(rx[0],ry[0],10,10);
		butnum=3;
		break;
   case 3 :     setfillstyle(4,12);
		fillellipse(brx[3],bry[3],10,10);
		fillellipse(rx[0],ry[0],10,10);
		butnum=4;
		break;
   default :    cout<<"\n All red pawns are unlocked \n";
		break;
		}
	      }

   if(temp==1){
   setcolor(1);

   switch (choice){
   case 0 :     setfillstyle(4,9);
		fillellipse(bbx[0],bby[0],10,10);
		fillellipse(bx[0],by[0],10,10);
		butnum=1;
		break;
   case 1 :     setfillstyle(4,9);
		fillellipse(bbx[1],bby[1],10,10);
		fillellipse(bx[0],by[0],10,10);
		butnum=2;
		break;
   case 2 :     setfillstyle(4,9);
		fillellipse(bbx[2],bby[2],10,10);
		fillellipse(bx[0],by[0],10,10);
		butnum=3;
		break;
   case 3 :     setfillstyle(4,9);
		fillellipse(bbx[3],bby[3],10,10);
		fillellipse(bx[0],by[0],10,10);
		butnum=4;
		break;
   default :    cout<<"\n All Blue pawns are unlocked \n";
		break;
	       }
	     }


    if(temp==2){
    setcolor(14);

   switch (choice){

   case 0 :     setfillstyle(4,14);
		fillellipse(byx[0],byy[0],10,10);
		fillellipse(yx[0],yy[0],10,10);
		butnum=1;
		break;
   case 1 :     setfillstyle(4,14);
		fillellipse(byx[1],byy[1],10,10);
		fillellipse(yx[0],yy[0],10,10);
		butnum=2;
		break;
   case 2 :     setfillstyle(4,14);
		fillellipse(byx[2],byy[2],10,10);
		fillellipse(yx[0],yy[0],10,10);
		butnum=3;
		break;
   case 3 :     setfillstyle(4,14);
		fillellipse(byx[3],byy[3],10,10);
		fillellipse(yx[0],yy[0],10,10);
		butnum=4;
		break;
   default :    cout<<"\n All Yellow pawns are unlocked \n";
		break;
	      }
	     }


   if(temp==3){
   setcolor(2);

   switch (choice){
   case 0 :     setfillstyle(4,10);
		fillellipse(bgx[0],bgy[0],10,10);
		fillellipse(gx[0],gy[0],10,10);
		butnum=1;
		break;
   case 1 :     setfillstyle(4,10);
		fillellipse(bgx[1],bgy[1],10,10);
		fillellipse(gx[0],gy[0],10,10);
		butnum=2;
		break;
   case 2 :     setfillstyle(4,10);
		fillellipse(bgx[2],bgy[2],10,10);
		fillellipse(gx[0],gy[0],10,10);
		butnum=3;
		break;
   case 3 :     setfillstyle(4,10);
		fillellipse(bgx[3],bgy[3],10,10);
		fillellipse(gx[0],gy[0],10,10);
		butnum=4;
		break;
   default :    cout<<"\n All Green pawns are unlocked \n";
		break;
	       }
	      }

 return butnum;

 }

 static   void move(int step,int butnum,int temp,int redbutton[8][60],int bluebutton[8][60],int yellowbutton[8][60],int greenbutton[8][60])
    {
       table();

       switch (temp) {
       case 0 : movered(step,redbutton,butnum);
		break;
       case 1 : moveblue(step,bluebutton,butnum);
		break;
       case 2 : moveyellow(step,yellowbutton,butnum);
		break;
       case 3 : movegreen(step,greenbutton,butnum);
		break;
		      }
    }



 static   void movered(int step,int redbutton[8][60],int butnum){

    switch(butnum){

    case 1 : mover1(step,redbutton);
	     break;
    case 2 : mover2(step,redbutton);
	     break;
    case 3 : mover3(step,redbutton);
	     break;
    case 4 : mover4(step,redbutton);
	     break;
     }//end of switch
    }

 static   void moveblue(int step,int bluebutton[8][60],int butnum){

    switch(butnum){

    case 1 : moveb1(step,bluebutton);
	     break;
    case 2 : moveb2(step,bluebutton);
	     break;
    case 3 : moveb3(step,bluebutton);
	     break;
    case 4 : moveb4(step,bluebutton);
	     break;
     }//end of switch
    }


 static    void movegreen(int step,int greenbutton[8][60],int butnum){

    switch(butnum){

    case 1 : moveg1(step,greenbutton);
	     break;
    case 2 : moveg2(step,greenbutton);
	     break;
    case 3 : moveg3(step,greenbutton);
	     break;
    case 4 : moveg4(step,greenbutton);
	     break;
     }//end of switch
    }




 static    void moveyellow(int step,int yellowbutton[8][60],int butnum){

    switch(butnum){

    case 1 : movey1(step,yellowbutton);
	     break;
    case 2 : movey2(step,yellowbutton);
	     break;
    case 3 : movey3(step,yellowbutton);
	     break;
    case 4 : movey4(step,yellowbutton);
	     break;
     }//end of switch
    }



 static   void mover1(int step,int redbutton[8][60]){

    int i=0;
    int temp = i;

    while(redbutton[0][i]!=0){
    temp = i;
    i++;
    }

    redbutton[0][0] = rx[0];
    redbutton[1][0] = ry[0];

    redbutton[0][i] = rx[step];
    redbutton[1][i] = ry[step];

    int tempx = redbutton[0][temp];
    int tempy = redbutton[1][temp];

    setfillstyle(1,4);
    fillellipse(rx[step],ry[step],10,10);

    }

 static     void mover2(int step,int redbutton[8][60]){

    int i=0;
   int  temp = i;

    while(redbutton[2][i]!=0){
    temp = i;
    i++;
    }

    redbutton[2][0] = rx[0];
    redbutton[3][0] = ry[0];

    redbutton[2][i] = rx[step];
    redbutton[3][i] = ry[step];

    int tempx = redbutton[2][temp];
    int tempy = redbutton[3][temp];

    setfillstyle(1,4);
    fillellipse(rx[step],ry[step],10,10);

    }

 static     void mover3(int step,int redbutton[8][60]){

    int i=0;
   int  temp = i;

    while(redbutton[4][i]!=0){
    temp = i;
    i++;
    }

    redbutton[4][0] = rx[0];
    redbutton[5][0] = ry[0];

    redbutton[4][i] = rx[step];
    redbutton[5][i] = ry[step];

    int tempx = redbutton[4][temp];
    int tempy = redbutton[5][temp];

    setfillstyle(1,4);
    fillellipse(rx[step],ry[step],10,10);

    }

 static     void mover4(int step,int redbutton[8][60]){

    int i=0;
    int temp = i;

    while(redbutton[6][i]!=0){
    temp = i;
    i++;
    }

    redbutton[6][0] = rx[0];
    redbutton[7][0] = ry[0];

    redbutton[6][i] = rx[step];
    redbutton[7][i] = ry[step];

    int tempx = redbutton[6][temp];
    int tempy = redbutton[7][temp];

    setfillstyle(1,4);
    fillellipse(rx[step],ry[step],10,10);

    }

 static  void moveg1(int step,int greenbutton[8][60]){

    int i=0;
    int temp = i;

    while(greenbutton[0][i]!=0){
    temp = i;
    i++;
    }

    greenbutton[0][0] = gx[0];
    greenbutton[1][0] = gy[0];

    greenbutton[0][i] = gx[step];
    greenbutton[1][i] = gy[step];

    int tempx = greenbutton[0][temp];
    int tempy = greenbutton[1][temp];

    setfillstyle(1,4);
    fillellipse(gx[step],gy[step],10,10);

    }

 static  void moveg2(int step,int greenbutton[8][60]){

    int i=0;
    int temp = i;

    while(greenbutton[2][i]!=0){
    temp = i;
    i++;
    }

    greenbutton[2][0] = gx[0];
    greenbutton[3][0] = gy[0];

    greenbutton[2][i] = gx[step];
    greenbutton[3][i] = gy[step];

    int tempx = greenbutton[2][temp];
    int tempy = greenbutton[3][temp];

    setfillstyle(1,4);
    fillellipse(gx[step],gy[step],10,10);

    }

 static  void moveg3(int step,int greenbutton[8][60]){

    int i=0;
   int temp = i;

    while(greenbutton[4][i]!=0){
    temp = i;
    i++;
    }

    greenbutton[4][0] = gx[0];
    greenbutton[5][0] = gy[0];

    greenbutton[4][i] = gx[step];
    greenbutton[5][i] = gy[step];

    int tempx = greenbutton[4][temp];
    int tempy = greenbutton[5][temp];

    setfillstyle(1,4);
    fillellipse(gx[step],gy[step],10,10);

    }

 static     void moveg4(int step,int greenbutton[8][60]){

    int i=0;
   int temp = i;

    while(greenbutton[6][i]!=0){
    temp = i;
    i++;
    }

    greenbutton[6][0] = gx[0];
    greenbutton[7][0] = gy[0];

    greenbutton[6][i] = gx[step];
    greenbutton[7][i] = gy[step];

    int tempx = greenbutton[6][temp];
    int tempy = greenbutton[7][temp];

    setfillstyle(1,4);
    fillellipse(gx[step],gy[step],10,10);

    }



 static   void movey1(int step,int yellowbutton[8][60]){

    int i=0;
    int temp = i;

    while(yellowbutton[0][i]!=0){
    temp = i;
    i++;
    }

    yellowbutton[0][0] = yx[0];
    yellowbutton[1][0] = yy[0];

    yellowbutton[0][i] = yx[step];
    yellowbutton[1][i] = yy[step];

    int tempx = yellowbutton[0][temp];
    int tempy = yellowbutton[1][temp];

    setfillstyle(1,4);
    fillellipse(yx[step],yy[step],10,10);

    }

 static     void movey2(int step,int yellowbutton[8][60]){

    int i=0;
    int temp = i;

    while(yellowbutton[2][i]!=0){
    temp = i;
    i++;
    }

    yellowbutton[2][0] = yx[0];
    yellowbutton[3][0] = yy[0];

    yellowbutton[2][i] = yx[step];
    yellowbutton[3][i] = yy[step];

    int tempx = yellowbutton[2][temp];
    int tempy = yellowbutton[3][temp];

    setfillstyle(1,4);
    fillellipse(yx[step],yy[step],10,10);

    }

 static     void movey3(int step,int yellowbutton[8][60]){

    int i=0;
    int temp = i;

    while(yellowbutton[4][i]!=0){
    temp = i;
    i++;
    }

    yellowbutton[4][0] = yx[0];
    yellowbutton[5][0] = yy[0];

    yellowbutton[4][i] = yx[step];
    yellowbutton[5][i] = yy[step];

    int tempx = yellowbutton[4][temp];
    int tempy = yellowbutton[5][temp];

    setfillstyle(1,4);
    fillellipse(yx[step],yy[step],10,10);

    }

 static     void movey4(int step,int yellowbutton[8][60]){

    int i=0;
    int temp = i;

    while(yellowbutton[6][i]!=0){
    temp = i;
    i++;
    }

    yellowbutton[6][0] = yx[0];
    yellowbutton[7][0] = yy[0];

    yellowbutton[6][i] = yx[step];
    yellowbutton[7][i] = yy[step];

    int tempx = yellowbutton[6][temp];
    int tempy = yellowbutton[7][temp];

    setfillstyle(1,4);
    fillellipse(yx[step],yy[step],10,10);

    }





 static   void moveb1(int step,int bluebutton[8][60]){

    int i=0;
    int temp = i;

    while(bluebutton[0][i]!=0){
    temp = i;
    i++;
    }

    bluebutton[0][0] = bx[0];
    bluebutton[1][0] = by[0];

    bluebutton[0][i] = bx[step];
    bluebutton[1][i] = by[step];

    int tempx = bluebutton[0][temp];
    int tempy = bluebutton[1][temp];

    setfillstyle(1,4);
    fillellipse(bx[step],by[step],10,10);

    }

 static     void moveb2(int step,int bluebutton[8][60]){

    int i=0;
    int temp = i;

    while(bluebutton[2][i]!=0){
    temp = i;
    i++;
    }

    bluebutton[2][0] = bx[0];
    bluebutton[3][0] = by[0];

    bluebutton[2][i] = bx[step];
    bluebutton[3][i] = by[step];

    int tempx = bluebutton[2][temp];
    int tempy = bluebutton[3][temp];

    setfillstyle(1,4);
    fillellipse(bx[step],by[step],10,10);

    }

 static     void moveb3(int step,int bluebutton[8][60]){

    int i=0;
    int temp = i;

    while(bluebutton[4][i]!=0){
    temp = i;
    i++;
    }

    bluebutton[4][0] = bx[0];
    bluebutton[5][0] = by[0];

    bluebutton[4][i] = bx[step];
    bluebutton[5][i] = by[step];

    int tempx = bluebutton[4][temp];
    int tempy = bluebutton[5][temp];

    setfillstyle(1,4);
    fillellipse(bx[step],by[step],10,10);

    }

 static     void moveb4(int step,int bluebutton[8][60]){

    int i=0;
    int temp = i;

    while(bluebutton[6][i]!=0){
    temp = i;
    i++;
    }

    bluebutton[6][0] = bx[0];
    bluebutton[7][0] = by[0];

    bluebutton[6][i] = bx[step];
    bluebutton[7][i] = by[step];

    int tempx = bluebutton[6][temp];
    int tempy = bluebutton[7][temp];

    setfillstyle(1,4);
    fillellipse(bx[step],by[step],10,10);

    }




   void main(){
   start();
   initialise();
   cleardevice();
   valondice();
   getch();

   }
