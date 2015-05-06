#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "afxtempl.h"

using namespace std;

int main(){
    int CB_len=13;

	BYTE ucSendBuf[100];
	CByteArray data;
	//CByteArray ucSendBuf16;

	data[CB_len] = {0xEE, 0xB1,0x10, 0x00,0x01,0x00,0x00, 0x00,0x00, 0xFF,0xFC,0xFF,0xFF};

    return 0;
}
