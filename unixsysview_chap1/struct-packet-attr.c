#include<stdio.h>
#include<stdlib.h>
//#include<sd>

#define __u8    unsigned char
#define __u16   unsigned short
/* __attribute__ ((packed)) ��λ��Լ���Ƿ���������β��������֮ǰ */
struct str_struct{
        __u8    a;
        __u16   d;
        __u8    b;
        __u8    c;
        //__u16   d;
} __attribute__ ((packed));
/*  ���õ�typedefʱ��Ҫ�ر�ע��__attribute__ ((packed))���õ�λ�ã��൱�ڣ�
  *  typedef struct str_stuct str;
  *  ��struct str_struct ����������Ǹ��ṹ��
  */
typedef struct {
        __u8    a;
        __u16   d;
        __u8    b;
        __u8    c;
//        __u16   d;
} __attribute__ ((packed)) str;
/* ���������typedef�ṹ�У�__attribute__ ((packed))���ڽṹ��str_temp֮���������Ǳ����Եģ�ע����ṹstr������*/
typedef struct {
        __u8    a;
        __u16   d;
        __u8    b;
        __u8    c;
//        __u16   d;
}str_temp __attribute__ ((packed));
typedef struct {
        __u8    a;
        __u16   d;
        __u8    b;
        __u8    c;
//        __u16   d;
}str_nopacked;
int main(void)
{
        printf("sizeof str = %d\n", sizeof(str));
        printf("sizeof str_struct = %d\n", sizeof(struct str_struct));
        printf("sizeof str_temp = %d\n", sizeof(str_temp));
        printf("sizeof str_nopacked = %d\n", sizeof(str_nopacked));
        return 0;
}
