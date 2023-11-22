#ifndef OLIVE_C
#define OLIVE_C


void olivec_fill(uint32_t* pixels,size_t width,size_t height,uint32_t color){



for (size_t i=0;i<width*height;i++){
    pixels[i]=color;
}





// for (size_t y=0;y<height;++y){
//     for(size_t x=0;x<width;x++){
//         pixels[y*width+x]=color;
//     }
// }


};


typedef int Errno;


#define return_defer(value) do{ result=(value);goto defer; } while (0)
int olivec_save_to_ppm_file(uint32_t* pixels,size_t width,size_t height ,const char* filepath){

    

    int result=0;

    FILE *f=NULL;
    {


     f=fopen(filepath,"wb");

     if(f==NULL) {
       return_defer(-1);
     }

     fprintf(f,"P6\n%zu %zu 255\n",width,height);

     if(ferror(f)) {
       return_defer(-1);
     };

     for (size_t i=0;i<width*height;i++){


           uint32_t pixel=pixels[i];
           uint8_t bytes[3]={ 
            (pixel>>(8*0))&0xFF,
            (pixel>>(8*1))&0xFF,
            (pixel>>(8*2))&0xFF,
           };

           fwrite(bytes,sizeof(bytes),1,f);
           if (ferror(f)) return_defer(-1);

      }







    }

defer:
     if (f) fclose(f);
     return result;

    

}


#endif //OLIVE_C