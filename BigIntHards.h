#ifndef BIG_INT_H
#define BIG_INT_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>

class bigInt{

    struct bit{
        unsigned int i : 1;

        bit operator=(int op){
            if (op>2)
                i=1;
        }
    };

    struct byte{
        bit value[9];
    };

    byte *dec_bin ( int dec ){
        int nbits = nBits(dec);
        int nbytes = nBytes(dec);
        struct byte *bin = (struct  byte*) calloc( nBytes, sizeof(struct byte)); // binario 8-bits
        register int i,j;

        for ( i = 0; i < nbits; i++ )
            for (j = 0; j < nbytes; ++j)
            {
                bin[j].value = ( dec & ((((int)pow(2,nbits++))-1) >> i)) ? 1 : 0;
            }

            bin[nbits] = 0x0;
        return bin;
    }


    int nBytes(int dec){
        int n = nBits(dec);

        return (n/8)+1;
    }


    int nBits(int dec){
        int n = 0, pot;

        for (pot = 0; pow(2,pot)-1 < dec; pot++)
        {
            n = pot;
        }

        return n+1;
    }

public:
    bigInt(int decimal){
        printf("nbits : %d, vector:%s \n", nBytes(decimal), dec_bin(decimal));
    }
};

#endif
