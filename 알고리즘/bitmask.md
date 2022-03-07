## Bitmask
### 비트연산
* 음수를 bitshift할 경우 unsigned 자료형 사용해야한다
### 집합표현
```c++
    set=set|(1<<p) // p번 비트를 1로 바꿔준다. (원소추가)
    set=set&~(1<<p) // p번 비트를 0으로 바꿔준다. (원소삭제)
    set=set^(1<<p) // p번 비트를 토클해준다.
    
    set1|set2 // 합집합
    set1&set2 // 교집합
    set1&(~set2) // 차집합
    set1^set2 // 교집합을 제외한 부분
    
    // 집합의 크기
    int bitSize(int x){
        if(x==0) return 0;
        return x%2+bitSize(x/2);
    }
    
    // 집합 순회
    for(int subset=set;subset>0;subset=(subset-1)&set){
    }
    
    set&(-set) // 최소원소
    set=set&(set-1) // 최소원소 지우기
 
```
* [boj_11723_집합](./bitmask/boj_11723.cpp)
* [boj_11578_팀원모집](./bitmask/boj_11578.cpp)




