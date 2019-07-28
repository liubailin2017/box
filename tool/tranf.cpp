#include<stdio.h>
int tranf(int c) {
    switch (c)
    {
    case '#':
        return '4';
        break;
    case '$':
        return '2';
        break;
    case '.':
        return '8';
        break;   default:
        break;
    case ' ':
        return '0';
        break;
    case '@':
        return '1';
        break;
    }
}

int main() {
    FILE *fs = fopen("src.txt","rb");
    FILE *ft = fopen("tar.txt","a+");

    int c = fgetc(fs);

    bool ise =false;
    while (!feof(fs))
    {
     
    fputc('{',ft);
    fputc('\n',ft);
    ise =false;
    for(int j = 0; j<16; j++) {
        if(c =='X') {
            ise = true;
        }
        bool isn = false;
        for(int i = 0; i< 28; i++) {
                if(c == '\n') isn =true;
                if(isn || ise){
                    fputc('0',ft);
                    fputc(',',ft);
                }else
                {
                    fputc(tranf(c),ft);
                    fputc(',',ft);
                    c=fgetc(fs);
                }
        }
        fputc('\n',ft);
        if(!ise) c = fgetc(fs);  
    }
    fputc('}',ft);
    fputc('\n',ft);
    fputc(',',ft);
    c = fgetc(fs);  
    }
     
    return 0;
}