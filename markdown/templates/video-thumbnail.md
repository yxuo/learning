# Video online thumbnails

## YouTube

### 1280x720

```
https://img.youtube.com/vi/UUID/maxresdefault.jpg
```

### 640x480

```
https://img.youtube.com/vi/UUID/sddefault.jpg
```

### 480x360

```
https://img.youtube.com/vi/UUID/hqdefault.jpg
```

### 320x180

```
https://img.youtube.com/vi/UUID/mqdefault.jpg
```

## VidYard

```
https://play.vidyard.com/UUID.jpg 
```

Example:

```
https://play.vidyard.com/Y81dCsiGj4cVuJZecobAP5.jpg 
```

![VIdyard thumbnail](https://play.vidyard.com/Y81dCsiGj4cVuJZecobAP5.jpg )

### Getting the uuid

![uuid element in your browser](img/vidyard-uuid.png)

## Clickable video preview

```markdown
![[Image description](video-image.jpg)](http://video-link.com)
```

Custom sized video:

```html
![[Video description](http://video-image.jpg)][http://video-link]
<a href="http://video-link.com">
    <img src="video-image.jpg" style="width:500px; height:auto;">
</a>
```

<a href="http://www.google.com">
    <img src="https://play.vidyard.com/Y81dCsiGj4cVuJZecobAP5.jpg" style="width:800px;">
</a>

HTML mechanics in CSS:

* The `max-width` is automatically set as 100% thus `width` works as `max-width`. 

* The `height:auto` is not necessary to adjust the proportions.

* Most of readers will not open links for local folders, but they work on GitHub. There is nothing wrong!
## Source

* [How to download your video's thumbnail - VidYard](https://knowledge.vidyard.com/hc/en-us/articles/360009869594-How-to-download-your-video-s-thumbnail)