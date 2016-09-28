#include <stdio.h>
#include <stdlib.h>

unsigned char* ReadBMP(char* filename, int** arr)
{
	int i;
	unsigned char header[54];
	FILE* img = fopen(filename,"rb");
	fread(header, sizeof(unsigned char), 54,img ); // read the 54-byte header

	// extract image height and width from header
	int width = *(int*)&header[18];    
	int height = *(int*)&header[22];    
	int padding=0; while ((width*3+padding) % 4!=0) padding++;
	arr=(int**) malloc(sizeof(int*) * (width*3+padding));
	for(i=0; i<width*3+padding; i++)
	{
		arr[i] = (int*) malloc(sizeof(int) * height);
	}
	int widthnew=width*3+padding;
	unsigned char* data =  (unsigned char*) malloc(sizeof(unsigned char) * widthnew);
	printf("%d", padding);

	for (int i=0; i<height; i++ ) {                                    
		fread( data, sizeof(unsigned char), widthnew, img);

		for (int j=0; j<width*3; j+=3)                                
	 	{ //Convert BGR to RGB and store                      

			arr[i][j+0] = data[j+2];                              
			arr[i][j+1] = data[j+1];                              
			arr[i][j+2] = data[j+0]; 
		}
	}                        
	fclose(img); //close the file

	FILE* imgwrite = fopen("output.bmp", "wb");
	fwrite(header, sizeof(unsigned char), 54, imgwrite);

	for (int i=0; i<height; i++ ) {                                    
		for (int j=0; j<width*3; j+=3)                                
	 	{ //Convert BGR to RGB and store                      

			data[j+2] = arr[i][j+0] ; 
			data[j+1] = arr[i][j+1] ;             
			data[j+0] = arr[i][j+2] ; 
		}
		fwrite( data, sizeof(unsigned char), widthnew, imgwrite);
	}
	fclose(imgwrite);

}

void main(int argc, char *argv[])
{

	int **arr;
	ReadBMP(argv[1],arr );

}