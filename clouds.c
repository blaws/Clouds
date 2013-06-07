// Benjamin Laws, CSE 21211-04

#include <math.h>
#include <stdlib.h>
#include "gfx.h"

void cloudbox(int x1,int y1,int x2,int y2,int g1,int g2,int g3,int g4){
  if(abs(x1-x2)<2 && abs(y1-y2)<2) return;

  int g,g12,g13,g24,g34,x12,y12;
  g12 = (g1+g2)/2;
  g13 = (g1+g3)/2;
  g24 = (g2+g4)/2;
  g34 = (g3+g4)/2;
  x12 = (x1+x2)/2;
  y12 = (y1+y2)/2;

  // color corners
  gfx_color(g1,g1,g1);
  gfx_line(x1,y1,x1,y1);
  gfx_color(g2,g2,g2);
  gfx_line(x2,y1,x2,y1);
  gfx_color(g3,g3,g3);
  gfx_line(x1,y2,x1,y2);
  gfx_color(g4,g4,g4);
  gfx_line(x2,y2,x2,y2);

  // color edges
  gfx_color(g12,g12,g12);
  gfx_line(x12,y1,x12,y1);
  gfx_color(g13,g13,g13);
  gfx_line(x1,y12,x1,y12);
  gfx_color(g24,g24,g24);
  gfx_line(x2,y12,x2,y12);
  gfx_color(g34,g34,g34);
  gfx_line(x12,y2,x12,y2);

  // color center
  g = (g1+g2+g3+g4)/4 + pow(-1,rand()%2)*(rand()%(abs(x2-x1)/2+1));
  if(g>255) g=255;
  if(g<0) g=0;
  gfx_color(g,g,g);
  gfx_line(x12,y12,x12,y12);

  // recursion
  cloudbox(x1,y1,x12,y12,g1,g12,g13,g);
  cloudbox(x12,y1,x2,y12,g12,g2,g,g24);
  cloudbox(x1,y12,x12,y2,g13,g,g3,g34);
  cloudbox(x12,y12,x2,y2,g,g24,g34,g4);
}

int main(void){
  int xsize=500,ysize=500,a,b,c,d;
  char q;

  gfx_open(xsize,ysize,"Fractal Clouds");
  srand(time(NULL));
  a = rand()%256;
  b = rand()%256;
  c = rand()%256;
  d = rand()%256;
  cloudbox(0,0,xsize,ysize,a,b,c,d);

  while(q!='q') q=gfx_wait();
  return 0;
}
