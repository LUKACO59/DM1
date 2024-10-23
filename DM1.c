#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
int fexp(int a, int b){
    int res=1;
    while(b>0){
        if(b%2==1){
            res=res*a;
        }
        a=a*a;
        b=b/2;
    }
    return res;
}
int mod_exp(int a, int b ,int n){
    int res = 1;
    int amn =a%n;
    while(b>0){
        if(b%2==1){
            res=(res*amn)%n;
        }
        amn=(amn*amn)%n;
        b=b/2;
    }
    return res;
}

bool fermat_witness(int n,int a){
    return mod_exp(a,(n-1),n)==1;
}
bool fermat_primality_test(int n,int k){
    int i=0;
    while(i<k){
        int a=(rand()%(n-2))+2;
        if(!fermat_witness(n,a)) return false;
        i++;
    }
    return true;
}
void decompose(int n,int *s,int *d){
    *s=0;
    *d=n;
    while(*d%2==0){
        *s=*s+1;
        *d=*d/2;
    }
}

/*a corriger*/
bool miller_witness(int n,int a){
    int *s=malloc(sizeof(int));
    int *d=malloc(sizeof(int));
    decompose((n-1),s,d);
    if(mod_exp(a,(*d),n)==1){
        free(s);
        free(d);
        return true;
    }
    int expo=(*d);
    if(mod_exp(a,expo,n)==(n-1)){
        free(s);
        free(d);
        return true;
    }
    for(int i=1;i<(*s);i++){
        expo=expo*2;
        if(mod_exp(a,expo,n)==(n-1)){
            free(s);
            free(d);    
            return true;
        }
    }
    free(s);
    free(d);    
    return false;
}
int main(){
    int *s=malloc(sizeof(int));
    int *d=malloc(sizeof(int));
    int n=13;
    decompose((n-1),s,d);
    int res=fexp(2,*s)* (*d);
    printf("%d\n",res);
    printf("%d\n",(-1)%2);
    printf("%d\n",miller_witness(7,3));
    return 0;
}