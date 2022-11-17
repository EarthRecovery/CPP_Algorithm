# 综述

### 数学知识

#### 对数

所有对数都是以2为底的

#### 级数

**调和级数**

![image-20221026231333970](Chapter1.assets/image-20221026231333970.png)

#### 模运算

如果A和B同余，记为 a≡b(mod m)

### 递归简论

**递归的四个基本法则**

1. **基准情形**（base cases）不用递归就可以求解
2. **要有进展** （making progress）递归调用必须总能朝着一个基准情形发展

3. **设计法则** 假设所有递归都能跑
4. **合成效益法则** 不在不同递归中做相同的事

### c++  class

#### explicit

在构造函数中，单参数构造函数尽量使用explicit修饰，来避免后台类型转换

```cpp

class A {
    public:
        int a;
        A(){a = 0;}
        explicit A(int a){a = a;}
};

int main(){
    A a = 37; //error here!
}
```

#### 常成员函数

c++ 类由两类函数，访问函数和修改函数

在访问函数形参后加const表明其语义学含义

```cpp
class A {
    public:
        A(){a = 0;}
        explicit A(int a){a = a;}
        int read() const //read 是访问函数
        { return a; }
        void write(int a)
        { this->a = a; }
    private:
        int a;
};
```

#### 接口

一般将类的核心提取出来写成.h

IntCell.h

```cpp
#ifndef INTCELL_H
#define INTCELL_H

class IntCell{
    public:
        explicit IntCell(int initialValue = 0);
        int read() const;
        void write( int x );
    private:
        int storedValue;
};

#endif
```

IntCell.cpp

```cpp
#include "IntCell.h"

IntCell::IntCell( int initialValue ) : storedValue{ initialValue }
{
}

int IntCell::read() const 
{
    return storedValue;
}

void IntCell::write(int a)
{
    storedValue = a;
}
```

### swap 和 move

std::move 将一个左值转换为右值引用

可以避免开销巨大的赋值操作

在swap中的用法

```cpp
void swap( std::vector<std::string> &x, std::vector<std::string> &y){
    std::vector<std::string> temp = std::move(x);
    x = std::move(y);
    y = std::move(temp);
}
```

### 五大函数

#### 析构函数

主要任务是释放资源

#### 拷贝构造函数 & 移动构造函数

```cpp
IntCell B = c //如果C 是左值使用拷贝构造函数，反之使用移动构造函数
IntCell B {C} //如果C 是左值使用拷贝构造函数，反之使用移动构造函数
```

#### 拷贝复制运算符 & 移动赋值运算符 （operator=）

```cpp
lhs = rhs // 如果rhs是左值，调用拷贝复制，反之调用移动赋值
```

#### 默认情况

```
~IntCell();                                 //析构函数
IntCell(const IntCell & rhs );              //拷贝构造函数
IntCell(IntCell && rhs);                    //移动构造函数
IntCell & operator= (const IntCell & rhs);  //拷贝赋值
IntCell & operator= (IntCell && rhs);       //移动赋值
```

#### 自定义

```cpp
class IntCell
{
  public:
    explicit IntCell(int initialValue = 0)
      {
        storedValue = new int{ initialValue};
      }
 
    ~IntCell()                                              //析构函数
      {
        delete storedValue;
      }
 
    IntCell(const IntCell & rhs)                            //拷贝构造函数
      {
        storedValue = new int{*rhs.storedValue};
      }
    IntCell(IntCell && rhs): storedValue{rhs.storedValue}   //移动构造函数
      {
        rhs.storedValue = nullptr;
      }
 
    IntCell & operator = (const IntCell & rhs)              //拷贝赋值
      {
        if(this != &rhs)
           *storedValue = *rhs.storedValue;
        return *this;
      }
    IntCell & operator=(IntCell && rhs)                     //移动赋值
      {
        std::swap(storedValue,rhs.storedValue);
        return *this;
      }
    int read() const
      { 
        return *storedValue;
      }
    void write(int x)
      {
        *storedValue = x;
      }
 
 
  private:
    int *storedValue;
};
```

### 模板

类似于java泛型

```cpp
template <typename Comparable>
const Comparable findMax(const vector<Comparable> & a){
    Comparable maxIndex = 0;

    for(int i=0;i<a.size();i++){
        if(a[i] > maxIndex){
            maxIndex = a[i];
        }
    }

    return maxIndex;
}
```

**类模板**

```cpp
template <class T1,class T2>
class Pair
{
    public:
        T1 key;  //关键字
        T2 value;  //值
        Pair(T1 k,T2 v):key(k),value(v) { };
        bool operator < (const Pair<T1,T2> & p) const;
};
template<class T1,class T2>
bool Pair<T1,T2>::operator < (const Pair<T1,T2> & p) const
//Pair的成员函数 operator <
{ //"小"的意思就是关键字小
    return key < p.key;
}	
```

### 将函数当成形参

```cpp
void ELIST2::add_sorted(int comparator(const void*, const void*),
                        ELIST2_LINK* new_link)
```



#### 

