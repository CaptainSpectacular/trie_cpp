## What is it?
A basic CLI interface to use a Trie data structure to find a list of completed words. eg, `find pizza` will give the output  `pizza, pizzas, pizzazz, and pizzazzes`. Built in Microsoft Visual Studio 2017, compatible with G++/GCC.

## G++/GCC Setup
#### Clone this repository
```
git clone https://github.com/pollockcl/trie_cpp
cd trie_cpp/CompleteMe_CPP
```

#### Compile main.cpp
```
g++ -c main.cpp
g++ -c dictionary.cpp
g++ -c command.cpp
g++ -c console.cpp
g++ -c tree.cpp
g++ -c node.cpp
g++ *.o -c <someFileName>
```
#### Run the executable
```./<someFileName>```
