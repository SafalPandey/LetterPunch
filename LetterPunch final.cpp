#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<string>
#include<conio.h>
#include<sstream>
#include<windows.h>
using namespace std;
void gotoXY(int x, int y)
{

	 COORD coord = {x, y};

	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	 return;
}
int main()
{
    x:
    int i,j=1,k,l,box,score=0,wrn=0,late=0,mistake=0,hscr,ct=1,level=1,cp=1;
    char a[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},key=' ',play='A';
    string hscore;

    for(k=0;k<23;k++)
    {   cout<<'|';
        if(k==0) cout<<"\b ";
        for(l=1;l<78;l++)
        {
            if(k==0 || k==22)
            {gotoXY(l,k);
            cout<<'_';}
            else cout<<' ';


        }
        cout<<'|'; if(k==0) cout<<"\b ";
        cout<<endl;
    }
 gotoXY(32,2);
    cout<<"LETTER-PUNCH";
    gotoXY(25,9);
    cout<<"Press any key to begin."<<endl;
    getch();
    for(k=0;k<23;k++)
    {   cout<<'|';
        if(k==0) cout<<"\b ";
        for(l=1;l<78;l++)
        {
            if(k==0 || k==22)
            {gotoXY(l,k);
            cout<<'_';}
            else cout<<" ";
        }
        cout<<'|'; if(k==0) cout<<"\b ";
        cout<<endl;
    }
 gotoXY(32,2);
    cout<<"Letter-Punch";

    for(box=11;box<=75;box+=13)
    {
        gotoXY(box,8);
        cout<<" ___";
        gotoXY(box,9);
        cout<<"[   ]";
        gotoXY(box,10);
        cout<<"[___]";
    }
       gotoXY(60,3);
       cout<<"Level "<<level;
       char h=3;
       gotoXY(72,3);
       cout<<h<<h<<h<<h;
        int p=0;


        ifstream hs ("Highscore.txt");

    if(hs.is_open())
    {
          while( getline (hs,hscore))
         {
            gotoXY(2,3);
            cout<<"HI= "<<hscore<<'\n';
        }
         hs.close();
    }

    gotoXY(0,27);
    for(l=0;l<3;l++)
    cout<<"                                            "<<endl;



    int m,b[5]={13,26,26+13,26+13+13,26+13+13+13};
    //for(j=1;j<21;j++)
    while(1)
    {
        srand(time(NULL));
        i= rand() % 25 + 0;
        srand(time(NULL));
        m=rand() % 5;
        gotoXY(b[m],9);
        cout<<a[i]<<endl;
        double tm;
        clock_t t2;
        t2=clock();
        key = _getch();
        gotoXY(b[m],9);
        cout<<'a'<<"\b ";
        gotoXY(0,27);
        cout<<key<<endl;

        t2=clock()-t2;
        tm=t2/CLOCKS_PER_SEC;
        if(key==a[i]&&tm<=1.00)
        {
            cout <<"Correct!!!                      "<<endl;
            Beep(500,100);
            score=score+1;
            gotoXY(13,3);
            cout<<"Score= "<<score;
            ct=1; cp=1;
        }
        else if(tm>=(1.5/level))
            {
                cout<<"Oops :( Not Fast Enough!!!"; Beep(800,300);
                gotoXY(76-p,3); p++;
                cout<<"\b ";
                late++; mistake++; }

        else
        {
            cout<<"Oops :( Wrong Key!!!           ";
            gotoXY(76-p,3); p++;
            cout<<"\b ";
            Beep(800,500); wrn++; mistake++;
        }
         gotoXY(0,27);
        if((mistake+late)>=7){cout<<"YOU WERE TOO SLOW!!!     "<<endl;  break;}
        if((mistake+wrn)>=7){cout<<"YOU MADE TOO MANY MISTAKES."<<endl; break; }
        gotoXY(40,9);
        cout<<'a'<<"\b ";
        j++;
        if( (score%20)==0 && score!=0 && cp==1)
        {
            level++;
            gotoXY(60,3); cout<<"Level "<<level;
            cp=0;
            Beep(400,50);Beep(500,50);Beep(600,50);Beep(400,50);Beep(500,50);Beep(600,50);
            gotoXY(0,28); cout<<"LEVEL UP!!! PUNCH FASTER!!!";
            ct=0;
        }

    }
    gotoXY(11,27);
    cout<<endl<<endl<<"YOU GOT: "<<score<<" OUT OF "<<j;

    stringstream myStream(hscore);
    myStream>>hscr;
    if(score>=hscr)
    {
    ofstream hso("Highscore.txt");
    hso << score<<'\0';
    hso.close();
    }
    gotoXY(27,15);
    cout<<"Press Space to play again.";
    play=_getch();
    if(play==' ')
        goto x;

}
