# Python

## Install

Terminal:

```powershell
winget install Python.Python.3
```

> This command install directly from the official site, with everything working.  
> To check where `winget` downloads the package from, use the `show` command:
> 
> ```powershell
> winget show Python.Python.3
> ```

Site: [Python](https://www.python.org/downloads/)

> :warning: It's not recommended downloading Python from Microsoft Store, because it have incompatibilities as:
> 
> * VSCode's intellisense does not recognize the PyQT6 library.
> 
> Other than that, Python works fine.