#include<stdio.h>

#include "olive.c"

#include<stdint.h>
#include<string.h>
#include <errno.h>



#define WIDTH 200

#define HEIGHT 200



static uint32_t pixels[HEIGHT*WIDTH];



void olivec_fill_rect(uint32_t *pixels,size_t pixels_width,size_t pixels_height,int x,int y ,int w,int h){
    
}



int main(void){


  

   olivec_fill(pixels,WIDTH,HEIGHT,0XFF00FF00);

   Errno err=olivec_save_to_ppm_file(pixels,WIDTH,HEIGHT,"output.ppm");

  


   if(err){
    
    fprintf(stderr,"Error couldn'd saved file");
    return 1;

   }

   printf("Virtual");




    return 0;
}