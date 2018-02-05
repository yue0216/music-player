#include <stdio.h>

#include <dos.h>

#include <stdlib.h>

#include <time.h>

#include <bios.h>

#include <conio.h>

#define  N1  64

#define  N2  32

#define  N4  16

#define  N8  8

#define  N16 4

#define  END 1

void PlaySound(int fre)
{
    int control=0;
    if(fre)
        {
         outportb(0x43,0xb6);
         fre=(unsigned)(1193180L/fre);
         outportb(0x42,(char)fre);
         outportb(0x42,(char)(fre>>8));
         control=inportb(0x61);
         outportb(0x61,control|0x03);
        }
}
void MeasureTime(int dur)
{
    int control;
    clock_t goal;
    goal=(clock_t)dur+clock( );
        while(goal>clock( ));
    control=inportb(0x61);
    if(dur)
         outportb(0x61,control&0xfc);
}
int IdentifyPre(char c)
{
    int fre=0;
  switch(c)
  {
  case'q':fre=131;break;
  case'w':fre=147;break;
  case'e':fre=165;break;
  case'r':fre=175;break;
  case't':fre=196;break;
  case'y':fre=220;break;
  case'u':fre=247;break;
  case'a':fre=262;break;
  case's':fre=296;break;
  case'd':fre=330;break;
  case'f':fre=349;break;
  case'g':fre=392;break;
  case'h':fre=440;break;
  case'j':fre=494;break;
  case'z':fre=523;break;
  case'x':fre=587;break;
  case'c':fre=659;break;
  case'v':fre=698;break;
  case'b':fre=784;break;
  case'n':fre=880;break;
  case'm':fre=988;break;
  default:;
  }
  return fre;
}

void PlayRecord(void)
{
    char c[300],name[50];
    int i=0,pre=0,dur=N8;
    FILE *p;
    printf("please write the name of the file\n");
    getchar();
    scanf("%s",name);
    p=fopen(name,"r");
    while(!feof(p))
    {
        if(kbhit())break;
        c[i]=fgetc(p);
        pre=IdentifyPre(c[i]);
        PlaySound(pre);
        MeasureTime(dur);
        i=i+1;
    }
    fclose(p);
}


enum NOTES{

C10=131,D10=147,E10=165,F10=175,G10=196,A10=220,B10=247,
C0=262,D0=296,E0=330,F0=349,G0=392,A0=440,B0=494,
C1=523,D1=587,E1=659,F1=698,G1=784,A1=880,B1=988,
C2=1047,D2=1175,E2=1319,F2=1397,G2=1568,A2=1760,B2=1976,M=0
};

typedef enum NOTES SONG;

SONG song[]={G0,N4,E0,N8,G0,N8,E0,N8,G0,N4+N8,A0,N8,G0,N8,E0,N8,A0,N8,G0,N4,M,N8,C0,N4,C0,N8,D0,N8,E0,
N4,
G0,N8,E0,N8,D0,N4,E0,N8,G0,N4,M,N8,G0,N8,G0,N8,A0,N8,G0,N8,E0,N8,G0,N4,G0,N8,A0,N8,
G0,N8,C1,N8,A0,N8,G0,N4,M,N8,C0,N4,G0,N8,E0,N8,D0,N8,C0,N8,D0,N4,E0,N8,G0,N4+N8,D0,N8,E0,
N4,C0,N4,C0,N4,M,N8,G0,N8,E1,N4,D1,N8,C1,N8,A0,N8,G0,N8,G0,N4,A0,N8,A0,N4,G0,N8,A0,N8+N16,
C1,N16,E1,N8,C1,N8,D1,N4,M,N8,G0,N8,E1,N4,D1,N8,C1,N8,A0,N8,G0,N8,G0,N4,A0,N8,A0,N4,G0,N8,
A0,N8+N16,E1,N8,D1,N8,D1,N4,M,N8,E1,N4,D1,N8+N16,C1,N16,A0,N8,G0,N8,G0,N4,C1,N4,A0,N8,G0,
N8,E0,N8,D0,N8,C0,N4,M,N8,D0,N8,E0,N8,G0,N4+N8,M,N8,G0,N8,A0,N8,C1,N4,END,END};

