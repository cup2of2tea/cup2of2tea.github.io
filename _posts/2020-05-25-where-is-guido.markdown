---
layout: post
title:  "Where is Guido"
date:   2020-02-25 22:00 +0100
categories: jekyll update
---

Jeudi 20 février s'était déroulé une compétition d'optimisation algorithmique "Google Hash Code".
Insalgo nous a accueilli à son hub, @matleg, @MrFlibble et moi-même (@cup_of_tea).

Cet article a pour but de retracer notre cheminement durant le concours, aussi bien que les impasses et les bonnes pistes.
En deuxième partie, on verra ensemble comment appliquer une méthode de programmation particulière (programmation entière) au problème, et si cela fonctionne.


<style TYPE="text/css">
code.has-jax {font: inherit; font-size: 100%; background: inherit; border: inherit;}
</style>
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
    tex2jax: {
        inlineMath: [['$','$'], ['\\(','\\)']],
        skipTags: ['script', 'noscript', 'style', 'textarea', 'pre'] // removed 'code' entry
    }
});
MathJax.Hub.Queue(function() {
    var all = MathJax.Hub.getAllJax(), i;
    for(i = 0; i < all.length; i += 1) {
        all[i].SourceElement().parentNode.className += ' has-jax';
    }
});
</script>
<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>



# Programmation entière

## Principe

La programmation entière consiste à vérifier la faisabilité ou d'optimiser une fonction à partir d'un set de contraintes.

Les fonctions définissant les contraintes et la fonction à optimiser sont linéaires et dotées de variables restreintes à un domaine entier.

Par exemple, ceci est un problème de progammation entière:

$ x >= 0 $

$ y >= 0 $

$ z >= 0 $

$ 1 <= 2x + 3y <= 10 $

$ 2 <= 1x + 4z <= 5 $

$ \text{Maximize }2x + 2y + 2z $

Les 5 premières lignes sont des lignes de contraintes, la dernière est la fonction d'optimisation.

Ce genre de problème est NP-complet (difficile à calculer), mais il existe des solveurs et algorithmes efficaces pour obtenir rapidement des solutions approchées ou optimales.

## Or-tools

Or-tools (découvert grâce à @MatthisHammel, ty!) est une libraire développée par Google et proposant des algorithmes d'optimisations, des solveurs etc...

C'est l'outil que j'ai utilisé (la version python) pour définir mes problèmes de programmation entière.

## Application au sujet


Je vais d'abord présenter la version que l'on a pu exploiter pour améliorer notre score, avant de présenter une version plus ambitieuse (mais qui ne fonctionne pas).

La première version se greffe en sortie du solveur que l'on avait déjà développé, et récupère la sortie générée pour l'optimiser:

- On garde les librairies et l'ordre dans lesquelles celles-ci ont été ajoutées
- On optimise seulement les livres qui sont affectés à telle ou telle librairie

Pour cette version, une seule matrice de variables est définie:
- book_is_in_librairie[][], la variable books_is_in_librairie[b][l] étant à 0 si le livre b est embarqué par la librairie l

Pour avoir une matrice de dimension réduite, on applique l'optimisation suivante:
- on ne garde que les livres qui sont au moins une fois dans les librairies de la solution

Ensuite, viennent l'expression des contraintes de l'énoncé sous la forme d'inégalités.

Un livre ne doit pas être présent dans plusieurs librairies:

$ \text{Pour chaque livre b:} $

$ 0 <= \sum_{l \in [0,L-1]}{ books\\_is\\_librairie[b][l]} <= 1 $

{% highlight python %}
for b in range(B):
    constraint = solver.Constraint(0,1)
    for l in range(L):
        if(b not in libsBooks[l]):
          constraint.SetCoefficient(books_is_librairie[b][l],1)
{% endhighlight %}

Un livre ne doit pas être ajouté dans une librairie qui ne le contient pas:

$ \text{Pour chaque livre b:} $

$ 0 <= \sum_{l \in [0,L-1] \land b \notin livres\\_de\\_librairie[l]}{ books\\_is\\_librairie[b][l]} <= 1 $

{% highlight python %}
for b in range(B):
    constraint = solver.Constraint(0,0)
    for l in range(L):
        if(books[b][l] not in libsBooks[l]):
            constraint.SetCoefficient(books_is_librairie[b][l],1)
{% endhighlight %}

Si une librairie a terminé son inscription le jour d, alors elle ne peut pas scanner plus de $ (maxDays-d)*shipping $ livres.

$ \text{Pour chaque librairie l:} $

$ 0 <= \sum_{b \in [0,B-1]}{books\\_is\\_in\\ _librairie[b][l]} <= (maxDays-d) * shipping $

{% highlight python %}
d = 0
for l in range(L):
    d += libsSignIn[l]
    constraint = solver.Constraint(0,max(0,(days-signIn)*libsShip[l]))
    for b in range(B):
        constraint.SetCoefficient(books_is_librairie[b][l],1)
{% endhighlight %}

