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

## Quelques jours avant la bataille

### Nos armes

En préparation du concours, j'avais développé quelques programmes C++ :
- un utilitaire (squelettor) générant des squelettes de programmes python et c++ (parser et classes) à partir d'un fichier décrivant les entrées
- une librairie générique d'algorithme génétique
- des runners et un métarunner, permettant de lancer le code génétique (en variant les entrées et paramètres)

Les entrées étant assez simples, squelettor ne servit à rien.

### Nos rôles

Comme on l'avait prévu (et prévoir fut peut-être notre plus grosse erreur), @MrFlibble et @Matleg partirent sur l'analyse du code et la recherche d'heuristiques pendant que je préparais le code génétique pour remixer leurs solutions obtenues.

## Sur les traces de Darwin

### Le principe de l'algorithme génétique

L'algorithme génétique s'inspire des mécanismes biologiques de l'évolution: 

- On a un individu (la solution), composé de gènes (fragment de solution)
- Cet individu peut connaître des mutations (ajout ou suppression de fragment de solution, modification d'un gene)
<div style="text-align:center">
    <img style="width:300px" src="/assets/img/Mutation.png"/>
</div>
- Pour chaque génération (itération), on a une population (un ensemble de solutions)
- Pour générer la génération de l'itération suivante, on garde les individus présentant le plus de potentiel et on les croise pour générer de nouveaux individus en mixant leurs genes

<div style="text-align:center;">
    <img style="width:300px" src="/assets/img/Croisement.png"/>
</div>

A force d'itérer, de garder les individus avec les meilleurs scores et d'introduire un peu d'aléatoire avec les croisements et mutations, on espère converger vers un optimum.

### La revanche du créationisme

<div style="text-align:center">
    <img  style="width:500px" src="/assets/img/genetic.gif"/>
</div>
Après 2 h 10 de développement, j'ai fini la "base" de mon génétique.

Mais deux problèmes apparaissent:

- Les données sont trop lourdes: 10^5 librairies, 10^5 livres, parfois 10^5 livres pour une librairie ... Ca segfault, ça me force à faire des populations avec de très petites tailles (et donc limite la variété de la population), ça freeze, crash...

- Et quand ça veut bien marcher, ça ne converge pas, du moins pas assez. 

Pour le second problème, cela vient surement de la modélisation:

Comme j'effectue des mutations qui consistent à supprimer/ajouter/modifier des librairies, mais que mes livres sont très liés à la présence et l'ordre des librairies, à chaque fois qu'un gêne librairie est ajouté, je regénère mes gênes de livres associés à cette librairie.

Cela entraîne des discontinuités dans l'évaluation des individus, et l'on se retrouve bloqué sur des optimums locaux pour lesquels les mutations sont rares.

Le lien fort entre les librairies et les livres pose un problème de modélisation que je n'ai pas réussi à résoudre.

## Les heuristiques

Pendant ce temps, les lucides @MrFlibble et @Matleg purent analyser les données d'entrée et développer quelques algorithmes et heuristiques permettant d'obtenir des scores bien meilleurs qu'un simple aléatoire.

### Tri par score de librairie

La première idée était d'attribuer un score à chaque librairie, qui consistait à sommer toutes les valeurs des livres de cette librairie.

Ce score ignorait donc le fait que l'on ne puisse pas ajouter tous les livres de cette librairie mais donnait tout de même une base de départ convenable.

A partir de ce score, la liste des librairies était triée, et c'était cet ordre qui était utilisé pour la solution.

### Affectation des livres aux différentes librairies

Pour affecter les livres aux librairies, on itérait sur chaque librairie et on appliquait ces deux étapes:

- On calcule le nombre de livres que peut scanner cette librairie (en fonction des librairies déjà passées et du temps d'inscription de la librairie)
- On affecte à cette librairie les livres qui n'ont pas encore été affecté et qui ont un score maximal

En combinant ces deux heuristiques, on obtient un score honorable.

### Mentions honorables

Les cas de tests montraient de grandes disparités dans la répartition des valeurs (paramètres des librairies, valeurs des livres etc...). 
L'intuition était donc qu'une heuristique pouvait s'appliquer à un cas en particulier mais pas aux autres. 

Nous avons pu tester de nombreuses heuristiques, notamment dans l'ordonnancement des librairies:

- Modifier la valeur des livres en fonction de leurs fréquences d'apparition dans les librairies
- Trier les librairies par délai d'inscription
- Trier les librairies par nombres de scan par jour
- Trier les librairies avec un ratio des deux paramètres précédents
- Des fonctions utilisant la combinaison de plein de variables, de fonctions logarithmiques ...

Globalement, ces heuristiques n'ont pas fourni de résultats si probants. On obtenait parfois des états initiaux un peu meilleurs pour certains cas, mais restions loin des meilleurs scores.

Je fus également victime d'autres soubresauts "AH MAIS ON PEUT FAIRE DES FLOTS NAN? TSAIS LA, DU MATCHING POUR LE SET COVERING?". Incompris de mes pairs, et doutant également de la pertinence de cette réflexion, cette voie ne fut pas plus explorée. Mais quand même.

### Permutations aléatoires

A partir des solutions générées, l'idée était de modifier aléatoirement ces solutions pour trouver de nouvelles solutions avec de meilleurs scores. 

L'idée était simplement de prendre un petit (10 éléments) intervalle dans la liste de librairie triée, réaliser une permutation aléatoire de cet intervalle, calculer le score et garder cette permutation pour la prochaine itération si le score est meilleur.

Avec ça, nous avons pu atteindre notre score final de 24 000 160 points.

Une faille à cette idée est que, si une permutation est réalisée vers la fin de la liste, comme cette permutation aura un impact nul sur le score, la permutation sera ignorée. Or, il peut y avoir un intérêt de remonter des éléments de fin de la liste avec des permutations successives pour trouver certaines solutions.

Plutôt que de faire:

{% highlight python %}

while True:
    testPermutation2 = triLibrairies.copy()
    i = rand()%(N - 10)

    testPermutation2[i:i+10] = random_shuffle(testPermutation2[i:i+10])

    s = calculScore(testPermutation2)

    if(s > bestScore):
      triLibrairies = testPermutation2

{% endhighlight %}

il aurait été plus intéressant de remplacer la dernière condition par (ce qui a été fait pendant l'extended round):

{% highlight python %}

    if(s >= bestScore):
      triLibrairies = testPermutation2

{% endhighlight %}


Grâce à cet algorithme, je pus fixer ce code qui crachais de minis jackpot continuellement sous fond noir de terminal, déprimé de la défaite du génétique, pendant que @MrFlibble et @Matleg continuaient à se creuser les méninges pour trouver de nouvelles idées.

<div style="text-align:center">
    <img style="width:500px" src="/assets/img/casino.gif"/>
</div>

## Programmation entière

Après le concours, je me suis rappelé de l'article sur le blog h25.io (ty @Mathis et @Clement Hammel) qui parlait d'artillerie lourde. 
Le problème me semblait modélisable, j'ai donc voulu tester.

### Principe

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

### Or-tools

Or-tools est une libraire développée par Google et proposant des algorithmes d'optimisations, des solveurs etc...

C'est l'outil que j'ai utilisé (la version python) pour définir mes problèmes de programmation entière.

### Application au sujet

Je vais d'abord présenter la version que l'on a pu exploiter pour améliorer notre score, avant de présenter une version plus ambitieuse (mais qui ne fonctionne pas).

Pour des contraintes de taille de donnée, le solveur comme il a été développé ne peut s'appliquer qu'à l'entrée E (so many books).

La première version se greffe en sortie du solveur que l'on avait déjà développé, et récupère la sortie générée pour l'optimiser:

- On garde les librairies et l'ordre dans lesquelles celles-ci ont été ajoutées
- On optimise seulement les livres qui sont affectés à telle ou telle librairie

Pour cette version, une seule matrice de variables est définie:
- $ bookIsInLibrairie[][] $ , la variable $ bookIsInLibrairie[b][l] $ étant à $ 0 $ si le livre $ b $ est embarqué par la librairie $ l $

Pour avoir une matrice de dimension réduite, on applique l'optimisation suivante:
- on ne garde que les livres qui sont au moins une fois dans les librairies de la solution

Ensuite, viennent l'expression des contraintes de l'énoncé sous la forme d'inégalités.

Un livre ne doit pas être présent dans plusieurs librairies:

$ \text{Pour chaque livre b:} $

$ 0 <= \sum_{l \in [0,L-1]}{ bookIsInLibrairie[b][l]} <= 1 $

{% highlight python %}
for b in range(B):
    constraint = solver.Constraint(0,1)
    for l in range(L):
        if(b not in libsBooks[l]):
          constraint.SetCoefficient(bookIsInLibrairie[b][l],1)
{% endhighlight %}

Un livre ne doit pas être ajouté dans une librairie qui ne le contient pas:

$ \text{Pour chaque livre b:} $

$ 0 <= \sum_{l \in [0,L-1] \land b \notin livresDeLibrairie[l]}{ booksIsLibrairie[b][l]} <= 1 $

{% highlight python %}
for b in range(B):
    constraint = solver.Constraint(0,0)
    for l in range(L):
        if(books[b][l] not in libsBooks[l]):
            constraint.SetCoefficient(bookIsInLibrairie[b][l],1)
{% endhighlight %}

Si une librairie a terminé son inscription le jour d, alors elle ne peut pas scanner plus de $ (maxDays-d)*shipping $ livres.

$ \text{Pour chaque librairie l:} $

$ 0 <= \sum_{b \in [0,B-1]}{bookIsInLibrairie[b][l]} <= (maxDays-d) * shipping $

{% highlight python %}
d = 0
for l in range(L):
    d += libsSignIn[l]
    constraint = solver.Constraint(0,max(0,(days-signIn)*libsShip[l]))
    for b in range(B):
        constraint.SetCoefficient(bookIsInLibrairie[b][l],1)
{% endhighlight %}


En laissant tourner le solveur quelques minutes, la solution optimale était renvoyée. Il suffisait ensuite à partir des valeurs prises par les différentes variables, de générer la solution dans le format attendu.

L'impact de ce solveur était limité (on ne gagnait en moyenne pas plus de 800 000 points en optimisant une solution non optimisée), mais c'était tout de même un chouette exercice, et une découverte sympa de or-tools.


## The end

Voili voilou, c'est tout pour cet article. 

Pour info, après avoir appliqué tout ça (heuristiques, mutations et solveur), on a pu atteindre les 27 106 605 points. 
A savoir qu'avec cette solution (même si on l'avait magiquement codée à l'avance), le score n'aurait pas été atteint en concours: les mutations crachent de nouveaux scores au bout de très longues périodes de run, et en exploitant des états obtenus lors de précédents runs.

L'objectif n'était donc pas de donner un exemple de bonne solution à coder pour le concours, mais plus des idées ici et là, un exemple d'expérience du concours, et le genre d'erreur à ne pas faire.

Personnellement, je retiens notamment la leçon suivante:
- Rusher et s'acharner sur une solution (génétique ici) sans avoir posé de réflexion sur le papier, c'est mal

Mais on espère pouvoir revenir en force l'année prochaine.

### La suite

Une seconde partie sera peut-être publiée pour expliquer d'autres idées plus avancées:

- Un solveur plus complexe (mais pas fonctionnel)
- La combinaison d'un solveur par mini-batchs avec mutations (idée fraîche pas encore testée, j'ai l'espoir qu'elle nous fasse atteindre les 27 200 000)
- La visualisation de données, pour trouver des patterns, voir si on peut les exploiter

### Vous pouvez reprendre une activité normale

En espérant que ça ait vous ai fait découvrir quelques trucs par ci par là, inspiré des idées ou motivé à nous rejoindre sur le concours de l'an prochain.

Gl&Hf!