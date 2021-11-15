### TCP(Transmission Control Protocol)란?
* 서버와 클라이언트간 신뢰성있는 데이터를 전달하기 위해 만들어진 프로토콜이다.

### 3 way handshake
* 3 way handshake를 통해 연결을 한다.
1) 클라이언트가 서버에게 SYN(x)를 보낸다.
2) 서버는 SYN(x)를 받고 클라이언트에게 잘 받았다는 ACK(x+1)과 SYN(y)를 보낸다.
3) 클라이언트는 ACK(x+1)과 SYN(y)를 받고 잘 받았다는 ACK(y+1)를 보낸다.

### 4 way handshake
* 4 way handshake를 통해 연결해제를 한다.
1) 클라이언트가 연결을 종료하겠다는 FIN을 보낸다.
2) 서버는 FIN을 받고 클라이언트에게 잘 받았다는 ACK를 보내고 통신을 끝내기위해서 
CLOSE_WAIT 상태가 된다.
3) 서버의 통신이 끝나면 클라이언트에게 FIN을 보낸다.
4) 클라이언트는 FIN을 받고 서버에게 잘 받았다는 ACK를 보낸다.
서버가 FIN을 보내기 전에 보낸 데이터가 FIN 이후에 올 경우를 대비하여 일정시간
TIME_WAIT 상태가 된다.

