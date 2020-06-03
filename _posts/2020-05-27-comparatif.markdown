---
layout: post
title:  "Programmation compétitive"
date:   2020-05-25 22:00 +0100
categories: jekyll update
---

Un petit article pour donner un aperçu de l'horizon de la programmation compétitive.

Ce classement est purement subjectif, et n'est donc pas à prendre comme une vérité absolue, vous êtes donc conseillés à
faire de vous même une opinion sur ces différents sites.

J'ai partagé cet article en 4 principales catégories:
* Les compétitions algorithmiques
* Les compétitions d'optimisation
* Les compétitions de bot programming
* Les CTF (compétitions de cyber sécurité)

J'ai principalement de l'expérience dans le premier domaine, et suis également fortement intéressé par la deuxième 
et la quatrième catégories. Le comparatif sera donc à prendre avec des pincettes principalement pour les 3 autres catégories (surtout les 2 dernières).
 
Note: Une grande partie des mots / expressions ont une définition associée pour rendre la lecture plus aisée. 
Pour la dévoiler, il suffit de passer le curseur sur un mot / une portion de phrase.

## Description des colonnes:

* Qualité:
    * Originalité (est-ce un problème déjà vu sur d'autres sites)
    * Intérêt (solution élégante, notions réutilisables)
    * La solution attendue est "mathématiquement rigoureuse" (complexité prouvable en accord avec les contraintes, pas d'intuition sans démonstration)
* UI: 
    * Site intuitif 
    * Exempt de bugs 
    * Navigation simple
* Accesible aux débutants:
    * Difficulté des problèmes les plus simples abordable
    * Progression guidée (tutoriels, catégories de difficulté)



<link href="https://fonts.googleapis.com/icon?family=Material+Icons"
      rel="stylesheet">

<style TYPE="text/css">
code.has-jax {font: inherit; font-size: 100%; background: inherit; border: inherit;}
td{
    text-align: center;
    font-size: 16px;
    cursor: pointer;
 }
 
 .details-control{
    cursor: pointer;
 }

td .material-icons {
    font-size: 50px;   
    color: #000000b3;
}

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
<script
  src="https://code.jquery.com/jquery-3.5.1.js"
  integrity="sha256-QWo7LDvxbWT2tbbQ97B53yJnYU3WhH/C8ycbRAkjPDc="
  crossorigin="anonymous"></script>
<link rel="stylesheet" type="text/css"  href="https://cdn.datatables.net/1.10.21/css/jquery.dataTables.min.css" />
<script src="https://cdn.datatables.net/1.10.21/js/jquery.dataTables.min.js" type="text/javascript"></script>

## Compétition algorithmiques:

### Concours

<table id="contestAlgo" class="display" style="width:100%">
        <thead>
            <tr>
                <th >Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Variété</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
                <th>~Durée moyenne</th>
                <th>Divisions</th>
                <th>Hacks</th>
            </tr>
        </thead>
        
        <tfoot>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Variété</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
                <th>~Durée moyenne</th>
                <th>Divisions</th>
                <th>Hacks</th>
            </tr>
        </tfoot>
</table>

### Entrainement

<table id="trainingAlgo" class="display" style="width:100%">
        <thead>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Variété</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </thead>
        
        <tfoot>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Variété</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </tfoot>
</table>

## Optimisation

### Compétitions

<table id="contestsOpti" class="display" style="width:100%">
        <thead>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </thead>
        
        <tfoot>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </tfoot>
</table>

### Entrainement

<table id="trainingOpti" class="display" style="width:100%">
        <thead>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </thead>
        
        <tfoot>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Themes</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </tfoot>
</table>

## Bot Programming

### Contests

<table id="contestsBot" class="display" style="width:100%">
        <thead>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </thead>
        
        <tfoot>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </tfoot>
</table>


## Ctf

### Training

<table id="contestsCtf" class="display" style="width:100%">
        <thead>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </thead>
        
        <tfoot>
            <tr>
                <th>Place</th>
                <th>Url</th>
                <th>Qualité</th>
                <th>UI</th>
                <th>Accessible aux débutants</th>
            </tr>
        </tfoot>
</table>

<script>




var data = {
    "algos": {
        "contests": {
            "Codeforces": {
                "url": "http://codeforces.com/",
                "themes": "Mathématiques, Graphes, Programmation Dynamique, Ad-Hoc",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 3,
                "UI": 5,
                "duration": "2h",
                "premium": "Non",
                "divisions": "4?",
                "hacks": 1,
                "place": 2,
                "misc": "Propose également des concours de langages exotiques, April's fool contest."
            },
            "Topcoder": {
                "url": "https://www.topcoder.com/challenges",
                "themes": "Programmation Dynamique, Combinatoire, Graphes",
                "variety": 3,
                "quality": 3,
                "beginnerFriendly": 0,
                "UI": 0,
                "duration": "1h30",
                "premium": "Non",
                "divisions": "2",
                "hacks": 1,
                "misc": "Le pionnier, mais UI catastrophique"
            },
            "Codechef": {
                "url": "https://www.codechef.com/",
                "themes": "Mathématiques, Structures, Graphes",
                "variety": 4,
                "quality": 4,
                "beginnerFriendly": 3,
                "UI": 4,
                "duration": "3h / 10 jours",
                "premium": "Non",
                "divisions": "2",
                "hacks": 0,
                "misc": "L'un des seuls concours d'algo long de qualité"
            },
            "Google Code Jam": {
                "url": "https://codingcompetitions.withgoogle.com/codejam",
                "themes": "Interactif, Ad-Hoc, Mathématiques",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 4,
                "duration": "2h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "place": 2,
                "misc": "Le plus gros concours international annuel (41000 personnes en 2020)."
            },
            "Google Distributed Code Jam": {
                "url": "https://codingcompetitions.withgoogle.com/past-competitions/distributed",
                "themes": "Algorithmes multithreadés, ?...",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 0,
                "UI": 4,
                "duration": "2h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "L'un des seuls concours d'algo multithread"
            },
            "Google KickStart": {
                "url": "https://codingcompetitions.withgoogle.com/kickstart",
                "themes": "Interactif, Ad-Hoc, Mathématiques",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 3,
                "UI": 4,
                "duration": "3h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "Un concours qui se veut comme une introduction à des concours plus compliqués (style Google Code Jam)."
            },
            "LeetCode": {
                "url": "https://leetcode.com/",
                "themes": "Structures, Implementation",
                "variety": 2,
                "quality": 2,
                "beginnerFriendly": 5,
                "UI": 4,
                "duration": "1h30",
                "premium": "Bibliothèque de problèmes de tests de recrutements (Google, Facebook, Amazon)... Déconseillé",
                "divisions": "Non",
                "hacks": 0,
                "place": -1,
                "misc": "Du recuit"
            },
            "Hackerrank": {
                "url": "https://www.hackerrank.com/",
                "themes": "Programmation Fonctionnelle, IA, Mathématiques, Structures ...",
                "variety": 5,
                "quality": 3,
                "beginnerFriendly": 3,
                "UI": 5,
                "duration": "2h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "Ne semble plus héberger beaucoup de concours intéressants, mais section training très complète"
            },
            "Hackerearth": {
                "url": "https://www.hackerearth.com/",
                "themes": "Structures, Mathématiques, Ad-Hoc",
                "variety": 3,
                "quality": 2,
                "beginnerFriendly": 2,
                "UI": 4,
                "duration": "7 jours",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "place": -1,
                "misc": "Concours très inégaux. Certains sont hideux et rédigés par un stagiaire de passage, d'autres sont ok."
            },
            "Codingame": {
                "url": "http://codingame.com/",
                "themes": "Implementation, Mathématiques, Ad-Hoc, Elagage",
                "variety": 3,
                "quality": 2,
                "beginnerFriendly": 5,
                "UI": 5,
                "duration": "2h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "Concours sympas mais pénalisés par le processus de validation (testcases faibles). Manque de rigueur algorithmique."
            },
            "AtCoder": {
                "url": "https://atcoder.jp/",
                "themes": "Graphes, Mathématiques, Ad-Hoc",
                "variety": 4,
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 4,
                "duration": "2h",
                "premium": "Non",
                "divisions": "2",
                "hacks": 0,
                "misc": "Problèmes originaux et intéressants. "
            },
            "Usaco": {
                "url": "http://www.usaco.org/",
                "themes": "Structures, Mathématiques, Graphes",
                "variety": 3,
                "quality": 4,
                "beginnerFriendly": 2,
                "UI": 3,
                "duration": "4h",
                "premium": "Non",
                "divisions": "4",
                "hacks": 0,
                "misc": "Meuh"
            },
            "IPSC": {
                "url": "https://ipsc.ksp.sk/",
                "themes": "WTF, xD, Outside the box",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 0,
                "UI": 2,
                "duration": "4h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "place": 1,
                "misc": "Problèmes très exotiques et très intéressant. Solutions inhabituelles attendues"
            },
            "Facebook Hacker Cup": {
                "url": "https://www.facebook.com/hackercup/",
                "themes": "Mathématiques, Programmation Dynamique, Ad-Hoc",
                "variety": 4,
                "quality": 4,
                "beginnerFriendly": 2,
                "UI": 3,
                "duration": "4h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "Concurrent de Google Code Jam. Très gros concours annuel."
            },
            "Prologin": {
                "url": "https://prologin.org/",
                "themes": "Dichotomie, Programmation Dynamique, Ad-Hoc, Graphes",
                "variety": 4,
                "quality": 4,
                "beginnerFriendly": 3,
                "UI": 4,
                "duration": "4h",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "Concours national pour les 20 ans ou moins, mais section entraînement ouverte à tous."
            },
            "IOI": {
                "url": "https://ioinformatics.org/",
                "themes": "Flots, Programmation Dynamique, Mathématiques, Graphes",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 0,
                "UI": 3,
                "duration": "?",
                "premium": "Non",
                "divisions": "Non",
                "hacks": 0,
                "misc": "Concours international pour les 'jeunes'. Problèmes accessibles publiquement."
            }
        },
        "training": {
            "France-ioi": {
                "url": "http://www.france-ioi.org/",
                "themes": "Flots, Programmation Dynamique, Mathématiques, Graphes, Géométrie",
                "variety": 5,
                "quality": 5,
                "beginnerFriendly": 5,
                "UI": 4,
                "premium": "Non",
                "place": 1,
                "misc": "Excellent site pour commencer. Permet d'apprendre des langages facilement et de découvrir l'algorithmique."
            },
            "Project Euler": {
                "url": "https://projecteuler.net/",
                "themes": "Mathématiques, Combinatoire, Théorie des nombres",
                "variety": 4,
                "quality": 5,
                "beginnerFriendly": 0,
                "UI": 3,
                "premium": "Non",
                "place": 2,
                "misc": "Problèmes mathématiques à résoudre localement (seule la solution est soumise, pas le code générant la solution)."
            },
            "Spoj": {
                "url": "https://www.spoj.com/",
                "themes": "Graphes, Programmation Dynamique, Ad-Hoc",
                "variety": 3,
                "quality": 3,
                "beginnerFriendly": 2,
                "UI": 2,
                "premium": "Non",
                "place": -1,
                "misc": "Peu intéressant."
            },
            "Online Judge": {
                "url": "https://onlinejudge.org/",
                "themes": "Graphes, Programmation Dynamique, Ad-Hoc, Chaînes de caractères",
                "variety": 3,
                "quality": 3,
                "beginnerFriendly": 2,
                "UI": 1,
                "premium": "Non",
                "place": -1,
                "misc": "Peu intéressant."
            },
            "Kattis": {
                "url": "https://open.kattis.com/",
                "themes": "Graphes, Programmation Dynamique, Ad-Hoc",
                "variety": 4,
                "quality": 4,
                "beginnerFriendly": 2,
                "UI": 3,
                "premium": "Non",
                "misc": "Problèmes ACM-ICPC dans les archives"
            }
        }
    },
    "optimisation": {
        "contests": {
            "Google Hash Code": {
                "url": "https://codingcompetitions.withgoogle.com/hashcode/",
                "themes": "Realistique, Graphes, Ordonancement",
                "quality": 5,
                "beginnerFriendly": 3,
                "UI": 5,
                "place": 1,
                "misc": "Toujours pareil avec Google: le plus gros concours d'optimisation annuel."
            },
            "Azspcs": {
                "url": "http://azspcs.com/",
                "themes": "Mathématique, Graphes",
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 3,
                "place": 3,
                "misc": "Concours assez réguliers. Plutôt mathématiques"
            },
            "Codingame": {
                "url": "http://codingame.com/",
                "themes": "Graphes, Chaînes de caractères, Simulation",
                "quality": 4,
                "beginnerFriendly": 5,
                "UI": 5,
                "misc": "Interface graphique permettant de visualiser en live l'exécution du code."
            },
            "Topcoder": {
                "url": "https://www.topcoder.com/challenges",
                "themes": "Graphes, Géométrie, Simulation",
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 0,
                "place": 2,
                "misc": "Marathon matches: la seule raison pour laquelle affronter cette UI aurait un sens."
            }
        },
        "training": {
            "Primers": {
                "url": "https://primers.xyz/",
                "themes": "Graphes, Géométrie, Simulation",
                "quality": 4,
                "beginnerFriendly": 3,
                "UI": 3,
                "misc": "Peu actif, mais bonne vision globale du domaine de l'optimisation."
            }
        }
    },
    "bot programming": {
        "contests": {
            "Codingame": {
                "url": "http://codingame.com/",
                "quality": 5,
                "beginnerFriendly": 3,
                "UI": 5,
                "place": 1,
                "misc": "La plateforme la plus active en bot programming. Possibilité de jouer après concours également."
            },
            "Halite": {
                "url": "https://halite.io/",
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 2,
                "misc": "Concours sur plusieurs mois. Très large communauté."
            },
            "Battle Code": {
                "url": "https://www.battlecode.org/",
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 3,
                "misc": "Concours organisé par le MIT. Phase finale réservée aux étudiants (pas forcément du MIT)"
            }
        }
    },
    "ctf": {
        "training": {
            "NewbieContest": {
                "url": "https://www.newbiecontest.org/",
                "quality": 3,
                "beginnerFriendly": 3,
                "UI": 3,
                "misc": ""
            },
            "W3Challs": {
                "url": "https://w3challs.com/",
                "quality": 3,
                "beginnerFriendly": 2,
                "UI": 3,
                "misc": ""
            },
            "Root-me": {
                "url": "https://www.root-me.org/fr",
                "quality": 4,
                "beginnerFriendly": 3,
                "UI": 5,
                "misc": ""
            },
            "Hack The Box": {
                "url": "https://www.hackthebox.eu/",
                "quality": 4,
                "beginnerFriendly": 0,
                "UI": 4,
                "misc": ""
            },
            "Over The Wire": {
                "url": "https://overthewire.org/wargames/",
                "quality": 5,
                "beginnerFriendly": 2,
                "UI": 4,
                "misc": ""
            },
            "Pwnable.tw": {
                "url": "https://pwnable.tw/",
                "quality": 5,
                "beginnerFriendly": 0,
                "UI": 4,
                "misc": ""
            },
            "Pwnable.kr": {
                "url": "http://pwnable.kr/",
                "quality": 4,
                "beginnerFriendly": 2,
                "UI": 3,
                "misc": ""
            }
        }
    }
};


for(var i = 0; i < Object.keys(data).length; i++) {
    var k1 = Object.keys(data)[i];
    for(var j = 0; j < Object.keys(data[k1]).length; j++) {
        var k2 = Object.keys(data[k1])[j];
        var tmp = [];
        for(var l = 0; l < Object.keys(data[k1][k2]).length; l++) {
            var k3 = Object.keys(data[k1][k2])[l];
            var o =  [data[k1][k2][k3]];
            o[0]['name'] = k3;
            o[0]['url'] = o[0]['url'] || '';
            o[0]['place'] = o[0]['place'] || 0;
            console.log(o[0]['place']);
            tmp=tmp.concat(o);
        }
        data[k1][k2] = tmp;
    }
}

var colors = ['#f15353','#f15353','#f1b13e','#f1b13e','#34b134','#34b134'];
            
function format ( d ) {
    // `d` is the original data object for the row
    return '<table cellpadding="5" cellspacing="0" border="0" style="padding-left:50px;">'+
        '<tr>'+
            '<td>'+d.misc+'</td>'+
        '</tr>'+
    '</table>';
}


$(document).ready( function () {
    $.fn.dataTable.ext.errMode = 'none';

    var contestAlgo = $('#contestAlgo').DataTable({
    "processing": true,
        data:data['algos']['contests'],

        columns: [
            {
                data: 'place',
                render: function(data,type,row) {
                    if(type == 'display') {
                       
                       if(data == -1) {
                            return '<div><span class="material-icons">clear</span></div>';
                       }
                       else if(data <= 3 && data > 0) {
                            return '<div><span class="material-icons">star</span></div>';
                       }  else {
                            return '<div><span></span></div>';   
                       }
                    }
                },
            },
            {
                data: 'url',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(!row['name']){
                            console.log(row);
                        }
                        return '<a href="'+data+'">'+row['name']+'</a>';
                    }
                },
                orderData: [ 1, 2 ]
            },
            {
                data: 'themes'
            },
            {
                data: 'variety',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                },
                orderData: [ 3, 2 ]
            },
            {
                data: 'quality',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'UI',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'beginnerFriendly',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'duration'
            },
            {
                data: 'divisions',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(row['divisions'] == 'Non'){
                            return '<div> <span class="material-icons">clear</span> </div>';
                        }  else {
                            return '<div> <span class="material-icons">done</span> </div> <div> ' + row['divisions'] + ' </div> ';
                        }
                    }
                }
            },
            {
                data: 'hacks',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(row['hacks'] == 1){
                            return '<span class="material-icons">done</span>';
                        }  else {
                            return '<span class="material-icons">clear</span>';
                        }
                    }
                }
            }
       ]
    });
    $('#contestAlgo').on('click', 'td', function () {
        var tr = $(this).closest('tr');
        var row = contestAlgo.row( tr );
 
        if ( row.child.isShown() ) {
            // This row is already open - close it
            row.child.hide();
            tr.removeClass('shown');
        }
        else {
            // Open this row
            row.child( format(row.data()) ).show();
            tr.addClass('shown');
        }
    } );
    
    var trainingAlgo = $('#trainingAlgo').DataTable({
    "processing": true,
        data:data['algos']['training'],

        columns: [
            {
                data: 'place',
                render: function(data,type,row) {
                    if(type == 'display') {
                       
                       if(data == -1) {
                            return '<div><span class="material-icons">clear</span></div>';
                       }
                       else if(data <= 3 && data > 0) {
                            return '<div><span class="material-icons">star</span></div>';
                       }  else {
                            return '<div><span></span></div>';   
                       }
                    }
                },
            },
            {
                data: 'url',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(!row['name']){
                            console.log(row);
                        }
                        return '<a href="'+data+'">'+row['name']+'</a>';
                    }
                },
                orderData: [ 1, 2 ]
            },
            {
                data: 'themes'
            },
            {
                data: 'variety',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                },
                orderData: [ 3, 2 ]
            },
            {
                data: 'quality',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'UI',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'beginnerFriendly',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            }
       ]
    });
    $('#trainingAlgo').on('click', 'td', function () {
        var tr = $(this).closest('tr');
        var row = trainingAlgo.row( tr );
 
        if ( row.child.isShown() ) {
            // This row is already open - close it
            row.child.hide();
            tr.removeClass('shown');
        }
        else {
            // Open this row
            row.child( format(row.data()) ).show();
            tr.addClass('shown');
        }
    } );
    
    var contestsOpti = $('#contestsOpti').DataTable({
    "processing": true,
        data:data['optimisation']['contests'],

        columns: [
            {
                data: 'place',
                render: function(data,type,row) {
                    if(type == 'display') {
                       
                       if(data == -1) {
                            return '<div><span class="material-icons">clear</span></div>';
                       }
                       else if(data <= 3 && data > 0) {
                            return '<div><span class="material-icons">star</span></div>';
                       }  else {
                            return '<div><span></span></div>';   
                       }
                    }
                },
            },
            {
                data: 'url',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(!row['name']){
                            console.log(row);
                        }
                        return '<a href="'+data+'">'+row['name']+'</a>';
                    }
                },
                orderData: [ 1, 2 ]
            },
            {
                data: 'themes'
            },
            {
                data: 'quality',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'UI',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'beginnerFriendly',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            }
       ]
    });
    $('#contestsOpti').on('click', 'td', function () {
        var tr = $(this).closest('tr');
        var row = contestsOpti.row( tr );
 
        if ( row.child.isShown() ) {
            // This row is already open - close it
            row.child.hide();
            tr.removeClass('shown');
        }
        else {
            // Open this row
            row.child( format(row.data()) ).show();
            tr.addClass('shown');
        }
    } );
    
    var trainingOpti = $('#trainingOpti').DataTable({
    "processing": true,
        data:data['optimisation']['training'],

        columns: [
            {
                data: 'place',
                render: function(data,type,row) {
                    if(type == 'display') {
                       
                       if(data == -1) {
                            return '<div><span class="material-icons">clear</span></div>';
                       }
                       else if(data <= 3 && data > 0) {
                            return '<div><span class="material-icons">star</span></div>';
                       }  else {
                            return '<div><span></span></div>';   
                       }
                    }
                },
            },
            {
                data: 'url',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(!row['name']){
                            console.log(row);
                        }
                        return '<a href="'+data+'">'+row['name']+'</a>';
                    }
                },
                orderData: [ 1, 2 ]
            },
            {
                data: 'themes'
            },
            {
                data: 'quality',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'UI',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'beginnerFriendly',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            }
       ]
    });
    $('#trainingOpti').on('click', 'td', function () {
        var tr = $(this).closest('tr');
        var row = trainingOpti.row( tr );
 
        if ( row.child.isShown() ) {
            // This row is already open - close it
            row.child.hide();
            tr.removeClass('shown');
        }
        else {
            // Open this row
            row.child( format(row.data()) ).show();
            tr.addClass('shown');
        }
    } );
    
    var contestsBot = $('#contestsBot').DataTable({
    "processing": true,
        data:data['bot programming']['contests'],

        columns: [
            {
                data: 'place',
                render: function(data,type,row) {
                    if(type == 'display') {
                       
                       if(data == -1) {
                            return '<div><span class="material-icons">clear</span></div>';
                       }
                       else if(data <= 3 && data > 0) {
                            return '<div><span class="material-icons">star</span></div>';
                       }  else {
                            return '<div><span></span></div>';   
                       }
                    }
                },
            },
            {
                data: 'url',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(!row['name']){
                            console.log(row);
                        }
                        return '<a href="'+data+'">'+row['name']+'</a>';
                    }
                },
                orderData: [ 1, 2 ]
            },
            {
                data: 'quality',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'UI',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'beginnerFriendly',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            }
       ]
    });
    $('#contestsBot').on('click', 'td', function () {
        var tr = $(this).closest('tr');
        var row = contestsBot.row( tr );
 
        if ( row.child.isShown() ) {
            // This row is already open - close it
            row.child.hide();
            tr.removeClass('shown');
        }
        else {
            // Open this row
            row.child( format(row.data()) ).show();
            tr.addClass('shown');
        }
    } );
    
    var contestsCtf = $('#contestsCtf').DataTable({
    "processing": true,
        data:data['ctf']['training'],
        columns: [
            {
                data: 'place',
                render: function(data,type,row) {
                    if(type == 'display') {
                       
                       if(data == -1) {
                            return '<div><span class="material-icons">clear</span></div>';
                       }
                       else if(data <= 3 && data > 0) {
                            return '<div><span class="material-icons">star</span></div>';
                       }  else {
                            return '<div><span></span></div>';   
                       }
                    }
                },
            },
            {
                data: 'url',
                render: function(data,type,row) {
                    if(type == 'display') {
                        if(!row['name']){
                            console.log(row);
                        }
                        return '<a href="'+data+'">'+row['name']+'</a>';
                    }
                },
                orderData: [ 1, 2 ]
            },
            {
                data: 'quality',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'UI',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            },
            {
                data: 'beginnerFriendly',
                "createdCell": function (td, cellData, rowData, row, col) {
                  for(var i = 0; i <= 5; i++) {
                      if(cellData <= i) {
                        $(td).css('background-color',colors[i]);
                        break;
                    }
                  }
                }
            }
       ]
    });
    $('#contestsCtf').on('click', 'td', function () {
        var tr = $(this).closest('tr');
        var row = contestsCtf.row( tr );
 
        if ( row.child.isShown() ) {
            // This row is already open - close it
            row.child.hide();
            tr.removeClass('shown');
        }
        else {
            // Open this row
            row.child( format(row.data()) ).show();
            tr.addClass('shown');
        }
    } );
} );
</script>