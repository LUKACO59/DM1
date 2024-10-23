#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

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

int main(){
    return 0;
}