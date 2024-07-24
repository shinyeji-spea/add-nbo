#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

uint32_t Fileread(const char* name){
        FILE* File;
        uint32_t detail = 0;

        File = fopen(name ,"rb");

        if(File){
                printf("fileopen success\n");
                if(fread(&detail, sizeof(uint32_t), 1, File) != 1){
			printf("file size is not 32bit!!!!!!!\n");
			return NULL;
		}
		fclose(File);
        }
        else {
                printf("fileopen error '%s'\n", name);
		return NULL;
        }
        return detail;
}

uint32_t add_nbo(const char* file1, const char* file2){

        uint32_t n1 = ntohl(Fileread(file1));
        uint32_t n2 = ntohl(Fileread(file2));
       
	if((n1 != NULL) & (n2 != NULL)) {
		uint32_t addn = n1 + n2;
        	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", n1,n1,n2,n2,addn,addn);

		return addn;
	}
	else return 0;
}

int main(int argc, char *argv[]){

        const char *file1 = argv[1];
        const char *file2 = argv[2];

	add_nbo(file1, file2);
}
