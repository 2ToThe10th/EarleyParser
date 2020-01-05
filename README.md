
# EarleyParser

[![Build Status](https://travis-ci.com/2ToThe10th/EarleyParser.svg?token=3S6xWbBvu4EyXfDwhGsF&branch=master)](https://travis-ci.com/2ToThe10th/EarleyParser)

### Алгоритм:

В данном проекте был использован алгоритм Эрли.
Алгоритм реализован с помощью класса ```EarleyParser``` 
(название функций класса(scan, complete, predict) совпадает с их названиями на лекции) и
двух вспомогательных классов: ```Position``` и ```Rule```

### Запуск:

Для того чтобы запустить тесты,
воспользуйтесь командами:

```cmake -DDEBUG=1```

```make```

```./second-practical-work```

Для запуска программы воспользуйтесь командами:

```cmake```

```make```

```./second-practical-work```

Для проверки программы на собственной кс-грамматике в main.cpp 
поменяйте вектор rules
