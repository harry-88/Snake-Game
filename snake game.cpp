#include<iostream>		//header files
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
char ch = 'a',chara = 60;		//deaclear character type variables
int siz = 3,scor,max = 0,food_in_x = 10,food_in_y = 10,life = 3,move_x[100] = {5,6,7},move_y[100] = {5,5,5};		//deaclear int type variables
string name;
void gotoxy(int x,int y)		//this function move the corsor in the screen
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void shape()		//this function make the bondries of game
{
    gotoxy(4,2);
    cout<<"score: "<<scor<<"\t\t"<<"level 1 "<<"\tlife: "<<life;		//display the the informaion of game
    gotoxy(3,3);
    for(int i = 1;i<50;i++)
    cout<<(char)219;
    for(int i = 1;i<=20;i++)
    {
        gotoxy(3,3+i);
        cout<<(char)219;
    }
    for(int i = 1;i<=20;i++)
    {
        gotoxy(51,3+i);
        cout<<(char)219;
    }
    gotoxy(3,23);
    for(int i = 1;i<50;i++)
    cout<<(char)219;
	gotoxy(60,4);
	cout<<"Game Information :";
	gotoxy(60,5);
	cout<<"------------------";
	gotoxy(60,6);
	cout<<"to move the snake use following buttons: "<<endl;
	gotoxy(60,7);
	cout<<"left - 'A'\tright - 'D'\n";
	gotoxy(60,8);
	cout<<"up - 'W'\tdown - 'S'";
	gotoxy(60,9);
	cout<<"Q - quite the game";
	gotoxy(60,11);
	cout<<"contect Information:";
	gotoxy(60,12);
	cout<<"--------------------";
	gotoxy(60,13);
	cout<<"Game Developer: M.Haris";
	gotoxy(60,14);
	cout<<"contect No : 0304-4195933\t0308-1355815";
	gotoxy(60,15);
	cout<<"email address: harisbro88@gmail.com";
}
void snake(int x[],int y[],int siz)		//this function made the body of snake
{
	for(int i = 1;i<siz;i++)
    {
    	gotoxy(x[i],y[i]);
    	cout<<"*";
	}
	gotoxy(x[0],y[0]);
		cout<<chara;
}
void rest(int x,int y,char c)		//this function make the ristrictions
{
    if(y == 3 || y == 23 || x == 3 || x == 51)
    {
		life--;
		chara = 60;
		for(int i = 0;i<3;i++)
		{
			move_x[i] = i + 5;
			move_y[i] = 5; 
		}
		siz = 3;
		scor = 0;
	}
	for(int i = siz-2;i>1;i--)
	{
		if(move_x[0] == move_x[i] && move_y[0] == move_y[i])
		{
			life--;
			chara = 60;
			scor = 0;
			for(int i = 0;i<3;i++)
			{
				move_x[i] = i + 5;
				move_y[i] = 5; 
			}
			siz = 3;
		}
	}
}
void move_fun(char c)		//this function cause to move the snake
{
    if((c == 'w' || c == 'W') && chara != 118)
    {
        move_y[0] = move_y[0] - 1;
        chara  = 94;
	}
    else if((c == 'a' || c == 'A') && chara != 62)
    {
    	 move_x[0] = move_x[0] - 1;
    	 chara = 60;
	}
     else if((c == 's' || c == 'S') && chara != 94)
    {
    	 move_y[0] = move_y[0] + 1;
    	 chara = 118;
	}
     else if((c == 'd' || c == 'D') && chara != 60)
    {
    	 move_x[0] = move_x[0] + 1;
    	 chara = 62;
	}
    if((c == 's' || c == 'S') || (c == 'w' || c == 'W') || (c == 'a' || c == 'A') || (c == 'd' || c == 'D'))		//it move the segmant of snake in next
    {
    	for(int i = siz;i >= 1;i--)
   		{
    		move_x[i] = move_x[i-1];
    		move_y[i] = move_y[i-1];
		}
	}
		rest(move_x[0],move_y[0],ch);		//call the function rest which have ristrictions

}
void food()		//this function made the food
{
    gotoxy(food_in_x,food_in_y);
    cout<<(char)254;
    if(move_x[0] == food_in_x && move_y[0] == food_in_y)
    {
        scor++;
        siz++;
    	food_in_x = rand()%47 + 4;
    	food_in_y =  rand()%19 + 4;
	}
    
}
void time()		//this function able to execute the whole program
{
    while((ch != 'q' && ch != 'Q') && life > 0 && scor < 50)
    {
        shape();
        snake(move_x,move_y,siz);
        food();
        ch = getch();
        if(ch != 'q' || ch != 'Q')
        	move_fun(ch);
        system("cls");
    }
    system("cls");
    gotoxy(5,5);
    if(ch == 'q' || ch == 'Q')
    	cout<<"thanks to play with us. I hope you enjoyed our game....";
    else if(scor == 50)
    {
    	cout<<"Congratulations! You won the game....";
	}
	else
	{
		cout<<"oops! you lost....";
	}
    life = 3;
    scor = 0;
}
void load()		//this function display a loading message
{
	gotoxy(7,5);
	cout<<"loading...";
	gotoxy(5,6);
	for(int i = 1;i<=15;i++)
	{
		for(int t = 1;t<=100000000;t++);		//this loop make some time differance
		cout<<(char)177;
	}
}
int main()		//main body is start from here
{	
	system("color F");
	char choice;
	do
	{
		load();
		system("cls");
    	time();
    	gotoxy(5,7);
    	cout<<"do you want to play again(y-yes,n-no) ";
    	choice = getche();
	}while(choice == 'y' || choice == 'Y');
	cout<<endl;
    gotoxy(1,24);
}
