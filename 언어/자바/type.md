# Type

## 1. Type
* primitive type은 실제 데이터를 저장하는 타입이다.
  * stack영역에 저장된다.
  * 종류로는 논리형 , 실수형 , 정수형 , 문자형이 있다. 
  * null을 저장하기위해서는 wrapper 클래스를 사용한다.
* reference type은 객체의 주소를 저장하는 타입이다.
  * 객체생성시 객체는 heap영역에 저장되고 객체의 참조타입변수는 stack영역에 저장된다. 
  * null을 저장할 수 있다.

  
## 2. Generic
### 정의
* 데이터타입을 일반화하는 것으로 컴파일시점에 타입검사를 하고 런타임시 타입을 제거한다. 
### 특징
* 타입제거시 unbound type은 object로 변환되고 bound type은 첫번째 bound type으로
  변환된다.
* 타입을 명시할때 primitive type 사용시 wrapper 클래스를 사용해야한다.

## 3. Mutable vs Immutable
### 정의
* immutable은 변경이 불가능한 것으로 변경사항이 있을 경우 새 객체가 생성된다.
### 특징
* 종류로 String , Boolean , Integer , Long , Float ,Double이 있다.
* thread safe하다.
* 변경될때마다 객체가 생성되므로 메모리 오버헤드가 발생한다.


## 인터뷰 
### String의 +와 concat의 차이는?
* jdk 1.5 이전에는 + 연산자는 concat연산자와 마찬가지로 String 객체를 생성하고
이어붙이는 방식을 취했다.
* jdk 1.5 이후부터 java 8까지 +연산자는 StringBuilder의 append 메서드를 override함으로써 
최적화가 되었다. 이때 여러줄에 걸쳐서 +연산을
하게되면 이 이점을 살리지 못하므로 StringBuilder를 사용하는 것이 더 좋다.
### 부동소수점 오차란?
* 부동소수점은 실수를 가수부와 지수부를 표현한것으로 2지수 체계로 나타내다보니
10진수의 수를 정확하게 나타낼 수 없다. java.math 패키지의 BigDecimal 클래스를 
사용해서 해결한다.
### Integer와 int의 차이는?
* Integer는 reference type이고 int는 primitive type이다. 
* Integer는 int의 wrapper class로 null을 저장할 수 있고 산술연산시 자동으로 unboxing 되어서
int로 변환된다. 
* Integer의 valueOf 메서드는 Integer를 반환하고 parseInt 메서드는 int를 반환한다.