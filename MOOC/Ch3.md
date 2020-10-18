# 第三章 栈与队列测验

> 设栈S 和队列Q 的初始状态为空，元素e1，e2，e3，e4，e5和e6依次通过栈S，一个元素出栈后即进队列Q，若6 个元素出队的序列是e2，e4，e3，e6，e5，e1则栈S的容量至少应该是_____________。
>
> Assume that the stack S and queue Q’s initial state is empty, the elements e1, e2, e3, e4, e5 and e6 followed through stack S, an element out the stack means into the queue Q. If the sequence the six elements out of the queue is e2, e4, e3, e6, e5, e1 then stack S of capacity should be at least _____________. （There is only one correct answer）

`B:3`

> 现有中缀表达式E=((100-4)/3+3*(36-7))*2。以下哪个是与E等价的后缀表达式？
>
> Existing infix expression E = ((100-4) / 3 + 3 * (36-7)) * 2. Which of the following is the equivalent postfix expression of E? （There is only one correct answer）

```
C:100 4 – 3 / 3 36 7 – * + 2 *
```

> 队列的特点包括：
>
> Queue’ features include:（There are more than one answers.）

```
A:后进后出 Last-in last-out (LILO)

D:先进先出First-in first-out (FIFO)
```

> 以下循环队列的实现方式中，长度为n的队列，所能容纳的元素个数也为n的有:
>
> In the following realizing ways of circular queue, the queue whose length is n can also contain the number of n elements is:（There are more than one answers.）

```
A:用front和rear两个指针标记队列的头和尾，并用整型变量len记录队列元素数With the queue’s head and tail pointers marked as front and rear, use the integer variable len to record the number of elements.

C:用front和rear两个指针标记队列的头和尾，并用布尔型变量empty记录队列是否为空With the queue’s head and tail pointers marked as front and rear, use Boolean variable empty record whether the queue is empty.
```

> 编号为1，2，3，4的四辆列车，顺序开进一个栈式结构的站台；则开出车站的顺序有______种可能。 注释：例如 1, 2, 3, 4 或 4, 3, 2，1 就是其中两种可能出站序列；而 4, 3, 1, 2 是 非法序列。
>
> Numbered 1,2,3,4 four trains, orderly entered a stack structure station. How many possible leaving sequences of that four trains ? ______ . Note: For instance, the leaving sequence could be 1,2,3,4 or 4,3,2,1 these two possibilities, but 4, 3, 1, 2 is not a possible sequence.

`14`

> 双端队列可以在队列的两端进行插入和删除操作，既可在队尾进行插入/删除，又可在队头进行插入/删除。现有4个不同的元素顺序输入到双端队列，那么可以得到_____种不同的排列。
>
> double-ended queue can insert and delete operations on both ends of the queue. That it can insert / delete at its tail, but also at the head. Existing 4 different elements sequentially input to the double-ended queue, you can get _____ different permutations.

`8`