<!-- 
TODO: traduzir conteúdo do readme inglês
 -->

## Uma analogia sobre árvore Git

O sistema de metrô do Rio de Janeiro parece uma árvore Git, pois trata-se de uma simples linha reta com uma ramificação.  

![linhas de metrô do Rio de Janeiro](https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/Diagrama_metro_rio.png/1280px-Diagrama_metro_rio.png)

Veja como o metrô do Rio em forma de Git:

![mapa de metrô do Rio de Janeiro](img/git-metro-rio-map.svg)

```mermaid
flowchart
subgraph legenda
tag>tag]
branch[branch]
end
subgraph L1[" "]
a(("⠀"))---|"branch Linha-2<br>checkout Linha-2<br>commit"|b(("⠀"))---|commit|c(("⠀"))---|commit|d(("⠀"))---|commit|e(("⠀"))---|commit|f(("⠀"))---|commit<br>merge master|g(("⠀"))---|checkout maste<br>commit|h(("⠀"))---|commit|i(("⠀"))
end
subgraph L2[" "]
g---|branch Linha-2<br>checkout Linha-2<br>commit|2g(("⠀"))---|commit|2h(("⠀"))---|commit|2i(("⠀"))---|commit|2j(("⠀"))---|commit|2k(("⠀"))
end
subgraph L4[" "]
4a(("⠀"))---|commit|4b(("⠀"))---|commit|4c(("⠀"))-->|rebase Linha-4 master|a
end

style L1 fill: transparent, stroke: transparent
style L2 fill: transparent, stroke: transparent
style L4 fill: transparent, stroke: transparent
style a fill: white, stroke: #f26820, stroke-width: 4px
style b fill: white, stroke: #f26820, stroke-width: 4px
style c fill: white, stroke: #f26820, stroke-width: 4px
style d fill: white, stroke: #f26820, stroke-width: 4px
style e fill: white, stroke: #f26820, stroke-width: 4px
style f fill: white, stroke: #f26820, stroke-width: 4px
style g fill: white, stroke: #f26820, stroke-width: 4px
style h fill: white, stroke: #f26820, stroke-width: 4px
style i fill: white, stroke: #f26820, stroke-width: 4px
style 2g fill: white, stroke: darkgreen, stroke-width: 4px
style 2h fill: white, stroke: darkgreen, stroke-width: 4px
style 2i fill: white, stroke: darkgreen, stroke-width: 4px
style 2j fill: white, stroke: darkgreen, stroke-width: 4px
style 2k fill: white, stroke: darkgreen, stroke-width: 4px
style 4a fill: white, stroke: orange, stroke-width: 4px
style 4b fill: white, stroke: orange, stroke-width: 4px
style 4c fill: white, stroke: orange, stroke-width: 4px

linkStyle 6,7 stroke: #f26820, stroke-width:8px;
linkStyle 0,1,2,3,4,5,8,9,10,11,12 stroke:darkgreen,stroke-width:8px;
linkStyle 13,14,15 stroke: orange,stroke-width:8px;

%%C1(first commit) -.-> a
%%C4(first commit) -.-> 4a
B1[Master] -.-> i
B2[Linha-2] -.-> 2k
B4[Linha-4] -.-> 4a
tag1c>VLT-1] -.-> c
tag1d>VLT-2] -.-> d
tag1d1>Barcas-1] -.-> d
tag1g>SuperVia-1] -.-> g
tag2g>SuperVia-2] -.-> 2g
tag2h>BRT-1] -.-> 2h
tag2k>SuperVia-3] -.-> 2k
tag4c>BRT-2] -.-> 4c

%%style tag4c fill:#fef4ac, stroke:#d3d398
style B1 fill: white, stroke: #f26820, stroke-width: 2
style B2 fill: white, stroke: darkgreen, stroke-width: 2
style B4 fill: white, stroke: orange, stroke-width: 2
style branch fill: white, stroke: gray, stroke-width: 2
%%style C1 fill: transparent, stroke: black ,stroke-dasharray: 5 5
```

*Mapa resumido. Algumas estações e a linha 3 (cancelada) foram ocultados para fins didáticos.*
