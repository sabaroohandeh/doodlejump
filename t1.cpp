
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <string>
#include <cmath>
#include "SDL2/SDL2_gfxPrimitives.h"
#include <cstdlib>
#include <time.h>
#include <sstream>
using namespace std;
///////////////////////////////
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 1000;
////////////////////////////////////////
SDL_Window*gWindow= NULL;
SDL_Surface*gScreenSurface=NULL;
SDL_Surface*gpngsurface=NULL;
SDL_Renderer *gRenderer;
///////////////////////////////////////////

SDL_Texture* LoadTexture(const char* imagename , SDL_Renderer* renderer){

SDL_Surface* tempSurface = IMG_Load(imagename);
SDL_Texture* texure = SDL_CreateTextureFromSurface(renderer , tempSurface);
SDL_FreeSurface(tempSurface);
return texure;

}
int main(int argc, char const *argv[]) {
gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
gRenderer = SDL_CreateRenderer(gWindow , -1 , 0);
gScreenSurface = SDL_GetWindowSurface( gWindow );
SDL_SetRenderDrawColor(gRenderer,255 , 255 , 255 , 255);
SDL_Texture* tex =LoadTexture("h.png" , gRenderer);
SDL_Texture* background=LoadTexture("background.png",gRenderer);
SDL_Texture* gameover=LoadTexture("gameover.png",gRenderer);
SDL_Texture* start=LoadTexture("start.png",gRenderer);
SDL_Texture* normwood=LoadTexture("normwood.png",gRenderer);
SDL_Texture* doublewood=LoadTexture("doublewoods.png",gRenderer);
SDL_Texture* invwood=LoadTexture("invwood.png",gRenderer);
SDL_Texture* doodle=LoadTexture("doodle2.png",gRenderer);
///////////////////////////////////////
int starter=0;
int wood[10][5];
int red[10];
int blue[10];
int green[10];
    for(int y=0;y<10;y++)
        red[y]=255;

     for(int g=0;g<10;g++)
        green[g]=100;

     for(int x=0;x<10;x++)
        blue[x]=0;

srand(time(0));
    int circlex;
    int circley;
    int score=0;
    int vx=4;
    int vy=20;
    bool keyDown = false;
    bool temp=1;
    int shetab=1;
    int shetab2=1;
    int y=250;
for(int z=0;z<10;z++)
wood[z][3]=1;

int doublemaker1=rand()%10;
int doublemaker2=rand()%10;

if(doublemaker1==doublemaker2)
doublemaker2=rand()%10;

red[doublemaker2]=255;
red[doublemaker1]=0;
green[doublemaker2]=255;
green[doublemaker1]=0;
blue[doublemaker2]=255;
blue[doublemaker1]=200;

wood[doublemaker1][3]=0;
wood[doublemaker2][3]=2;

for(int i=0;i<10;i++)
{
wood[i][2]=0;
wood[i][4]=0;
}
for(int j=0;j<10;j++)
wood[j][0]=rand()%681;
 for(int k=0;k<10;k++)
wood[k][1]=100*k -50 ;



circlex=wood[9][0]+60;
circley=wood[9][1]-10;
//////////////////////////////////////////////////////////start
bool quit=false;
while(!quit)
{
  SDL_Rect t;
	t.x=0;
	t.y=0;
  SDL_QueryTexture(start , NULL , NULL , &t.w , &t.h);
  SDL_RenderClear(gRenderer);
  SDL_RenderCopy(gRenderer,start,NULL,&t);
  SDL_RenderPresent(gRenderer);

// ///////////////////
SDL_Event event1;
while(SDL_PollEvent(&event1))
{
if(event1.type == SDL_QUIT)
{
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
 return 0;
  }
  if(event1.type == SDL_KEYDOWN)
  {
      if(event1.key.keysym.sym == SDLK_SPACE)
      {

          quit=true;
          }
           if(event1.key.keysym.sym == SDLK_ESCAPE)
      {

          return 0;
          }

      }
}}

/////////////////////
while(starter==0)
{
  SDL_RenderClear(gRenderer);
  SDL_Rect t;
t.x=0;
t.y=0;
SDL_QueryTexture(background , NULL , NULL , &t.w , &t.h);
SDL_RenderCopy(gRenderer,background,NULL,&t);
///////////////////////////////////////
if(wood[doublemaker2][1]>1000)
{
  red[doublemaker2]=255;
  blue[doublemaker2]=255;
  green[doublemaker2]=255;
     temp=1;
     wood[doublemaker2][4]=0;
}
for(int a=-1;a>=-10;a--)
{
  if(wood[a+10][1]>1000)
  {
      wood[a+10][0]=rand()%681;
      wood[a+10][2]=0;
      wood[a+10][1]=-50;
}
}
/////////////////////////////raft biroon biad too
if( circlex > 800)
   circlex=10;
if(circlex < 5)
   circlex=795;
//////////////////////////////////////
if(circley < 200){
circley=200;
score +=vy;
for(int i=0;i<10;i++)
wood[i][1]+=vy;}
//////////////////////////////////////

  for(int l=0;l<10;l++)
{

if(vy<0 && wood[l][0]<circlex && circlex<wood[l][0]+120 && wood[l][1]-40<circley && circley<wood[l][1]&&wood[l][3]==1)
  {
   vy=20;
shetab=1;
}
if(vy<0 && wood[l][0]<circlex && circlex<wood[l][0]+120 && wood[l][1]-40<circley && circley<wood[l][1]&&wood[l][3]==0)
  {

   vy=40;
shetab=1;
}
if(vy<0 && wood[l][0]<circlex && circlex<wood[l][0]+120 && wood[l][1]-40<circley && circley<wood[l][1] &&wood[l][3]==2 && temp==1)
  {
wood[l][4]=3;
   red[l]=0;
   blue[l]=0;
   green[l]=0;
temp=0;
   vy=20;
shetab=1;

}
}
/////////////////////////////////////

SDL_Rect rect1;
for(int m=0;m<10;m++)
{
if(wood[m][3]==1){
rect1.x=wood[m][0];
rect1.y=wood[m][1];
SDL_QueryTexture(normwood , NULL , NULL , &rect1.w , &rect1.h);
SDL_RenderCopy(gRenderer,normwood,NULL,&rect1);

}}
///////////////////////////////////////////////////
SDL_Rect rect0;
for(int vb=0;vb<10;vb++)
{
if(wood[vb][4]!=3)
if(wood[vb][3]==2){
rect0.x=wood[vb][0];
rect0.y=wood[vb][1];
SDL_QueryTexture(invwood , NULL , NULL , &rect0.w , &rect0.h);

SDL_RenderCopy(gRenderer,invwood,NULL,&rect0);

}}
////////////////////////////////////////////////
SDL_Rect rect3;
for(int n=0;n<10;n++)
{
if(wood[n][3]==0){
rect3.x=wood[n][0];
rect3.y=wood[n][1];
SDL_QueryTexture(doublewood , NULL , NULL , &rect3.w , &rect3.h);
SDL_RenderCopy(gRenderer,doublewood,NULL,&rect3);

}}

if(circley>1000)
{
    for(int i=0;i<10;i++)
    {
          wood[i][1]+=vy;

          if(wood[0][1]<-100 && wood[1][1]<-100 && wood[2][1]<-100 && wood[3][1]<-100 &&
           wood[4][1]<-100 && wood[5][1]<-100 && wood[6][1]<-100 &&
           wood[7][1]<-100 && wood[8][1]<-100 && wood[9][1]<-100  )
          {
            SDL_Rect t;
          	t.x=0;
          	t.y=0;
            SDL_QueryTexture(gameover , NULL , NULL , &t.w , &t.h);
          SDL_RenderCopy(gRenderer,gameover,NULL,&t);
          }
      }
    }
    ///////////////////////
    SDL_Rect offset;
    offset.x = circlex-10;
    offset.y = circley-10;
    offset.w = offset.h = 50;
  SDL_RenderCopy(gRenderer,doodle,NULL,&offset);
  //////////////////////////////////////////////////////////////
  circley-=vy;
  vy-=shetab;

////////////////////////////////
   SDL_Event event;

         while(SDL_PollEvent(&event))
          {
              if(event.type == SDL_QUIT)
              {
                SDL_DestroyWindow( gWindow );
               gWindow = NULL;
               return 0;
              }
              }
              ///////////////////////
             if(event.type == SDL_KEYDOWN)
              {

                  keyDown = true;


                  if(event.key.keysym.sym == SDLK_LEFT)
                  {
                      vx = -10;
                       circlex += vx;
                    }

                  if(event.key.keysym.sym == SDLK_RIGHT)

              {
                     vx = +10;
                      circlex += vx;
              }
              if (event.type == SDL_KEYUP)
                  keyDown = false;

      }
      if (event.type == SDL_KEYUP)
          keyDown = false;
  ///////////////////////////////////////
          SDL_RenderPresent(gRenderer);
          SDL_Delay(50);
}

    return 0;
}
