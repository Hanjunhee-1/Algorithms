# Birthday Problem

- 방 안에 여러 사람들이 있을 때 나랑 생일이 같은 사람이 존재할 확률이 50% 이상이 되려면 몇 명의 사람이 있어야 할까?

- 우선 두 사람의 생일이 같은 경우를 구해보면 됩니다.

    1. 1년은 365일 입니다. (윤년 제외)
    2. 두 사람의 생일이 같을 확률은 1/365 = 0.27% 입니다. <br/><br/><br/>


- 이번에는 서로의 생일이 다를 경우를 구해봅니다.

    1. 마찬가지로 1년은 365일 입니다. (윤년 제외)
    2. 한 사람만 있을 경우에는 365/365 = 1 로 애초에 한 명밖에 없기 때문에 서로의 생일이 다를 확률은 100% 입니다.
    3. 두 사람이 있을 경우에는 365/365 * 364/365 = 99.72% 입니다.
    4. 세 사람이 있을 경우에는 365/365 * 364/365 * 363/365 = 99.17% 입니다.
    5. 계속해서 위와 같이 구해줍니다. <br/><br/><br/>

- 이제 서로의 생일이 다를 경우에 대한 식을 기준으로 서로의 생일이 같은 경우에 대한 식을 도출합니다.

    1. `(서로의 생일이 같은 경우) = 1 - (서로의 생일이 다른 경우)` <br/><br/><br/>

- 답을 구해보면 방 안에 여러 사람들이 있을 때 나랑 생일이 같은 사람이 존재할 확률이 50% 이상이 되려면 나를 포함한 23명 이상의 사람이 같은 방에 있어야 합니다. 

- 생각보다 적은 사람으로도 생일이 같을 확률이 50% 가 넘어가는 것을 보고 이 문제를 생일 문제 Paradox 라고도 합니다. 