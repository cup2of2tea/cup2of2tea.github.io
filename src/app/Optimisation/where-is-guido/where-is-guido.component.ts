import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-where-is-guido',
  templateUrl: './where-is-guido.component.html',
  styleUrls: ['./where-is-guido.component.scss']
})
export class WhereIsGuidoComponent implements OnInit {

  constructor() { }
  equations: any;
  ngOnInit() {
    this.equations = [
      " x >= 0 ",
      " y >= 0 ",
      " z >= 0 ",
      " 1 <= 2x + 3y <=10 ",
      " 2 <= 1x + 4z <=5 ",
      "\\text{Maximize } 2x + 2y + 2z ",
      " bookIsInLibrairie[][] \\text{ , la variable  bookIsInLibrairie[b][l]  étant à  }0\\text{  si le livre }b \\text{ est embarqué par la librairie } ",
      " l ",
      " maxDays ",
      " B ",
      " value ",
      " L ",
      " signIn ",
      " shipping ",
      " \\text{Pour chaque livre b:} ",
      " 0 <= \\sum_{l \\in [0,L-1]}{ bookIsInLibrairie[b][l]} <= 1 ",
      " \\text{Pour chaque livre b: }",
      " 0 <= \\sum_{b \\in [0,B-1]}{bookIsInLibrairie[b][l]} <= (maxDays-d) * shipping[l] ",
      "d",
      " \\text{Pour chaque librairie l:} ",
      " 0 <= \\sum_{b \\in [0,B-1]}{bookIsInLibrairie[b][l]} <= (maxDays-d) * shipping[l] ",
      " \\text{Maximize } \\sum_{b \\in [0,B-1], l \\in [0,L-1]}{bookIsInLibrairie[b][l]*value[b]} "
    ];
  }




}
