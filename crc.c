#include "crc.h"

#define FOR_EACH_BIT(num,bitIter)  for(int bitIter=0;bitIter<sizeof(num)*8;bitIter++)


typedef unsigned char uint8_t;

uint8_t crc8(void *data,int size,uint8_t crc)
{
    uint8_t *crcDataIter=(uint8_t *)data;
    uint8_t crcData=*crcDataIter;
    uint8_t crcresult=crcDataIter[0];
    for(int i=1;i<size;i++)
    {   
        FOR_EACH_BIT(crcDataIter[i],bitIter)
        {
            if(crcresult&(0x01<<7)) crcresult^=crc;
            crcresult<<=1;
            crcresult|=(crcDataIter[i]&(0x01<<(7-bitIter)))>>(7-bitIter);
        }
    }

    for(int i=0;i<sizeof(crc)*8-1;i++)
    {
        if(crcresult&(0x01<<7)) crcresult^=crc;
        crcresult<<=1;
    }
    if(crcresult&(0x01<<7)) crcresult^=crc;
    return crcresult;
};
