for letter in "python":
    print("当前字母是：", letter)

fruits = ['banana', 'apple', 'mango']
for fruit in fruits:
    print("当前水果是：", fruit)
print("循环结束")
# 1. 循环输出字符串中的每个字符
# 2. 循环输出列表中的每个元素
# 3. 循环结束

fruits = ['banana', 'apple', 'mango']
for fruit in range(len(fruits)):
    print("当前水果是：", fruit)
print("循环结束")

# pass 是占位语句 
var = "hello world"
var1 = "python runbob"
print("var1[1:5]: ",var1[1:5])
#字符串连接=字符串＋字符串

seq=[1,5,7,9,6,41,4,12,1,21,]
print(list(seq))

#元组中的元素不能修改，元组中的元素值是不允许删除的
tup1 = ('physics', 'chemistry', 1997, 2000)
tup2 = (1, 2, 3, 4, 5 )
tup3 = "a", "b", "c", "d"
print ("tup1[0]: ", tup1[0])
print ("tup2[1:5]: ", tup2[1:5])
#元组中的元素值是不允许删除的，但是可以对元组进行连接组合
tup3 = tup1 + tup2
print (tup3)
#可以del整个元组，但是不能删除元组中的某个元素

#值可以取任何数据类型，但键必须是不可变的，如字符串，数字或元组。
tinydict = {'Alice': '2341', 'Beth': '9102', 'Cecil': '3258'}
tinydict1 = { 'abc': 456 }
#tinydict2 = { 'abc': 123, 98.6: 37 }

#修改字典
tinydict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
 
tinydict['Age'] = 8 # 更新
tinydict['School'] = "RUNOOB" # 添加
 
 
print ("tinydict['Age']: ", tinydict['Age'])
print ("tinydict['School']: ", tinydict['School'])

#创建空字典
emptydict=dict()
print(emptydict)
print("length:",len(emptydict))
print(type(emptydict))

thisset=set(("google","runoob","taobao","Facebook")) 
thisset.update({1,5})
print(thisset)
thisset.update([1,4],[5,6])  #set()函数创建一个无序不重复元素集，可进行关系测试，删除重复数据，还可以计算交集、差集、并集等。
print(thisset)
thisset.remove("Facebook")
print(thisset)
thisset.discard("runoob")
print(thisset)
thisset.pop()
print(thisset)
thisset.clear()
print(thisset)

# subject = input("请输入一个字符：")
# match subject:
#     case "a":
#         print("a")
#     case "b":
#         print("b")
#     case _:#其他情况
#         print("other")
#match语句是Python 3.10中新增的一种控制流结构，用于模式匹配。它可以根据变量的值来选择执行不同的代码块。
# range(1,6)#range()函数用于生成一个整数序列，可以指定起始值、结束值和步长。
# print(range(1,6))

for number in range(1,6):

    print(number)
    #range()函数用于生成一个整数序列，可以指定起始值、结束值和步长。
    #for循环用于遍历一个可迭代对象（如列表、元组、字符串等），对每个元素执行指定的操作。
    #range 包含开头索引 不包含结束索引

list=[1,2,3,4,5]
it=iter(list)
print(next(it))
print(next(it))
#iter()函数用于创建一个迭代器对象，可以用于遍历一个可迭代对象。next()函数用于获取迭代器的下一个元素。
for x in it:
    print(x)

a=[1,2,3]

a="Runoob"
#以上代码中，[1,2,3] 是 List 类型，"Runoob" 是 String 类型，而变量 a 是没有类型，她仅仅是一个对象的引用（一个指针），可以是指向 List 类型对象，也可以是指向 String 类型对象。

def change(a):
    print(id(a))
    a=10
    print(id(a))
a=1
print(id(a))

change(a)    


def printinfo(Name,age):
    print("Name:",Name)
    print("age:",age)
printinfo(age=50,Name="runoob")


sum = lambda arg1, arg2: arg1 + arg2

# 可写函数说明
def printme( str ):
   "打印任何传入的字符串"
   print (str)
   return

# 调用printme函数
printme( str=sum(50,60))


def myfunc(n):
  return lambda a : a * n

doubler = myfunc(2)
print(doubler(11))
tripler = myfunc(3)
print(tripler(11))
#lambda函数可以接受任意数量的参数，但只能有一个表达式。lambda函数用于创建匿名函数，即没有名字的函数。
#lambda函数可以接受任意数量的参数，但只能有一个表达式。lambda函数用于创建匿名函数，即没有名字的函数。

stack=[]
stack.append('a')
stack.append('b')
stack.append('c')
print(stack)
print(stack.pop())
print(stack)
print(stack.pop())
print(stack)
print(stack.pop())
print(stack)

print(len(stack)==0)

class Queue:
    def __init__(self) :
        self.queue=[]
    def enqueue(self,item):
        self.queue.append(item)
    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        else:
            raise IndexError("dequeue from empty queue")
    def peek(self):
        if not self.is_empty():
            return self.queue[0]
        else:
            raise IndexError("peek from empty queue")
    def is_empty(self):
        return len(self.queue)==0
    def size(self):
        return len(self.queue)
queue=Queue()
queue.enqueue('a')
queue.enqueue('b')
queue.enqueue('c')

print(queue.peek())
print(queue.size())
print(queue.dequeue())
print(queue.size())
print(queue.is_empty())
#队列是一种先进先出（FIFO）的数据结构，它支持两种基本操作：入队（enqueue）和出队（dequeue）。入队操作将元素添加到队列的末尾，而出队操作将队列的第一个元素移除并返回。队列通常用于实现任务调度、缓冲区管理等功能。

t=12345,45123,"hello"
u=t,"nihao"
print(u)

print(u)

s='hello python!'
str(s)

h='ptr'
repr(h)#转化为字符串
print(repr(h))
str(1/7)#转化为字符串
print(123)

for x in range(1,10):
    print(repr(x).rjust(2),repr(x*x).rjust(3),end='')
    print(repr(x*x*x).rjust(4))
#rjust 方法将字符串右对齐，并使用指定的字符填充左侧，使其达到指定的宽度。end参数用于指定在每次循环结束后打印的字符，默认为换行符。
print('12'.zfill(5))
#zfill 左边填充数字
print('12'.rjust(5))

print('{}网址是： “{}！”'.format('菜鸟', 'www.runoob.com'))#括号及其里面的字符 (称作格式化字段) 将会被 format() 中的参数替换。

print('{1} 和 {0}'.format('Google', 'Runoob'))
#字符串替换 按照前面大括号里面的顺序

print('{0},{1},{other}'.format('google','baidu',other='taobao'))
#other  关键字参数可用于替换

import math
print('常量PI的值近似为:{!r}'.format(math.pi))

print('常量 PI 的值近似为 {0:.3f}。'.format(math.pi))
#占位符和格式符 用 ： 分开 ：后面是格式符 .3f 表示小数点后三位 前面的‘0’ 表示第一个format参数

table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
for name, number in table.items():
     print('{0:10} ==> {1:10d}'.format(name, number)) 
#格式化字符串的输出

#!/usr/bin/python3

# 打开一个文件
f = open("E:\vscode\test.txt", "w")

f.write( "Python 是一个非常好的语言。\n是的,的确非常好!!\n" )

# 关闭打开的文件
f.close()