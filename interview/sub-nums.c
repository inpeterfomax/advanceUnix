#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#define INPUTSIZE 100

int checkInputString(char const *instr, int len)
{
	if(instr == NULL)
		return 0;
	int i = 0;
	int sen = 0;
	for(; instr[i] != '\0'; i++){
		if(i == 0 && instr[i] == '-')
			continue;
		
		if(sen == 0){
			if(instr[i] >= '0' && instr[i] <= '9')
				continue;
			else if(instr[i] == ' '){
				sen = i + 1;
				continue;
			}else 
				break;
		}else{
			if(sen == i && instr[i] == '-')
				continue;
			if(instr[i] >= '0' && instr[i] <= '9')
				continue;
			else
				break;
		}
	}
	if(i == len)
		return 1;
	else
		return 0;
}

void recheck(int *a, int *alen, int *b, int *blen)
{
	int i = 0;
	int ai = 0;
	int bi = 0;
	int al = *alen;
	int bl = *blen;

	if(a[0] == 0){
		for(; ai < al; ai++){
			if(a[ai] != 0){
				break;
			}else{
				continue;
			}
		}
		
		if(ai == al){
			*alen = 1;
			a[0] = 0;
		}else{
			*alen -= ai;
			for(; ai < al; ai++){
				a[i] = a[ai];
				i++;
			}
		}
	}
	
	if(b[0] == 0){
		for(; bi < bl; bi++){
			if(b[bi] != 0){
				break;
			}else{
				continue;
			}
		}
		
		if(bi == bl){
			*blen = 1;
			b[0] = 0;
		}else{
			i = 0;
			*blen -= bi;
			for(; bi < bl; bi++){
				b[i] = b[ai];
				i++;
			}
		}
	}
}

void minus(int* a, int alen, int* b, int blen, char* result)
{
	int temp[INPUTSIZE];
	int i = alen - 1;
	int j = blen - 1;
	int t = 0;
	
	for(;j >= 0; j--, i--){
		if(a[i] >= b[j]){
			temp[t] = a[i] - b[j];
		}else{
			temp[t] = a[i] + 10 - b[j];
			a[i-1]--;
		}
		t++;
	}

	while(i > 0){
		if(a[i] < 0){
			temp[t] = a[i] + 10;
			a[i - 1]--;
		}
		else
			temp[t] = a[i];
		t++;
		i--;
	}
	
	if(i == 0){
		temp[t] = a[i];
		t++;
		i--;
	}
	
	
	while(t >= 0){
		if(temp[t-1] != 0)
			break;
		t--;
	}

	int r = 0;
	for(; t > 0 ; r++)
		result[r] = temp[--t] + '0';
	result[r] = '\0';
} 

void plus(int* a, int alen, int* b, int blen, char* result)
{
	int temp[INPUTSIZE];
	int i = alen - 1;
	int j = blen - 1;
	int t = 0;
	
	int highw = 0;

	for(;i >=0 || j >= 0; j--, i--){
		int rtem = a[i] + b[j] + highw;
		temp[t] = rtem % 10;
		highw = rtem % 10;
		t++;
		if(i==0 && j==0)
			temp[t+1] = rtem % 10;
	}
	
	

	while(i >= 0){
		int rtem = a[i] + highw;
		temp[t] = rtem % 10;
		highw = rtem / 10;
		t++;
		i--;
	}
	
	while(j >= 0){
		int rtem = b[j] + highw;
		temp[t] = rtem % 10;
		highw = rtem / 10;
		t++;
		j--;
	}
	// continous step in.
	if( highw != 0)
		temp[t++] highw;
	
	int r = 0;
	for(t--; t >=0 ; t--, r++)
		result[r] = temp[t] + '0';
	result[r] = '\0';
} 

int main()
{
	char inputStr[INPUTSIZE];
	char as[INPUTSIZE];
	char bs[INPUTSIZE];
	int a[INPUTSIZE];
	int b[INPUTSIZE];

	char result[INPUTSIZE];
	int flag;

	printf("Please enter input string:\n");
	gets(inputStr);

	int inputLen = strlen(inputStr);
	if(inputLen > 100){
		printf("The input string length > 100, error\n");
		return 1;
	}
	if(!checkInputString(inputStr, inputLen)){
		printf("The input string error!:\n");
		return 1;
	}
	
	
	int firstNum = 0;
	int firstLen = 0;
	int seconLen = 0;
	int i = 0;
	int j = 0;
	int asym = 1;
	int bsym = 1;
	// make into two int string.
	for(; i < inputLen; i++){
		if(!firstNum && inputStr[i] != ' '){
			if(inputStr[i] == '-'){
				asym = 0;
				continue;
			}
			a[j] = inputStr[i] - '0';
			j++;
			firstLen = j;
		}else if(!firstNum && inputStr[i] == ' '){
			firstNum = 1;
			j = 0;
		}else if(firstNum){
			if(inputStr[i] == '-'){
				bsym = 0;
				continue;
			}
			b[j] = inputStr[i] - '0';
			j++;
			seconLen = j;
		}
	}
	
	//recheck(a, &firstLen, b, &seconLen);
	
	for(i = 0; i < firstLen; i++){
		printf(" ai %d  \n", a[i]);
		as[i] = a[i] + '0';
	}
	as[i] = '\0';
	for(i = 0; i < seconLen; i++){
		printf(" bi %d  \n", b[i]);
		bs[i] = b[i] + '0';
	}
	bs[i] = '\0';
	printf(" ai %s  bs %s\n", as, bs);

	
	if((asym && bsym) || (!asym && !bsym)){
		if(firstLen == seconLen){
			int sc = strcmp(as, bs);
			if(sc == 0){
				result[0] = '0';
				printf("%s", result);
				return 0;
			}else if(sc > 0){
				if(asym)
					minus(a,firstLen, b, seconLen, result);
				else{
					result[0] = '-';
					minus(a,firstLen, b, seconLen, &result[1]);
				}
			}else if (sc < 0){
				if(asym){
					result[0] = '-';
					minus(b,seconLen, a,firstLen, &result[1]);
				}else
					minus(b,seconLen, a,firstLen, result);
			}
		}else{
			if(firstLen > seconLen){
				if(asym)
					minus(a,firstLen, b, seconLen, result);
				else{
					result[0] = '-';
					minus(a,firstLen, b, seconLen, &result[1]);
				}
			}else{
				if(asym){
					result[0] = '-';
					minus(b,seconLen, a,firstLen, &result[1]);
				}else
					minus(b,seconLen, a,firstLen, result);
			}
		}
	}else if((!asym && bsym) || (asym && !bsym)){
		if(asym)
			plus(a, firstLen, b, seconLen, result);
		else{
			result[0] = '-';
			plus(a, firstLen, b, seconLen, &result[1]);
		}
	}
	
	printf("result %s\n", result);
	return 0;
}
