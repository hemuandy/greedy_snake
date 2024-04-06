#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

using namespace std;

char c,lastinput;
int x=20, y=20, n=500, a[22][22]={0}, headx, heady/*, tailx, taily*/ ,length=1 ,score=0;
bool gameover=false;
int applex, appley;

void apple()
{
    applex=rand()%x+1;
    appley=rand()%y+1;
    while(a[applex][appley]!=0)
    {
        applex=rand()%x+1;
        appley=rand()%y+1;
    }
    a[applex][appley]=1e9;
}

void move()
{
    if(c=='w')
    {
        if(a[headx-1][heady]==0 || a[headx-1][heady]==1e9)
        {
            if(a[headx-1][heady]==1e9)
            {
                length++;
                score=length;
                a[headx-1][heady]=length; 
                headx=headx-1;
            }
            else
            {
                for(int i=0;i<=x+1;i++)
                {
                    for(int j=0;j<=y+1;j++)
                    {
                        if(a[i][j]>=1 && a[i][j]!=1e9) a[i][j]--;
                    }
                }    
                a[headx-1][heady]=length; 
                headx=headx-1; 
            }
             
        }
        else if(a[headx-1][heady]!=1e9)
        {
            gameover=true;
        }
    }
    else if(c=='s')
    {
        if(a[headx+1][heady]==0 || a[headx+1][heady]==1e9)
        {
            if(a[headx+1][heady]==1e9)
            {
                length++;
                score=length;
                a[headx+1][heady]=length; 
                headx=headx+1;
            }
            else
            {
                for(int i=0;i<=x+1;i++)
                {
                    for(int j=0;j<=y+1;j++)
                    {
                        if(a[i][j]>=1 && a[i][j]!=1e9) a[i][j]--;
                    }
                }    
                a[headx+1][heady]=length; 
                headx=headx+1;
            }
              
        }
        else if(a[headx+1][heady]!=1e9)
        {
            gameover=true;
        }
    }
    else if(c=='a')
    {
        if(a[headx][heady-1]==0 || a[headx][heady-1]==1e9)
        {
            if(a[headx][heady-1]==1e9)
            {
                length++;
                score=length;
                a[headx][heady-1]=length; 
                heady=heady-1;
            }
            else
            {
                for(int i=0;i<=x+1;i++)
                {
                    for(int j=0;j<=y+1;j++)
                    {
                        if(a[i][j]>=1 && a[i][j]!=1e9) a[i][j]--;
                    }
                }    
                a[headx][heady-1]=length; 
                heady=heady-1;
            }
              
        }
        else if(a[headx][heady-1]!=1e9)
        {
            gameover=true;
        }
    }
    else if(c=='d')
    {
        if(a[headx][heady+1]==0 || a[headx][heady+1]==1e9)
        {
            if(a[headx][heady+1]==1e9)
            {
                length++;   
                score=length;
                a[headx][heady+1]=length; 
                heady=heady+1;
            }
            else
            {
                for(int i=0;i<=x+1;i++)
                {
                    for(int j=0;j<=y+1;j++)
                    {
                        if(a[i][j]>=1 && a[i][j]!=1e9) a[i][j]--;
                    }
                }    
                a[headx][heady+1]=length; 
                heady=heady+1;
            }  
        }
        else if(a[headx][heady+1]!=1e9)
        {
            gameover=true;
        }
    }
    if(headx==applex && heady==appley)
    {
        apple();
    }
}

void print()
{
    system("cls");
    for(int i=0;i<=x+1;i++)
    {
        for(int j=0;j<=y+1;j++)
        {
            if(a[i][j]>=1 && a[i][j]!=1e9) cout<<'@'<<" ";
            else if(a[i][j]==-1) cout<<'#'<<" ";
            else if(a[i][j]==1e9) cout<<'*'<<" ";
            else cout<<' '<<" ";
        }
        cout<<endl;
    }
    score=length;
    cout<<"Press 'w' to move up, 'a' to move left, 'd' to move right, 's' to move down "<<endl;
    cout<<"Score: "<<score<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    apple();
    for(int i=0;i<=x+1;i++)
    {
        a[i][0]=-1;
        a[i][y+1]=-1;
    }
    for(int i=0;i<=y+1;i++)
    {
        a[0][i]=-1;
        a[x+1][i]=-1;
    }
    a[x/2][y/2]=1;
    headx=x/2;
    heady=y/2;
    //tailx=x/2;
    //taily=y/2;
    while(1)
    {
        print();
        Sleep(n);
        if(kbhit())
        {
            c=getch();
            if(c=='q') break;
            lastinput=c;
        }
        move();
        if(gameover)
        {
            cout<<"Game over! You scored "<<score<<" points. You lose!"<<endl;
            break;
        }
        if(length==x*y)
        {
            gameover=true;
            cout<<"Game over! You scored "<<score<<" points. You win!"<<endl;
            break;
        }
    }
    system("pause");
    return 0;
}