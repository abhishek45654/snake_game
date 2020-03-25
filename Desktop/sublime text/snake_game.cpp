#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int boundary_height=20,boundary_width=20;                         //boundary height and width
int snake_headx=boundary_width/2,snake_heady=boundary_height/2;  //coordinates of head of snake.
int foodx=9,foody=2,score=0,end_game=0;                          //coordinates of food of snake.
char ch,continue_move;
vector<vector<int > > snake_seg;                   //stores the coordinates of segments of snake each time snake eat food

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
    int k=0;
   for(int i=0;i<boundary_height;i++)
   {
   	 cout<<"*";
   	 for(int j=1;j<boundary_width-1;j++)
   	 {
   	    if(i==0||i==boundary_height-1)cout<<"*";
   	 	else 
   	 	{
   	 		if(i==snake_heady&&j==snake_headx)
				cout<<"O";
				
   	 		else if(i==foody&&j==foodx)
				cout<<"o";
				
   	 		else 
			{
				int z=0;
				for(int k=0;k<snake_seg.size();k++)
				{
                  if(i==snake_seg[k][1]&&j==snake_seg[k][0])
                  {
                     cout<<"o";z++;
                  }
                }
                if(z==0)cout<<" ";
			}
   	 	}
   	 }
   	 cout<<"*"<<endl;
   }
}

//function for the movement snake segmenst according to head.
void move_seg(int x,int y)
{
	for(int i=snake_seg.size()-1;i>0;i--)
    {
       snake_seg[i]=snake_seg[i-1];
    }
    snake_seg[0][0]=x;
    snake_seg[0][1]=y;
}

//function to run snake
void game_play()
{  
    int prevx=snake_headx,prevy=snake_heady;
    if(_kbhit())
    {
   	    ch=_getch();
    }
    if(ch=='p')continue_move = 'p';
    if(ch=='a'&&continue_move=='d'||ch=='d'&&continue_move=='a')ch=continue_move;
    else if(ch=='w'&&continue_move=='z'||ch=='z'&&continue_move=='w')ch=continue_move;
    if(ch=='a'||ch=='d'||ch=='w'||ch=='z')continue_move=ch;     
    switch(continue_move)
   	{
   	    case 'a':snake_headx--;break;//to move snake left.
   	    case 'd':snake_headx++;break;//to move snake right.
   	    case 'w':snake_heady--;break;//to move snake up.
   	    case 'z':snake_heady++;break;//to move snake down.
   	    default:break;
    }
    if(continue_move!='p')
    {
        move_seg(prevx,prevy);
        if(foodx==snake_headx&&foody==snake_heady)
   	    {
	       food_coordinates();score++;
	       vector<int>v;v.push_back(snake_headx); v.push_back(snake_heady);
	       snake_seg.push_back(v);  
	    }
       if(snake_headx==boundary_width-1||snake_heady==boundary_height-1||snake_heady==0||snake_headx==0)
   	    end_game=1;
   	}
}

//main function to drive whole game.
int main()
{
	cout<<"Instructions to play"<<endl;
	cout<<"1. Press w to move up."<<endl;
	cout<<"2. Press z to move down."<<endl;
	cout<<"3. Press a to move left."<<endl;
	cout<<"4. Press d to move right."<<endl;
	cout<<"5. Press p to pause the game and any other button above to resume."<<endl<<endl;
	cout<<"if you want default boundary size press d"<<endl;
	cout<<"otherwise press a to customise boundary size"<<endl;
	char c;cin>>c;
		switch(c)
		{
			case 'a':
				cout<<"Enter boundary width"<<endl;
				cout<<"width = ";
				cin>>boundary_width;
				
				cout<<"Enter boundary height"<<endl;
				cout<<"height = ";
				cin>>boundary_height;
				break;
				
			case 'A':
				cout<<"Enter boundary width"<<endl;
				cout<<"width = ";
				cin>>boundary_width;
				
				cout<<"Enter boundary height"<<endl;
				cout<<"height = ";
				cin>>boundary_height;
				break;
		}
	vector<int>v;
	v.push_back(snake_headx);
    v.push_back(snake_heady);
	snake_seg.push_back(v);  
	
	while(!end_game)
	{	
	  game_play();
      draw();
      for(int i=0;i<10000-snake_seg.size();i++)
      {
      	for(int j=0;j<1000-snake_seg.size();j++)
		{
				  
		}
	  }
      
	  
    }
    cout<<"gameover and your score is "<<score;
    return 0;
}
