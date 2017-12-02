#include <stdio.h>

typedef struct _empInfo
{
    int empNum;    // 직원의 고유번호
    int age;     // 직원의 나이
}EmpInfo;

// 여덟 자리의 수로 이뤄진 직원의 고유번호를 두 자리의 수로 변경한다
int GetHashValue(int empNum)
{
    return empNum % 100;
}

// 20120003 , 20210103 과같은경우는 키가 03 으로 충돌이 발생하게되는데
// 이러한 충돌은 배열의 길이를 늘리는 방법으로 피애야 할 상황이 아님
int main(void)
{
    EmpInfo empInfoArr[100];
    
    EmpInfo emp1={20120003, 42};
    EmpInfo emp2={20130012, 33};
    EmpInfo emp3={20170049, 27};
    
    EmpInfo r1, r2, r3;
    
    // 키를 인덱스 값으로 이용해서 저장
    empInfoArr[GetHashValue(emp1.empNum)] = emp1;
    empInfoArr[GetHashValue(emp2.empNum)] = emp2;
    empInfoArr[GetHashValue(emp3.empNum)] = emp3;
    
    // 키를 인덱스 값으로 이용해서 탐색
    r1 = empInfoArr[GetHashValue(20120003)];
    r2 = empInfoArr[GetHashValue(20130012)];
    r3 = empInfoArr[GetHashValue(20170049)];
    
    // 탐색 결과 확인
    printf("사번 %d, 나이 %d \n", r1.empNum, r1.age);
    printf("사번 %d, 나이 %d \n", r2.empNum, r2.age);
    printf("사번 %d, 나이 %d \n", r3.empNum, r3.age);
    return 0;
}