main()
{
  char a[300],q,name[50];
  int i=0,fre,dur=4,control=0,note=0,f,l,m;
  clock_t  goal;
  FILE *p;
  printf("input a number:\n");
  printf("1.play by yourself.\n");
  printf("2.play a song.\n");
  printf("3.play the record song.\n");
  scanf("%d",&l);
  if(l==1)
  {
    a[0]=getch();
    for(m=0;;m++)
    {
    if(a[i]!='0')
    {
       switch(a[i])
      {
        case'1':fre=131;break;
        case'2':fre=147;break;
        case'3':fre=165;break;
        case'4':fre=175;break;
        case'5':fre=196;break;
        case'6':fre=220;break;
        case'7':fre=247;break;
        case'Q':fre=262;break;
        case'W':fre=296;break;
        case'E':fre=330;break;
        case'R':fre=349;break;
        case'T':fre=392;break;
        case'Y':fre=440;break;
        case'U':fre=494;break;
        case'A':fre=523;break;
        case'S':fre=587;break;
        case'D':fre=659;break;
        case'F':fre=698;break;
        case'G':fre=784;break;
        case'H':fre=880;break;
        case'J':fre=988;break;
        case'Z':fre=1047;break;
        case'X':fre=1175;break;
        case'C':fre=1319;break;
        case'V':fre=1397;break;
        case'B':fre=1568;break;
        case'N':fre=1760;break;
        case'M':fre=1976;break;
        case'q':fre=262;break;
        case'w':fre=296;break;
        case'e':fre=330;break;
        case'r':fre=349;break;
        case't':fre=392;break;
        case'y':fre=440;break;
        case'u':fre=494;break;
        case'a':fre=523;break;
        case's':fre=587;break;
        case'd':fre=659;break;
        case'f':fre=698;break;
        case'g':fre=784;break;
        case'h':fre=880;break;
        case'j':fre=988;break;
        case'z':fre=1047;break;
        case'x':fre=1175;break;
        case'c':fre=1319;break;
        case'v':fre=1397;break;
        case'b':fre=1568;break;
        case'n':fre=1760;break;
        case'm':fre=1976;break;
        default:;
        }
      if(fre)
         {                             /*若频率值fre非0*/

           outportb(0x43,0xb6);            /*初始化2号定时器 */

           fre=(unsigned)(1193180L/fre);   /*计算计数初值 */

           outportb(0x42,(char)fre);       /*先写计数初值的低8位*/

           outportb(0x42,(char)(fre>>8));  /*再写计数初值的高8位*/

           control=inportb(0x61);          /*读0x61的状态*/

           outportb(0x61,control|0x03); /*将第0位，第1位置1，使喇叭发声*/

         }


           goal=(clock_t)dur+clock( );

     	    while(goal>clock( ));

          if(dur)

             outportb(0x61,control);

         i++;

         a[i]=getch();
      }

      else
      {
        getchar();
        printf("Do you want to save the song?\n");
        printf("Please choose Y or N.\n");
        scanf("%c",&q);
        if(q=='Y'||q=='y')
        {
            printf("Please input the name of the song.\n");
            scanf("%s",name);
            if((p=fopen(name,"w"))==NULL)
            {
            printf("Failure to open %s\n",name);
            exit(0);
            }
            fwrite(a,sizeof(char),i,p);
            fclose(p);
             break;
        }
        else
        {
            break;
        }
      }
    }
  }
    if(l==2)
    {
        while(song[note]!=END&&song[f]!=END)
            {

        fre=song[note];

        dur=song[note+1];
        if(kbhit()) break;

         if(fre)
            {                             /*若频率值fre非0*/

              outportb(0x43,0xb6);            /*初始化2号定时器 */

              fre=(unsigned)(1193180L/fre);   /*计算计数初值 */

              outportb(0x42,(char)fre);       /*先写计数初值的低8位*/

              outportb(0x42,(char)(fre>>8));  /*再写计数初值的高8位*/

              control=inportb(0x61);          /*读0x61的状态*/

              outportb(0x61,control|0x03); /*将第0位，第1位置1，使喇叭发声*/

            }
            goal=(clock_t)dur+clock( );

	        while(goal>clock( ));

            if(dur)

            outportb(0x61,control);

            note+=2;

            f=note+1;
            }

    }
    if(l==3)
    {
        printf("please input the name of the song.\n");
        getchar();
        scanf("%s",name);
        p=fopen(name,"r");
        while(!feof(p))
        {
            if(kbhit())break;
            a[i]=fgetc(p);
            fre=IdentifyPre(a[i]);
            PlaySound(fre);
            MeasureTime(dur);
            i=i+1;
        }
        fclose(p);
    }
}
