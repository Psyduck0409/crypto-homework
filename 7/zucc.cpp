/*************************************************************************
 > File Name: zuc.cpp
 > Author: Guaji
 > Mail: rdwentao@163.com 
 > Created Time: Wed 29 Apr 2020 08:33:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int D[] = {17623,9916,25195,4958,22409,13794,28981,2479,19832,12051,27588,6897,24102,15437,30874,18348};
const unsigned int S1[][16] = {{0x3E, 0x72, 0x5B, 0x47, 0xCA, 0xE0, 0x00, 0x33, 0x04, 0xD1, 0x54, 0x98, 0x09, 0xB9, 0x6D, 0xCB},
                        {0x7B, 0x1B, 0xF9, 0x32, 0xAF, 0x9D, 0x6A, 0xA5, 0xB8, 0x2D, 0xFC, 0x1D, 0x08, 0x53, 0x03, 0x90},
                        {0x4D, 0x4E, 0x84, 0x99, 0xE4, 0xCE, 0xD9, 0x91, 0xDD, 0xB6, 0x85, 0x48, 0x8B, 0x29, 0x6E, 0xAC},
                        {0xCD, 0xC1, 0xF8, 0x1E, 0x73, 0x43, 0x69, 0xC6, 0xB5, 0xBD, 0xFD, 0x39, 0x63, 0x20, 0xD4, 0x38},
                        {0x76, 0x7D, 0xB2, 0xA7, 0xCF, 0xED, 0x57, 0xC5, 0xF3, 0x2C, 0xBB, 0x14, 0x21, 0x06, 0x55, 0x9B},
                        {0xE3, 0xEF, 0x5E, 0x31, 0x4F, 0x7F, 0x5A, 0xA4, 0x0D, 0x82, 0x51, 0x49, 0x5F, 0xBA, 0x58, 0x1C},
                        {0x4A, 0x16, 0xD5, 0x17, 0xA8, 0x92, 0x24, 0x1F, 0x8C, 0xFF, 0xD8, 0xAE, 0x2E, 0x01, 0xD3, 0xAD},
                        {0x3B, 0x4B, 0xDA, 0x46, 0xEB, 0xC9, 0xDE, 0x9A, 0x8F, 0x87, 0xD7, 0x3A, 0x80, 0x6F, 0x2F, 0xC8},
                        {0xB1, 0xB4, 0x37, 0xF7, 0x0A, 0x22, 0x13, 0x28, 0x7C, 0xCC, 0x3C, 0x89, 0xC7, 0xC3, 0x96, 0x56},
                        {0x07, 0xBF, 0x7E, 0xF0, 0x0B, 0x2B, 0x97, 0x52, 0x35, 0x41, 0x79, 0x61, 0xA6, 0x4C, 0x10, 0xFE},
                        {0xBC, 0x26, 0x95, 0x88, 0x8A, 0xB0, 0xA3, 0xFB, 0xC0, 0x18, 0x94, 0xF2, 0xE1, 0xE5, 0xE9, 0x5D},
                        {0xD0, 0xDC, 0x11, 0x66, 0x64, 0x5C, 0xEC, 0x59, 0x42, 0x75, 0x12, 0xF5, 0x74, 0x9C, 0xAA, 0x23},
                        {0x0E, 0x86, 0xAB, 0xBE, 0x2A, 0x02, 0xE7, 0x67, 0xE6, 0x44, 0xA2, 0x6C, 0xC2, 0x93, 0x9F, 0xF1},
                        {0xF6, 0xFA, 0x36, 0xD2, 0x50, 0x68, 0x9E, 0x62, 0x71, 0x15, 0x3D, 0xD6, 0x40, 0xC4, 0xE2, 0x0F},
                        {0x8E, 0x83, 0x77, 0x6B, 0x25, 0x05, 0x3F, 0x0C, 0x30, 0xEA, 0x70, 0xB7, 0xA1, 0xE8, 0xA9, 0x65},
                        {0x8D, 0x27, 0x1A, 0xDB, 0x81, 0xB3, 0xA0, 0xF4, 0x45, 0x7A, 0x19, 0xDF, 0xEE, 0x78, 0x34, 0x60}};


const unsigned int S2[][16] = {{0x55, 0xC2, 0x63, 0x71, 0x3B, 0xC8, 0x47, 0x86, 0x9F, 0x3C, 0xDA, 0x5B, 0x29, 0xAA, 0xFD, 0x77},
                        {0x8C, 0xC5, 0x94, 0x0C, 0xA6, 0x1A, 0x13, 0x00, 0xE3, 0xA8, 0x16, 0x72, 0x40, 0xF9, 0xF8, 0x42},
                        {0x44, 0x26, 0x68, 0x96, 0x81, 0xD9, 0x45, 0x3E, 0x10, 0x76, 0xC6, 0xA7, 0x8B, 0x39, 0x43, 0xE1},
                        {0x3A, 0xB5, 0x56, 0x2A, 0xC0, 0x6D, 0xB3, 0x05, 0x22, 0x66, 0xBF, 0xDC, 0x0B, 0xFA, 0x62, 0x48},
                        {0xDD, 0x20, 0x11, 0x06, 0x36, 0xC9, 0xC1, 0xCF, 0xF6, 0x27, 0x52, 0xBB, 0x69, 0xF5, 0xD4, 0x87},
                        {0x7F, 0x84, 0x4C, 0xD2, 0x9C, 0x57, 0xA4, 0xBC, 0x4F, 0x9A, 0xDF, 0xFE, 0xD6, 0x8D, 0x7A, 0xEB},
                        {0x2B, 0x53, 0xD8, 0x5C, 0xA1, 0x14, 0x17, 0xFB, 0x23, 0xD5, 0x7D, 0x30, 0x67, 0x73, 0x08, 0x09},
                        {0xEE, 0xB7, 0x70, 0x3F, 0x61, 0xB2, 0x19, 0x8E, 0x4E, 0xE5, 0x4B, 0x93, 0x8F, 0x5D, 0xDB, 0xA9},
                        {0xAD, 0xF1, 0xAE, 0x2E, 0xCB, 0x0D, 0xFC, 0xF4, 0x2D, 0x46, 0x6E, 0x1D, 0x97, 0xE8, 0xD1, 0xE9},
                        {0x4D, 0x37, 0xA5, 0x75, 0x5E, 0x83, 0x9E, 0xAB, 0x82, 0x9D, 0xB9, 0x1C, 0xE0, 0xCD, 0x49, 0x89},
                        {0x01, 0xB6, 0xBD, 0x58, 0x24, 0xA2, 0x5F, 0x38, 0x78, 0x99, 0x15, 0x90, 0x50, 0xB8, 0x95, 0xE4},
                        {0xD0, 0x91, 0xC7, 0xCE, 0xED, 0x0F, 0xB4, 0x6F, 0xA0, 0xCC, 0xF0, 0x02, 0x4A, 0x79, 0xC3, 0xDE},
                        {0xA3, 0xEF, 0xEA, 0x51, 0xE6, 0x6B, 0x18, 0xEC, 0x1B, 0x2C, 0x80, 0xF7, 0x74, 0xE7, 0xFF, 0x21},
                        {0x5A, 0x6A, 0x54, 0x1E, 0x41, 0x31, 0x92, 0x35, 0xC4, 0x33, 0x07, 0x0A, 0xBA, 0x7E, 0x0E, 0x34},
                        {0x88, 0xB1, 0x98, 0x7C, 0xF3, 0x3D, 0x60, 0x6C, 0x7B, 0xCA, 0xD3, 0x1F, 0x32, 0x65, 0x04, 0x28},
                        {0x64, 0xBE, 0x85, 0x9B, 0x2F, 0x59, 0x8A, 0xD7, 0xB0, 0x25, 0xAC, 0xAF, 0x12, 0x03, 0xE2, 0xF2}};

void pr_LFSR(unsigned int *LFSR){
    for(int i=0;i<16;i++){
        printf("%d ",LFSR[i]);
    }
    printf("\n");
}

unsigned int *k_load(unsigned char *k, unsigned char *iv){
    unsigned int *s;
    s = (unsigned int*)malloc(sizeof(unsigned int)*16);
    memset(s,0,sizeof(unsigned int)*16);
    for(int i=0;i<16;++i){
        s[i] = iv[i] + (D[i]<<8) + (k[i]<<23);
    }
    return s;
}

unsigned int loop_left(const unsigned int x,int t){
    unsigned int res=(x<<t)+((x-((x<<t)>>t))>>(32-t));
    return res;
}

unsigned int *Bitrec(const unsigned int *LFSR){
    static unsigned int *x= (unsigned int*)malloc(sizeof(unsigned int)*4);
    x[0] = ((LFSR[15]>>15)<<16)+(LFSR[14]&0xFFFF);
    x[1] = (LFSR[9]>>15)+((LFSR[11]&0xFFFF)<<16);
    x[2] = (LFSR[5]>>15)+((LFSR[7]&0xFFFF)<<16);
    x[3] = (LFSR[0]>>15)+((LFSR[2]&0xFFFF)<<16);
    return x;
}

unsigned int S(unsigned int a){
    unsigned int res;
    res = (S1[(a&0xF0000000)>>28][(a&0x0F000000)>>24]<<24)+(S2[(a&0x00F00000)>>20][(a&0x000F0000)>>16]<<16)\
        +(S1[(a&0x0000F000)>>12][(a&0x00000F00)>>8]<<8)+S2[(a&0x000000F0)>>4][(a&0x0000000F)];
    return res;
}

unsigned int F(unsigned int *x,unsigned int *R1,unsigned int *R2){
    unsigned int w = (x[0]^*R1)+*R2;
    unsigned int w1 = *R1+x[1]; 
    unsigned int w2 = *R2^x[2];
    unsigned int t1 = ((w1&0xFFFF)<<16) + (w2>>16);
    unsigned int t2 = ((w2&0xFFFF)<<16) + (w1>>16);
    // printf("w1 = %x, w2 = %x, t1_ = %x, t2_ = %x\n",w1,w2,t1,t2);
    t1 = t1^(loop_left(t1, 2))^(loop_left(t1, 10))^(loop_left(t1, 18))^(loop_left(t1, 24));
    t2 = t2^(loop_left(t2, 8))^(loop_left(t2, 14))^(loop_left(t2, 22))^(loop_left(t2, 30));
    // printf("t1 = %x, t2=%x\n",t1,t2);
    *R1 = S(t1);
    *R2 = S(t2);
    return w;
}

void *LFSRMode(unsigned int u, unsigned int *LFSR,unsigned int k){  // k=1:init ,k=0:work
    const unsigned long long mod = 0x7fffffff;
    unsigned long long s16 = ((((1<<15)*(unsigned long long)LFSR[15]%mod + (1<<17)*(unsigned long long)LFSR[13]%mod)%mod \
        + (1<<21)*(unsigned long long)LFSR[10]%mod)%mod + (1<<20)*(unsigned long long)LFSR[4]%mod)%mod +  (1+(1<<8))*(unsigned long long)LFSR[0]%mod;
    // unsigned long long s16 = ((((1<<15)*LFSR[15]%mod + (1<<17)*LFSR[13]%mod)%mod \
        // + (1<<21)*LFSR[10]%mod)%mod + (1<<20)*LFSR[4]%mod)%mod +  (1+(1<<8))*LFSR[0]%mod;
    s16 = s16%mod;
    if (k == 1){
        s16 = ((unsigned long long)u+s16) % mod;
    }
    else
        s16 = s16 % mod;
    if (s16 == 0)
        s16 = mod;
    for(int i=0;i<15;++i){
        LFSR[i] = LFSR[i+1];
    }
    LFSR[15] = (unsigned int)s16;
}

unsigned int *init(unsigned char *k, unsigned char *iv,unsigned *R1, unsigned *R2){
    unsigned int *LFSR = k_load(k, iv);
    *R1=0;*R2=0;
    unsigned int w,*x;
    for(int i=0;i<32;i++){
        x = Bitrec(LFSR);
        // printf("x: %u %u %u %u\n",x[0],x[1],x[2],x[3]);
        w = F(x, R1, R2);
        // printf("w = %x, R1 = %x, R2 = %x, i = %d\n",w,*R1,*R2,i);
        LFSRMode(w>>1, LFSR, 1);
        // pr_LFSR(LFSR);
    }
    return LFSR;
}

unsigned int work(unsigned int *LFSR, unsigned *R1, unsigned int *R2){
    unsigned int *x = Bitrec(LFSR);
    unsigned int w = F(x, R1, R2);
    unsigned int z = w^x[3];
    LFSRMode(w>>1, LFSR, 0);
    return z;
}

int main(){
    unsigned int *LFSR, R1 ,R2;
    //0x15be 0x80
    unsigned char k[16],iv[16];
    for(int i=0;i<16;++i){
        k[i]=0xff;
        iv[i]=0xff;
    }
    //k[14] = 0x15;
    //k[15] = 0xbe;
    //iv[14] = 0;
    //iv[15] = 0x80;
    LFSR = init(k,iv,&R1,&R2);
    printf("%x\n",work(LFSR,&R1,&R2));
    printf("%x\n",work(LFSR,&R1,&R2));
    return 0;
}
