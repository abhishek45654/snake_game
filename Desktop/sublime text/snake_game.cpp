#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int boundary_height=20,boundary_width=20;
int snake_headx=boundary_width/2,snake_heady=boundary_height/2;
int foodx=9,foody=2,score=0,end_game=0;
char ch,continue_move;
//this function is used to give random coordinates to food.
void food_coordinates()
{
	srand(time(NULL));
	foodx=rand()%(boundary_width-3)+1;
	foody=rand()%(boundary_height-3)+1;
}

//this function is used to draw boundary, food and sanke.
void draw()
{
	system("CLS");
   for(int i=0;i<boundary_height;i++)
   {
   	 cout<<"*";
   	 for(int j=1;j<boundary_width-1;j++)
   	 {
   	 	if(i==0||i==boundary_height-1)cout<<"*";
   	 	else 
   	 	{
   	 		if(i==snake_heady&&j==snake_headx)cout<<"O";
   	 		else if(i==foody&&j==foodx)cout<<"o";
   	 		else cout<<" ";
   	 	}
   	 }
   	 cout<<"*"<<endl;
   }
}

//function to run snake
void game_play()
{  
    
    if(_kbhit())
    {
   	    ch=_getch();
    }
    if(ch=='a'||ch=='d'||ch=='w'||ch=='z')continue_move=ch;     
    switch(continue_move)
   	{
   	    case 'a':snake_headx--;break;//to move snake left.
   	    case 'd':snake_headx++;break;//to move snake right.
   	    case 'w':snake_heady--;break;//to move snake up.
   	    case 'z':snake_heady++;break;//to move snake down.
   	    default:break;
    }
   if(foodx==snake_headx&&foody==snake_heady)
   	{food_coordinates();score++;}
   if(snake_headx==boundary_width-1||snake_heady==boundary_height-1||snake_heady==0||snake_headx==0)
   	end_game=1;
}

//main function to drive whole game.
int main()
{
	while(!end_game)
	{	
	  game_play();
      draw();
      for(int i=0;i<10000;i++)
      for(int j=0;j<10000;j++){}
	  
    }
    cout<<"score = "<<score;
    return 0;
}
