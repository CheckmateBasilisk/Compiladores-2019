
#include<stdio.h>
#include<ctype.h>

enum{
    UINT = 1024,
    FLT
};

int recognize(){
    FILE *input;
    input = stdin;
    int c;
    
    c = getc(input);
    if(c == '0'){ // if input starts with '0'
        int c = getc(input);
        if(c == EOF){
            return UINT;
        } else if(c == '.'){ // 0 followed by '.'
            int c;
            do{
                c = getc(input);
            }while(isdigit(c));
 
            if((c == 'e') || (c == 'E')){    //0. folloed by [eE]
                c = getc(input);
                if(c == EOF){
                    return -1;
                }
                if((c == '+') || (c == '-')){
                    c = getc(input);
                    if(c == EOF){
                        return -1;
                    }
                }

                while(isdigit(c)){
                    c = getc(input);    //check if c belongs to [0-9]*
                }

                if(c == EOF){
                    return FLT;
                }else {
                    return -1;
                }
            }
            
            if(c == EOF){
                return FLT; 
            }
            return -1;// 0. followed by anything else than EOF
        } else if(c == 'e'||'E'){ // 0 followed by [eE]
            c = getc(input);
            if(c == EOF){
                return -1;
            }
            if((c == '+') || (c == '-')){
                c = getc(input);
                if(c == EOF){
                    return -1;
                }
            }

            while(isdigit(c)){
                c = getc(input);    //check if c belongs to [0-9]*
            }

            if(c == EOF){
                return FLT;
            }else {
                return -1;
            }
            return -1;  //if input does not match 0|[1-9]+|[eE]|'.' => error
        }else { // 0 followed by anything else
            return -1;  //if first character is a 0 followed by anything else => error
        }

    } else if(isdigit(c)){ //if input starts with [1-9]  .Passing previous if guarantees it doesnt start with '0'

        do{
            c = getc(input);    //check if c belongs to [0-9]*
        }while(isdigit(c));


        if(c == EOF){
            return UINT;
        }else if(c == '.'){
            do{
                c =(getc(input));   //check if c belongs to [0-9]*
            }while(isdigit(c));

            if(c == EOF){   //if input is [1-9] [0-9]* followed by EOF
                return FLT;
            }else           //if input is [1-9] [0-9]* followed by anything else => error
                return -1;
        

        } else if((c == 'e') || (c == 'E')){    //if input is [1-9][0-9]* followed by [eE] 
            c = getc(input);
            if(c == EOF){
                return -1;
            }
            if((c == '+') || (c == '-')){
                c = getc(input);
                if(c == EOF){
                    return -1;
                }
            }

            while(isdigit(c)){
                c = getc(input);    //check if c belongs to [0-9]*
            }
            if(c == EOF){
                return FLT;
            }else {
                return -1;
            }
        }else{
            return -1;  //if input is [1-9] followed by anything else => error
        }
        
    } else if(c == '.'){    //if input starts with '.'
        c = getc(input);
        if(c == EOF)    //if input is '.' followed by nothing => error
            return -1;
        
        while(isdigit(c))
            c = (getc(input));
    
        if(c == EOF){   //if input is '.' [0-9]+
            return FLT;
        }else if((c == 'e') || (c == 'E')){   //if input is '.' [0-9] [eE]
            c = getc(input);
            if(c == EOF){
                return -1;
            }
            if((c == '+') || (c == '-')){
                c = getc(input);
                if(c == EOF){
                    return -1;
                }
            }

            while(isdigit(c)){
                c = getc(input);    //check if c belongs to [0-9]*
            }


            if(c == EOF){
                return FLT;
            }else {
                return -1;
            }
            
        }else
            return -1;  //if input is '.' [0-9]+ followed by anything that is not digit => error
    
    } else if((c == 'e') || (c == 'E')){    //if input starts with [eE]
        c = getc(input);
        if(c == EOF){
            return -1;
        }
        if((c == '+') || (c == '-')){
            c = getc(input);
            if(c == EOF){
                return -1;
            }
        }

        while(isdigit(c)){
            c = getc(input);    //check if c belongs to [0-9]*
        }


        if(c == EOF){
            return FLT;
        }else {
            return -1;
        }
        
    }else
        return -1;  //if input does not match 0|[1-9]+|[eE]|'.' => error
}

int main(int argc, char *argv[]){
    int i = recognize();

    if(i == FLT) printf("it is a float\n");
    else if(i == UINT) printf("it is an u int\n");
    
    return 0;
}


