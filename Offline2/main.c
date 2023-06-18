#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "utils.h"

Image *read_PPM(char *filename)
{
    /* opens a PPM file, constructs an Image object and returns a pointer to it.
    Use fopen(), fscanf(), fprintf(), and fclose().*/
    FILE *fp;
    Image *img=malloc(sizeof(Image));
    img->cols=malloc(sizeof(int));
    img->rows=malloc(sizeof(int));
    fp=freopen(filename, "r", stdin);
    char str[2];
    fscanf(fp, "%s", str);
    int i, j, rgb;
    fscanf(fp, "%d%d%d", &img->cols, &img->rows, &rgb);
    img->image=malloc(img->rows*sizeof(int*));
    for(i=0; i<img->rows; i++)
        img->image[i]=malloc(img->cols*sizeof(int)*3);
    for(i=0; i<img->rows; i++)
        for(j=0; j<img->cols; j++)
            fscanf(fp, "%d%d%d", &img->image[i][j].R, &img->image[i][j].G, &img->image[i][j].B);
    fclose(fp);
    return img;
}

void write_PPM(Image *image, char *filename)
{
    /* takes an Image object and writes to filename in PPM format.*/
    FILE *fp;
    fp=freopen(filename, "w", stdout);
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", image->cols, image->rows);
    fprintf(fp, "%d\n", 255);
    int i, j;
    for(i=0; i<image->rows; i++)
    {
        for(j=0; j<image->cols; j++)
            fprintf(fp, "%3d %3d %3d   ", image->image[i][j].R, image->image[i][j].G, image->image[i][j].B);
        printf("\n");
    }
    fclose(fp);
}

void free_image(Image *image)
{
    /* takes an Image object and frees all the memory associated with it.
    This involves not only calling free on image but also on the appropriate
    members of it.
    */
    free(image->cols);
    free(image->rows);
    free(image->image);
    free(image);
}


Color *evaluate_one_pixel(Image *image, int row, int col)
{
    /* Takes an Image object and returns what color the pixel at the given row/col
    should be in the secret image. This function should not change image*/
    Color *c=malloc(sizeof(Color));
    c->B=malloc(sizeof(int));
    c->G=malloc(sizeof(int));
    c->R=malloc(sizeof(int));
    if(image->image[row][col].B%2==0)
    {
        c->B=0;
        c->R=0;
        c->G=0;
    }
    else
    {
        c->B=255;
        c->R=255;
        c->G=255;
    }
    return c;
}

Image *get_secret_image(Image *image)
{
    /* takes an Image object, and constructs the secret image from it by extracting
    the LSB of the B channel. You should call evaluate_one_pixel() here. */
    int i, j;
    Color *c;
    Image *img=malloc(sizeof(Image));
    img->cols=malloc(sizeof(int));
    img->rows=malloc(sizeof(int));
    img->rows=image->rows;
    img->cols=image->cols;
    img->image=malloc(img->rows*sizeof(int*));
    for(i=0; i<img->rows; i++)
        img->image[i]=malloc(img->cols*sizeof(int)*3);
    for(i=0; i<image->rows; i++)
    {
        for(j=0; j<image->cols; j++)
        {
            c=evaluate_one_pixel(image, i, j);
            img->image[i][j]=*c;
        }
    }
    return img;
}

int main()
{
    /* Call read_PPM(), write_PPM(), free_image(), get_secret_image() in some order
    to obtain the hidden message.*/
    Image *img, *img_;
    img=read_PPM("DennisRitchie.ppm");
    img_=get_secret_image(img);
    write_PPM(img_, "output.ppm");
    free_image(img);
    return 0;
}


