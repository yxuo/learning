# Section 3 - HTML 5

## 8 What will be taught

* links

* Table

* Headers

* Forms


* In final project I shall be capable to create a simple site.
  
## 9 - Web page structure, part 1

```html
<!doctype html>
<!-- doctype html is automatically set as html5 -->

<html>
  <!-- Main structure -->
  <head>
    <title>Title in browser</title>
  </head>
  <body>
    Body content
  </body>
</html>
```
    
## 10 - Web page structure, part 2

### Identation

Identation is good practice in HTML, not obrigatory but recommended.

No identation:
```html
<div>
<p>paragraph</p>
</div>
```

Using identation:
```html
<div>
    <p>paragraph</p>
</div>
```

### Meta

Is the file format, normally `utf-8`.

```html
<meta charset="utf-8">
<meta charset="ascii">
```

### Head is optional in html5

```html
<!doctype html>
<!-- doctype html is automatically set as html5 -->

<html>
  <!-- Main structure -->
    <title>Title in browser</title>
    <!-- 'head' content -->
  <body>
    Body content
  </body>
</html>
```