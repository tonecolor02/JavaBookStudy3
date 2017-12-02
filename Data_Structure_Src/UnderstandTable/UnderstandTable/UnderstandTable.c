#include <stdio.h>

typedef struct _empInfo
{
    int empNum;    // 직원의 고유번호
    int age;     // 직원의 나이
}EmpInfo;

// 직원 고유번호의 범위가 배열의 인덱스 값으로 사용하기에 적당하지 않다
// 직원 고유번호의 범위를 수용할 수 있는 매우 큰 배열이 필요하다
int main(void)
{
    EmpInfo empInfoArr[1000];
    EmpInfo ei;
    int eNum;
    
    printf("사번과 나이 입력: ");
    scanf("%d %d", &(ei.empNum), &(ei.age));
    empInfoArr[ei.empNum] = ei;    // 단번에 저장!
    
    printf("확인하고픈 직원의 사번 입력: ");
    scanf("%d", &eNum);
    
    ei = empInfoArr[eNum];    // 단번에 탐색!
    printf("사번 %d, 나이 %d \n", ei.empNum, ei.age);
    return 0;
}
