## History로 보는 운영체제 - 1960년대 후반

---
## 1960년대 후반
* 새로운 개념이 제안되었다.
    + 시분할 시스템 (Time Sharing System)
    + 멀티 태스킹 (Multi Tasking)
> 제안은 되었으나 실제 운영체제로 구현되지는 않았다.

___
## 시분할 시스템과 멀티 테스킹
* 응용 프로그램이 CPU를 사용하는 시간을 잘개 쪼개서, 여러개의 응용 프로그램을 동시에 실행하는 기법이다.
* Application 1이 12시간, Application 2가 30분, Application 3이 1시간 걸린다고 가정하였을때 아래 표에서 15분씩 시간을 쪼개서 Application 1 (15 min) -> Application 2 (15 min) -> Application 3 (15 min) -> Application 1 (15 min) ... 실행하는 기법이다.

|Application 1  -->|Application 2  -->|Application 3|
|---|---|---|

* 시분할 시스템 : 다중 사용자를 지원하고, 컴퓨터 응답 시간(Application을 시작하는데 걸리는 시간)을 최소화 한다.
* 멀티 태스킹 : 가능한 CPU를 많이 활용하도록 하는 기능이다. (시간 대비 CPU 사용률을 높인다.)