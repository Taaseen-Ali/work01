#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c1;
  color c2;
  color c3;
  color c4;

  c1.red = 0;
  c1.green = MAX_COLOR;
  c1.blue = 0;

  
  c2.red = 0;
  c2.green = 0;
  c2.blue = MAX_COLOR;

  c3.red = MAX_COLOR;;
  c3.green = 0;
  c3.blue = 0;

  c4.red = MAX_COLOR;
  c4.green = 0;
  c4.blue = MAX_COLOR;

  clear_screen(s);

 
  for(int i=0; i<500; i+=7){
    color *col1 = &c1;
    color *col2 = &c2;
    if(i>255){
      col1 = &c2;
      col2 = &c3;
    }
    draw_line(250,250,500,i,s,*col1);
    draw_line(250,250,i,500,s,*col2);
  }
  
  for(int i=0; i<500; i+=7){
    color *col1 = &c1;
    color *col2 = &c2;
    if(i>255){
      col1 = &c2;
      col2 = &c3;
    }
    draw_line(250,250,i,0,s,*col1);
    draw_line(250,250,0,i,s,*col2);
  }


  display(s);
  save_extension(s, "lines.png");
}
