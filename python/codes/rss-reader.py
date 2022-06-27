import feedparser
rss = feedparser.parse('https://vascainosdofuturo.webnode.com.br/rss/all.xml')

# print()


# print("Título    >>",rss['feed']['title'])
# print("Descrição >>",rss.feed.subtitle)
for entry in rss.entries:
    print("Notícia >>",entry.title)


