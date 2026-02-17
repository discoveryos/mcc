#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc<3){ printf("Usage: mld out.mir in1.mir in2.mir ...\n"); return 1; }

    FILE *out=fopen(argv[1],"w");
    if(!out){ perror("fopen"); return 1; }

    for(int i=2;i<argc;i++){
        FILE *in=fopen(argv[i],"r");
        if(!in){ perror("fopen"); continue; }

        char line[1024];
        while(fgets(line,1024,in)) fputs(line,out);
        fclose(in);
    }

    fclose(out);
    return 0;
}
