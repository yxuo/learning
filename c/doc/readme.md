# C language

## File handling

Types of file handling modes:

* `r` - read
* `w` - write
* `a`  - append

Combination of handling modes:

| Mode         | Read               | Write              | New file           | Clear file         | Text               | Byte               |
| ------------ | ------------------ | ------------------ | ------------------ | ------------------ | ------------------ | ------------------ |
| `r`          | :heavy_check_mark: |                    |                    |                    | :heavy_check_mark: |                    |
| `w`          |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    |
| `a`          |                    | :heavy_check_mark: | :heavy_check_mark: |                    | :heavy_check_mark: |                    |
| `r+`         | :heavy_check_mark: | :heavy_check_mark: |                    |                    | :heavy_check_mark: |                    |
| `w+`         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    |
| `a+`         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | :heavy_check_mark: |                    |
| `rb`         |                    |                    |                    |                    |                    | :heavy_check_mark: |
| `wb`         |                    |                    |                    |                    |                    | :heavy_check_mark: |
| `ab`         |                    |                    |                    |                    |                    | :heavy_check_mark: |
| `r+b`, `rb+` | :heavy_check_mark: | :heavy_check_mark: |                    |                    |                    | :heavy_check_mark: |

*Table inspired by [Haccks](https://stackoverflow.com/users/2455888/haccks) - StackOverflow.*

* The modes `r`, `w`, `a` are in text mode by default
* These file modes creates a new file only if it doesn't exist.

Source:

 * [How do you allow spaces to be entered using scanf? - StackOverflow](https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf)

 * [What is the difference between "rb+" and "ab" in fopen()? - StackOverflow](https://stackoverflow.com/questions/43978465/what-is-the-difference-between-rb-and-ab-in-fopen)

 * [W. Celes; J. L. Rangel. **Listas encadeadas**. Unicamp.](https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap10.pdf)
    
    * [(Archived version)](https://web.archive.org/web/20220421033620/https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap10.pdf)
    
      > Thanks to @Jeanjulio96 for the recommendation 
    
* [Difference between r+ and w+ in fopen() - StackOverflow](https://stackoverflow.com/questions/21113919/difference-between-r-and-w-in-fopen)

* [Read and write to binary files in C? - StackOverflow](https://stackoverflow.com/questions/17598572/read-and-write-to-binary-files-in-c)