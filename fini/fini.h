/*
 * fini.h
 *
 *  Created on: 2019年5月25日
 *      Author: lj
 */

#ifndef FINI_H_
#define FINI_H_

#include <stdio.h>

// ini文件中的数据长度
#define MAXLEN			(256)

typedef struct FPair_
{
	char 	Key[MAXLEN];
	char 	Value[MAXLEN];
}FPair;


typedef struct FIni_
{
	//FILE 	*fp;

	// 总的key-value的个数
	int 	Count;

	// 总的Key-Value数据
	FPair	PairArray[MAXLEN];

}FIni;
#ifdef __cplusplus
extern "C"{  
#endif
 
 
FIni *FINI_Create(const char *filename);
void FINI_Destroy(FIni *self);

int  FINI_GetInt(FIni *self, const char *key);
char *FINI_GetStr(FIni *self, const char *key);
 
#ifdef __cplusplus
}
#endif

#endif /* FINI_H_ */

