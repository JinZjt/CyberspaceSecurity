#include<stdio.h>
int PublicKey(int p, int q){
    return p*q; //the public key
}

int DetermineField(int p, int q){
    return (p-1)*(q-1);
}

int PrivateKey(int e, int f){
    int k=0;
    while(1){
      if((k*f+1)/e>=f) break;
      else{
          if((k*f+1)%e==0) return (k*f+1)/e;
          k++;
      }
    }
    return -1; //if privatekey is -1, it means that this codeblock doesn't work
}

int encryption(int m, int e, int n){
    int i=e,sum=1;
    for(i=e;i>0;i--){
        sum = (sum*m)%n;
    }
    return sum%n;
}

int decryption(int cipher, int n, int d){
    int i=d,sum=1;
    for(i=d;i>0;i--){
        sum = (sum*cipher)%n;//积的取余等于取余的积的取余
    }
    return sum%n;
}

int main(){
    int p=23,q=11,e=7,n=0,f=0,d=0,result = 0, cipher = 0, m=27;
    n = PublicKey(p,q);
    f = DetermineField(p,q);
    d = PrivateKey(e,f);
    cipher = encryption(m,e,n);
    result = decryption(cipher, n, d);
    printf("n=%d f=%d d=%d cipher = %d, result = %d\n", n,f,d,cipher,result);
    return 0;
}



