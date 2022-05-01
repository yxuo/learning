*Read this in other languages: [English](readme.md), [português](readme.pt.md)*

# Git

## Naming folders and files

So far this moment I haven't found anything about an official naming convention from either Git or GitHub.

Therefore, I'm based on my experience, opinions and recommendations of the community.

### Restrictions

Any system have boundaries, this will be the topic here.

* Some systems are case sensitive `Folder` and `folder` cohexist), some systems aren't.

  If your porject are made for web, Linux, and an Windows user can participate, avoid duplicate names.

### Recommendations

* Prefer to name in lowercase, to avoid confusion.  
  Use uppercase only when it really make sense.
    > Some systems are case sensitive, some aren't.
    >
    > We waste time deciding how to name each file.
    >
    > Mixed upper and lowercase folders are less eye friendly.

* Strongly prefer to use dash instead of space.

  > Webpages, some compilers and systems have problems to deal with folders with spaces.
  >
  > In webpages, spaces are represented as `%20`, which is not friendly at all. Use dash `-` instead.

### Naming folders:

Firstly, be aware that you can name all folders the any way you want, if that is your concern.

> Obviously some system folders like `.git` can't be even renamed.

## Git commands:

### Add file:

```git
git add doc/lang/pt/readme-4.pt
```

#### add all:

```git
git add .
```

#### Add all files based on part of directory:

```git
git add *readme-4.pt
git add *readme*
```

> Be vigilant for which files have been added.

### Commit:

```git
git commit -m "title" -m "second line"
```

# Source

* [How to write a good commit message - freeCodeCamp](https://www.freecodecamp.org/news/a-beginners-guide-to-git-how-to-write-a-good-commit-message/)

* [How often should I/do you make commits? - StackExchange](https://softwareengineering.stackexchange.com/questions/74764/how-often-should-i-do-you-make-commits)

* [How to change a Git commit message - Linuxize](https://linuxize.com/post/change-git-commit-message/)

Naming conventions:

* [Is there a naming convention for git repositories? - StackOverflow](https://stackoverflow.com/questions/11947587/is-there-a-naming-convention-for-git-repositories)

* [Devising a Git repository  naming convention - GravityDepth](https://gravitydept.com/blog/devising-a-git-repository-naming-convention)

  * [Web file and folder naming - CSUDH](https://www.csudh.edu/web-services/web-standards/file-folder-naming/)

* [Is it a good habit to write TODO to commit message? - StackOverflow](https://stackoverflow.com/questions/51260140/is-it-a-good-habit-to-write-todo-to-commit-message)

* [Git add specific lines not interactively - StackOverflow](https://stackoverflow.com/questions/50627024/git-add-specific-lines-not-interactively)