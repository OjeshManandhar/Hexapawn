# Hexapawn
Small Chess like game made using C with hope of using Machine Learning in it.

Following the idea for this project from this [video](https://www.youtube.com/watch?v=sw7UAZNgGg8).

### Development
I used **Code::Blocks 17.12** as IDE and compiler on Windows 10.

### Requisites
Function from [QBASIC-func-through-C](https://github.com/OjeshManandhar/QBASIC-func-through-C) and
[Basic-Function](https://github.com/OjeshManandhar/Basic-Functions) are used so make sure to install them.

### Installing/Cloning
To clone it on your local machine,
- Clone this repository to your local machine.
```shell
https://github.com/OjeshManandhar/Hexapawn.git
```
- Go inside the directory where you placed the cloned repo
- Make sure you have installed [QBASIC-func-through-C](https://github.com/OjeshManandhar/QBASIC-func-through-C) and
[Basic Function](https://github.com/OjeshManandhar/Basic-Functions)
- Compile and run the project *Hexapawn.cbp*

### To-do
- [X] Darw Board
- [ ] Create Menu
- [ ] Player vs Player Mode
- [ ] Machine Learning

### Machine Learning Idea
- Save all the moves avaliable to the computer in difernent rounds
- Note the number of avaliable moves
- List the Moves
- If a moves leads to the computers' loss
  + Decrease the no. of avaliable moves
  + Remove that move from the list

### File idea to save ML data
- *.csv* file
- Each row represents a **Match Box** from the [video](https://www.youtube.com/watch?v=sw7UAZNgGg8)
- 1<sup>st</sup> col => the round number
- 2<sup>nd</sup> col => the position pieces on the board
- 3<sup>rd</sup> col => number of avaliable moves
- Each avaliable move in a column

### License
This project is licensed under the Apache License 2.0 License - see the [LICENSE](LICENSE) file for details.
