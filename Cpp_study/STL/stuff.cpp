#include<cstdio>
#include<cstdlib>

#define field(x,y)  (field + x*m + y)

int T, id;
char *field;

int n, m ,c ,f;

long out_C, out_F;

void _initField(int n, int m){
    int i,j;    
    field = (char*)malloc(sizeof(int)*n*m);
    for(i=0; i<n; ++i){
        scanf("\n");
        for(j=0; j<m; ++j){
            scanf("%c", field(i,j));
            *field(i,j) -= '0';//<cancel>
        }
    }
    //for(i=0; i<m*n; ++i)        printf("%c", *(field+i));//>
}

int _checkRangeX(int x0, int x1, int y){
    int i;
    for( i = x0; i < x1+1; ++i){
        if (*field(i,y))    return 1;
    }
    return 0;
}

int _checkRangeY(int x, int y0, int y1){
    int i;
    for( i = y0; i < y1+1; ++i){
        if (*field(x,i))    return 1;
    }
    return 0;
}

void _calcF(int x2, int y0){
    if( ++x2 < n ){
        if(!( *field(x2, y0))) ++out_F; 
    }
}

void _calcC(){
        int TESTNUM = 1;//<test>
    int x1, x2, y0, y1, y2;
    char flag_x1_inc;
    for(x1=0 ;x1 < n - 2;++x1){
        for (x2=x1+2;x2 < n ;++x2){

            flag_x1_inc = 1;

            for(y0=0;y0 < m -1 ;++y0){

                if ( _checkRangeX(x1, x2, y0))  break;
                flag_x1_inc = 0;

                for(y2=y0+1; y2 < m ;++y2){
                    if ( _checkRangeY(x2, y0, y2))  break;

                    for(y1=y0+1; y1 < m ;++y1){
                        if ( _checkRangeY(x1, y0, y1))  break;
                        ++out_C;
                        printf("Cout%2d: x1:%d x2:%d y0:%d y1:%d y2:%d\n", TESTNUM++, x1, x2, y0, y1, y2);//<test>
                        _calcF( x2, y0);
                    }
                }
                printf("%d y0\n" ,y0);
            }

            if (flag_x1_inc)    break;
        } 
    }
    out_C %= 998244353;
    out_F %= 998244353;
    printf("%ld %ld", out_C, out_F);
}

void calc(){
    scanf("%d %d %d %d", &n, &m, &c, &f);//<cancel>
    //n = 4;m =3; c =1; f= 1;//<test>

    if( n < 3 || m < 2) {
        printf("0 0");
        return;
    }

    _initField(n,m);

    _calcC();

    free(field);
}

int main(){
    int i;

    //T =1;//<test>
    //id =0;//<test>
    scanf("%d %d", &T, &id); //<cancel>

    for(int i =0; i<T; ++i)     calc();

    return 0;
}
