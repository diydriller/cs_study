# Thread
## 1. Thread와 Runnable 
* Thread 클래스를 상속받는 방법과 Runnable 인터페이스를 구현하는 방법이 있다.
Runnable 인터페이스는 run 메서드 1개만 있는 함수형 인터페이스이고 
Thread 클래스는 Runnable 인터페이스를 구현한 클래스로 자바에서는
다중 상속을 지원하지않기때문에 확장성이 필요한 경우 Runnable 인터페이스를 구현하는 것이 낫다.
* start 메서드는 스레드를 실행대기상태로 변화시키고 스레드 스케줄러에 의해서 실행상태로 
변화될때 run 메서드를 사용해서 작업을 수행한다.

## 2. Thread Scheduling
* 스레드 스케줄러에 의해서 스케줄링 될때 우선순위나 시분할을 사용한다.

## 3. 상태

<table>
    <tr>
        <td>상태</td><td>상수</td><td>설명</td>
    </tr>
    <tr>
        <td>생성</td><td>NEW</td>
        <td>스레드 생성(start 메서드 호출x)</td>
    </tr>
    <tr>
        <td>실행대기</td><td>RUNNABLE</td>
        <td>실행상태로 가기위해 대기중(run 메서드 호출x)</td>
    </tr>
    <tr>
        <td rowspan="3">일시정지</td><td>WAITING</td>
        <td>다른 스레드가 notify할때까지 정지</td>
    </tr>
    <tr>
        <td>TIMED_WAITING</td>
        <td>일정 시간동안 정지</td>
    </tr>
    <tr>
        <td>BLOCKED</td>
        <td>자원객체의 lock이 풀릴때까지 정지</td>
    </tr>
    <tr>
        <td>종료</td><td>TERMINATED</td>
        <td>실행을 마치고 종료</td>
    </tr>
</table>
