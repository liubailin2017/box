/*
 * fini.c
 *
 *  Created on: 2019年5月25日
 *      Author: lj
 */
#include <stdlib.h>
#include <string.h>
#include "fini.h"

FIni *FINI_Create(const char *filename)
{
	FIni *self = (FIni *)malloc(sizeof(FIni));
	char line[MAXLEN]={0};
	int i=0;

	memset(self, 0, sizeof(FIni));
	self->Count = 0;

	// 加载文件
	FILE *fp = fopen(filename, "r");
	if (fp)
	{
		while( fgets(line, MAXLEN, fp))
		{
			//puts(line);

			// 去掉特殊字符
			for(i=0; i<MAXLEN; i++)
			{
				if (line[i] == '\r' || line[i] == '\n')
					line[i] = '\0';
			}

			// 判断是否包含 =
			char *pe = strchr(line, '=');
			if (pe)
			{
				// =左边的数据
				int len = pe -line;
				memcpy(self->PairArray[self->Count].Key, line, len);

				//=右边的数据，
				len = strlen(line) - (pe -line) -1;
				memcpy(self->PairArray[self->Count].Value, pe+1, len);

				self->Count++;
			}
		}

		fclose(fp);
	}
	else
		return NULL;

	return self;
}


void FINI_Destroy(FIni *self)
{
	if (self)
	{
		free(self);
		self = NULL;
	}
}

char *FINI_GetStr(FIni *self, const char *key)
{
	if (!self)
		return NULL;

	int i=0;
	for(i=0; i<self->Count; i++)
	{
		if (0 == strcmp(key, self->PairArray[i].Key))
		{
			return self->PairArray[i].Value;
		}
	}

	return NULL;
}

int  FINI_GetInt(FIni *self, const char *key)
{
	if (!self)
		return NULL;

	int i=0;
	for(i=0; i<self->Count; i++)
	{
		if (0 == strcmp(key, self->PairArray[i].Key))
		{
			return atoi(self->PairArray[i].Value);
		}
	}

	return 0;
}

