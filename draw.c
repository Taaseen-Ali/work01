#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_oct1(int x0, int y0, int x1, int y1, screen s, color c);
void draw_oct2(int x0, int y0, int x1, int y1, screen s, color c);
void draw_oct7(int x0, int y0, int x1, int y1, screen s, color c);
void draw_oct8(int x0, int y0, int x1, int y1, screen s, color c);

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  float m= (float) (y0-y1)/(x0-x1);
  if(x1<x0){
    int cpy = x0;
    x0 = x1;
    x1 = cpy;
    cpy = y0;
    y0 = y1;
    y1 = cpy;
  }
  
  if(m>=0){
    if(m<=1)
      draw_oct1(x0, y0, x1, y1, s, c);
    else
      draw_oct2(x0, y0, x1, y1, s, c);
  }

  if(m<0){
    if(m>=-1)
      draw_oct7(x0, y0, x1, y1, s, c);
    else
      draw_oct8(x0, y0, x1, y1, s, c);
  }
}


void draw_oct1(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y,a,b,d;
  x=x0;
  y=y0;
  a=y1-y0;
  b=-(x1-x0);
  d=2*a+b;
  while(x<=x1){
    plot(s,c,x,y);
    if(d>0){
      y++;
      d+=2*b;
    }
    x++;
    d+=2*a;
  }
      
}


void draw_oct2(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y,a,b,d;
  x=x0;
  y=y0;
  a=y1-y0;
  b=-(x1-x0);
  d=2*a+b;
  while(y<=y1){
    plot(s,c,x,y);
    if(d<0){
      x++;
      d+=2*a;
    }
    y++;
    d+=2*b;
  }
      
}

void draw_oct7(int x0, int y0, int x1, int y1, screen s, color c) {

  int x,y,a,b,d;
  x=x0;
  y=y0;
  a=y1-y0;
  b=-(x1-x0);
  d=2*a+b;
  while(x<=x1){
    plot(s,c,x,y);
    if(d<0){
      y--;
      d-=2*b;
    }
    x++;
    d+=2*a;
  }
      
}

void draw_oct8(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y,a,b,d;
  x=x0;
  y=y0;
  a=y1-y0;
  b=-(x1-x0);
  d=2*a+b;
  while(y>=y1){
    plot(s,c,x,y);
    if(d>0){
      x++;
      d+=2*a;
    }
    y--;
    d-=2*b;
  }

  
}

