# 0x04. Sandpiles

## Resources:books:
Read or watch:
[Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg)

---
## Learning Objectives:bulb:
Interview Preparation ― Algorithms

---
### [0. Sandpiles sum](./0-sandpiles.c)
* Write a function that computes the sum of two sandpiles.
  - Prototype: `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`
  - You can assume that both grid1 and grid2 are individually stable
  - A sandpile is considered stable when none of its cells contains more than 3 grains
  - When your function is done, `grid1` must be stable
  - `grid1` must be printed before each toppling round, only if it is unstable (See example)
  - You’re not allowed to allocate memory dynamically

* The code must compile with:
  - `gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles`
  - `gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles`

---
## Author

* [GitHub - Andersen Castañeda](https://github.com/AndersenCastaneda)

* [LinkedIn - AndersenCastañeda](https://www.linkedin.com/in/andersencastaneda/)
