# 第一章 概论 测验

> 下列不属于线性结构的是：
>
> Which one of the followings does not belong to linear structure:（There is only one correct answer）

#### A. 图(graph)

> 以下哪种结构是逻辑结构，而与存储和运算无关：
>
> Which of the following structure is a logical structure regardless of the storage or algorithm:（There is only one correct answer）

#### C.队列(queue)

> 关于算法特性描述正确的有：
>
> Which one is right about algorithm’s characterization:（there are more than one correct answers）

#### B.算法保证计算结果的正确性。Algorithm will ensure the correctness of the calculation results.

#### C.算法的有穷性指算法必须在有限步骤内结束。The finite nature of algorithms means algorithm must be completed within a limited step.

> 下列说法正确的是：
>
> Which options may be correct?（there are more than one correct answers）

#### A.如果函数f(n)是O(g(n))，g(n)是O(h(n))，那么f(n)+g(n)是O(h(n))【if f(n) is O(g(n))，g(n) is O(h(n))，so f(n)+g(n) is O(h(n))】

#### D.如果函数f(n)是O(g(n))，g(n)是O(h(n))，那么f(n)是O(h(n))【  if f(n) is O(g(n))，g(n) is O(h(n))，then  f(n) is O(h(n))】

> 已知一个数组a的长度为n，求问下面这段代码的时间复杂度: 
>
> An array of a, its length is known as n. Please answer the time complexity of the following code.（There are more than one answers.）
>
> for (i=0,length=1;i<n-1;i++){
>
>  for (j = i+1;j<n && a[j-1]<=a[j];j++)
>
>   if(length<j-i+1)
>
>    length=j-i+1;
>
> }

#### A. O(n^2)

#### C. Ω(n)

> 计算运行下列程序段后m的值：
>
> Calculate the value of m after running the following program segment
>
> n = 9; m = 0; 
>
> for (i=1;i<=n;i++)
>
>  for (j = 2*i; j<=n; j++)
>
>   m=m+1;
>
> 求m的值

#### 20

> 由大到小写出以下时间复杂度的序列： 答案直接写标号，如：(1)(2)(3)(4)(5) （提示：系统基于字符匹配来判定答案，所以您的答案中不要出现空格）
>
> Write the following time complexity in descending sequence:Write down the answer labels such as (1)(2)(3)(4)(5). （Hint：This problem is judged by string matching, Please make sure your answer don't contain any blanks. ）

#### (5)(1)(2)(4)(3)

