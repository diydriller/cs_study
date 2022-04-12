# Garbage Collection

## 1. 정의
* jvm에서 executor engine에 위치하며 heap영역에서 참조되지않는 객체를 제거하는 처리기이다.

### Heap 
* heap영역은 young generation영역과 old generation영역으로 나뉘며 
young generation은 eden영역 , survivor1영역 , survivor2영역으로 나뉜다.
* 처음 객체가 생성되면 eden영역에 생성되며 eden영역이 가득차면 minor gc가 발생하며
참조되지않는 객체를 제거하고 남은 객체들을 survivor1영역과 survivor2영역 중 비어있는 곳으로
번갈아가면서 이동한다.
* 객체의 age값이 특정 임계치를 넘게 되면 old generation영역으로 이동된다. old genertaion 영역이
가득차면 major gc가 발생해서 참조되지않는 객체를 제거한다.


## 2. gc 동작방식
* reference counting은 객체의 참조카운트를 기록하면서 참조값이 0이 되면 객체를 삭제하는
방법이다.
* mark and sweep은 gc root로부터 참조되는 객체를 추적해서 마킹하는 mark와 마킹되지않는
객체를 삭제하는 sweep으로 이루어지는 방법이다. gc root는 stack영역의 변수 ,
method영역의 static 변수가 될 수 있다.
### 순환참조
* reference counting에서 순환참조가 생길 경우 메모리 누수가 생길 수 있다.
이를 방지하기위해 참조수준을 강한참조와 약한참조로 나누고 약한참조일때는 참조값을 늘리지
않는다. 약한참조는 객체를 참조하지만 소유하지 않는다.

## 3. gc 종류
### Mark And Sweep
* gc가 발생하면 gc를 수행하는 스레드외의 모든 스레드가 멈추는 것을 stop the world라고
  하고 gc는 stop the world가 수행되는 시간을 줄이기 위해 발전되어왔다.
* serial gc는 gc를 처리하는 스레드가 1개이며 mark and sweep 이후 compact과정을 거친다.
* parallel gc는 gc를 처리하는 스레드가 여러개이다. compaction은 하지않는다.
* cms gc는 application 스레드와 gc 스레드가 동시에 실행되는 단계를 거친다. compaction은 하지 않는다.
  * initial mark 단계에서 stop the world가 발생해서 gc root가 참조하는 객체를 마킹한다.
  * concurrent mark 단계에서 살아있는 객체가 참조하는 객체들을 추적해서 마킹한다.
  * remark 단계에서 stop the world가 발생해서 이전 단계에서 확인한 객체들을 다시 추적하면서
  추가되거나 삭제된 객체를 확인하고 마킹을 확정한다.
  * cuncurrent sweep 단계에서 마킹되지않은 객체를 삭제한다.
  
## 인터뷰
### full gc 수행시 발생되는 문제점은?
* 대부분의 객체는 금방 사라지므로 gc의 대부분은 minor gc이다. 하지만 major gc가 발생할 경우 gc가 수행되는
시간이 느리므로 성능에 영향을 끼칠 수 있기때문에 major gc가 최대한 발생하지 않도록 해야한다.
* jvm옵션 중 heap영역의 young generation과 old generation의 비율을 조정하는 옵션이 있다. 
  * young genration영역이 너무 작은 경우 객체가 바로 old generation으로 넘어가게되고 major gc가 발생할
  가능성이 높아진다. 
  * young generation영역이 너무 큰 경우 minor gc과정에서 발생하는 survivor영역의 객체를 복사하는 비용이
  많아진다.

