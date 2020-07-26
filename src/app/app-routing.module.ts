import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { WhereIsGuidoComponent } from './Optimisation/where-is-guido/where-is-guido.component';

const routes: Routes = [
  { path: 'articles/WhereIsGuido', component: WhereIsGuidoComponent }
];
@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
